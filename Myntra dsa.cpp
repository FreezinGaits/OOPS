#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

class Cart {
public:
    vector<Product> items;

    void addToCart(Product p) {
        items.push_back(p);
    }

    void showCart() {
        cout << "Items in your cart:" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i].name << " - $" << items[i].price << " x " << items[i].quantity << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (size_t i = 0; i < items.size(); ++i) {
            total += items[i].price * items[i].quantity;
        }
        return total;
    }
};

void showProducts(const vector<Product>& products) {
    cout << "Available Products:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << " (" << products[i].quantity << " in stock)" << endl;
    }
}

int main() {
    vector<Product> products;
    products.push_back(Product("T-Shirt", 19.99, 10));
    products.push_back(Product("Jeans", 49.99, 5));
    products.push_back(Product("Sneakers", 89.99, 3));

    Cart cart;
    int choice, quantity;

    while (true) {
        showProducts(products);
        cout << "Enter the number of the product to add to your cart (0 to checkout): ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Enter quantity: ";
        cin >> quantity;

        if (choice > 0 && choice <= products.size() && quantity <= products[choice - 1].quantity) {
            cart.addToCart(Product(products[choice - 1].name, products[choice - 1].price, quantity));
            products[choice - 1].quantity -= quantity;
        } else {
            cout << "Invalid choice or quantity." << endl;
        }
    }

    cart.showCart();
    cout << "Total: $" << cart.calculateTotal() << endl;

    return 0;
}

