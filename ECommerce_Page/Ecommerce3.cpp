#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Item {
	public:
		string name;
		double price;
		int quantity;

		Item(string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

		string toString() {
			return name + "," + to_string(price) + "," + to_string(quantity);
		}

		void fromString(const string& str) {
			size_t pos1 = str.find(",");
			size_t pos2 = str.find(",", pos1 + 1);
			name = str.substr(0, pos1);
			price = stod(str.substr(pos1 + 1, pos2 - pos1 - 1));
			quantity = stoi(str.substr(pos2 + 1));
		}
};

class User {
	public:
		string name;
		string email;
		vector<Item> cart;
		vector<Item> wishlist;

		User(string name, string email) : name(name), email(email) {}

		void addToCart(Item& item, int qty) {
			if (item.quantity >= qty) {
				item.quantity -= qty;
				cart.push_back(Item(item.name, item.price, qty));
				cout << qty << " " << item.name << "(s) added to cart." << endl;
			} else {
				cout << "Insufficient stock for " << item.name << "." << endl;
			}
		}

		void addToWishlist(Item item) {
			wishlist.push_back(item);
			cout << item.name << " added to wishlist." << endl;
		}

		void viewCart() {
			cout << "Cart:" << endl;
			for (size_t i = 0; i < cart.size(); ++i) {
				cout << "- " << cart[i].name << ": " << cart[i].price << " (Quantity: " << cart[i].quantity << ")" << endl;
			}
		}

		void viewWishlist() {
			cout << "Wishlist:" << endl;
			for (size_t i = 0; i < wishlist.size(); ++i) {
				cout << "- " << wishlist[i].name << ": " << wishlist[i].price << endl;
			}
		}

		void removeFromCart(string itemName) {
			for (vector<Item>::iterator it = cart.begin(); it != cart.end(); ++it) {
				if (it->name == itemName) {
					cart.erase(it);
					cout << itemName << " removed from cart." << endl;
					return;
				}
			}
			cout << itemName << " not found in cart." << endl;
		}

		void removeFromWishlist(string itemName) {
			for (vector<Item>::iterator it = wishlist.begin(); it != wishlist.end(); ++it) {
				if (it->name == itemName) {
					wishlist.erase(it);
					cout << itemName << " removed from wishlist." << endl;
					return;
				}
			}
			cout << itemName << " not found in wishlist." << endl;
		}

		void saveCartToFile() {
			ofstream file("cart.txt");
			for (const auto& item : cart) {
				file << item.toString() << endl;
			}
			file.close();
		}

		void loadCartFromFile() {
			ifstream file("cart.txt");
			string line;
			while (getline(file, line)) {
				Item item;
				item.fromString(line);
				cart.push_back(item);
			}
			file.close();
		}

		void saveWishlistToFile() {
			ofstream file("wishlist.txt");
			for (const auto& item : wishlist) {
				file << item.toString() << endl;
			}
			file.close();
		}

		void loadWishlistFromFile() {
			ifstream file("wishlist.txt");
			string line;
			while (getline(file, line)) {
				Item item;
				item.fromString(line);
				wishlist.push_back(item);
			}
			file.close();
		}
};

void displayMenu() {
	cout << "\nMenu Options:\n";
	cout << "1. Add item to cart\n";
	cout << "2. Add item to wishlist\n";
	cout << "3. View cart\n";
	cout << "4. View wishlist\n";
	cout << "5. Remove item from cart\n";
	cout << "6. Remove item from wishlist\n";
	cout << "7. Save cart to file\n";
	cout << "8. Load cart from file\n";
	cout << "9. Save wishlist to file\n";
	cout << "10. Load wishlist from file\n";
	cout << "11. Exit\n";
	cout << "Enter your choice: ";
}

void displayItems(vector<Item>& items) {
	cout << "\nAvailable Items:\n";
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i].name << " - $" << items[i].price << " (Stock: " << items[i].quantity << ")" << endl;
	}
}

