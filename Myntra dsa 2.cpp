#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    double price;
    Item(string name, double price) : name(name), price(price) {}
};

class User {
public:
    string name;
    string email;
    vector<Item> cart;
    vector<Item> wishlist;

    User(string name, string email) : name(name), email(email) {}

    void addToCart(Item item) {
        cart.push_back(item);
        cout << item.name << " added to cart." << endl;
    }

    void addToWishlist(Item item) {
        wishlist.push_back(item);
        cout << item.name << " added to wishlist." << endl;
    }

    void viewCart() {
        cout << "Cart:" << endl;
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << "- " << cart[i].name << ": " << cart[i].price << endl;
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

int main() {
    User user("John Doe", "john@example.com");

    Item item1("Shirt", 1500.0);
    Item item2("Jeans", 2000.0);
    Item item3("Shoes", 3000.0);
    Item item4("Watch", 5000.0);

    user.addToCart(item1);
    user.addToCart(item2);
    user.addToWishlist(item3);
    user.addToWishlist(item4);

    user.viewCart();
    user.viewWishlist();

    user.removeFromCart("Jeans");
    user.viewCart();

    user.removeFromWishlist("Watch");
    user.viewWishlist();

    return 0;
}
