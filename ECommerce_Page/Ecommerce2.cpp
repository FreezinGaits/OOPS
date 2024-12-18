#include<iostream>
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
};

void displayMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Add item to cart\n";
    cout << "2. Add item to wishlist\n";
    cout << "3. View cart\n";
    cout << "4. View wishlist\n";
    cout << "5. Remove item from cart\n";
    cout << "6. Remove item from wishlist\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\nAdmin Menu Options:\n";
    cout << "1. Update item quantity\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
}

void displayItems(vector<Item>& items) {
    cout << "\nAvailable Items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].name << " - $" << items[i].price << " (Stock: " << items[i].quantity << ")" << endl;
    }
}

void loadItems(vector<Item>& items) {
    ifstream file("items.txt");
    if (file.is_open()) {
        string name;
        double price;
        int quantity;
        while (file >> name >> price >> quantity) {
            items.push_back(Item(name, price, quantity));
        }
        file.close();
    }
}

void saveItems(const vector<Item>& items) {
    ofstream file("items.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < items.size(); ++i) {
            file << items[i].name << " " << items[i].price << " " << items[i].quantity << endl;
        }
        file.close();
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

bool loginUser(string& name, string& email, bool& isAdmin) {
    string emailInput, passwordInput, storedName, storedEmail, storedPassword;
    string adminEmail = "admin@admin.com"; // Administrator email (replace with your own)
    string adminPassword = "admin"; // Administrator password (replace with your own)

    cout << "Enter your email: ";
    cin.ignore();
    getline(cin, emailInput);
    cout << "Enter your password: ";
    getline(cin, passwordInput);

    if (emailInput == adminEmail && passwordInput == adminPassword) {
        name = "Admin";
        email = adminEmail;
        isAdmin = true;
        return true;
    }

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file.good()) {
            getline(file, storedName, ',');
            getline(file, storedEmail, ',');
            getline(file, storedPassword, '\n');
            if (storedEmail == emailInput && storedPassword == passwordInput) {
                name = storedName;
                email = storedEmail;
                isAdmin = false;
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
    loadItems(items);

    string name, email, password, itemName;
    int choice, itemIndex, qty;
    bool isAdmin = false;

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
        if (!loginUser(name, email, isAdmin)) {
            cout << "Login failed.\n";
            return 0;
        } else {
            if (isAdmin) {
                cout << "Admin login successful! Welcome, Admin.\n";
            } else {
                cout << "Login successful! Welcome, " << name << "\n";
            }
        }
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    User user(name, email);

    if (isAdmin) {
        while (true) {
            displayAdminMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    displayItems(items);
                    cout << "Enter the number of the item to update quantity: ";
                    cin >> itemIndex;
                    cout << "Enter new quantity: ";
                    cin >> qty;
                    if (itemIndex > 0 && itemIndex <= items.size()) {
                        items[itemIndex - 1].quantity = qty;
                        cout << "Item quantity updated.\n";
                        saveItems(items);
                    } else {
                        cout << "Invalid item number.\n";
                    }
                    break;
                case 2:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    } else {
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
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }

    return 0;
}