bool registerUser(string& name, string& email, string& password) {
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter your email: ";
	getline(cin, email);
	cout << "Enter your password: ";
	getline(cin, password);

	ofstream file("users.txt", ios::app);
	if (file.is_open()) {
		file << name << "," << email << "," << password << "\n";
		file.close();
		return true;
	}
	return false;
}

bool loginUser(string& name, string& email) {
	string emailInput, passwordInput, storedName, storedEmail, storedPassword;

	cout << "Enter your email: ";
	cin.ignore();
	getline(cin, emailInput);
	cout << "Enter your password: ";
	getline(cin, passwordInput);

	ifstream file("users.txt");
	if (file.is_open()) {
		while (file.good()) {
			getline(file, storedName, ',');
			getline(file, storedEmail, ',');
			getline(file, storedPassword, '\n');
			if (storedEmail == emailInput && storedPassword == passwordInput) {
				name = storedName;
				email = storedEmail;
				file.close();
				return true;
			}
		}
		file.close();
	}
	return false;
}

int main() {
	vector<Item> items;
	items.push_back(Item("Shirt", 1500.0, 10));
	items.push_back(Item("Jeans", 2000.0, 5));
	items.push_back(Item("Shoes", 3000.0, 3));
	items.push_back(Item("Watch", 5000.0, 7));

	string name, email, password, itemName;
	int choice, itemIndex, qty;

	cout << "1. Register\n";
	cout << "2. Login\n";
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice == 1) {
		if (registerUser(name, email, password)) {
			cout << "Registration successful!\n";
		} else {
			cout << "Registration failed.\n";
			return 0;
		}
	} else if (choice == 2) {
		if (!loginUser(name, email)) {
			cout << "Login failed.\n";
			return 0;
		} else {
			cout << "Login successful! Welcome, " << name << "\n";
		}
	} else {
		cout << "Invalid choice.\n";
		return 0;
	}

	User user(name, email);

	while (true) {
		displayMenu();
		cin >> choice;

		switch (choice) {
			case 1:
				displayItems(items);
				cout << "Enter the number of the item to add to cart: ";
				cin >> itemIndex;
				cout << "Enter quantity: ";
				cin >> qty;
				if (itemIndex > 0 && itemIndex <= items.size()) {
					user.addToCart(items[itemIndex - 1], qty);
				} else {
					cout << "Invalid item number.\n";
				}
				break;
			case 2:
				displayItems(items);
				cout << "Enter the number of the item to add to wishlist: ";
				cin >> itemIndex;
				if (itemIndex > 0 && itemIndex <= items.size()) {
					user.addToWishlist(items[itemIndex - 1]);
				} else {
					cout << "Invalid item number.\n";
				}
				break;
			case 3:
				user.viewCart();
				break;
			case 4:
				user.viewWishlist();
				break;
			case 5:
				user.viewCart();
				cout << "Enter the name of the item to remove from cart: ";
				cin.ignore();
				getline(cin, itemName);
				user.removeFromCart(itemName);
				break;
			case 6:
				user.viewWishlist();
				cout << "Enter the name of the item to remove from wishlist: ";
				cin.ignore();
				getline(cin, itemName);
				user.removeFromWishlist(itemName);
				break;
			case 7:
				user.saveCartToFile();
				cout << "Cart saved to file.\n";
				break;
			case 8:
				user.loadCartFromFile();
				cout << "Cart loaded from file.\n";
				break;
			case 9:
				user.saveWishlistToFile();
				cout << "Wishlist saved to file.\n";
				break;
			case 10:
				user.loadWishlistFromFile();
				cout << "Wishlist loaded from file.\n";
				break;
			case 11:
				cout << "Exiting...\n";
				return 0;
			default:
				cout << "Invalid choice. Please try again.\n";
				break;
		}
	}
}
