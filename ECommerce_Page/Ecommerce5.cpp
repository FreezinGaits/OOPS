#include <iostream>
#include <string>
#include<climits>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
};

Product products[] = {
    {1, "Laptop", 999.99},
    {2, "Smartphone", 499.99},
    {3, "Headphones", 79.99},
    {4, "Book", 15.99}
};
const int NUM_PRODUCTS = sizeof(products) / sizeof(products[0]);

struct CartNode {
    Product product;
    int quantity;
    CartNode* next;
};

void displayProducts() {
    cout << "\nAvailable Products:\n";
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        cout << "ID: " << products[i].id 
             << " | Name: " << products[i].name 
             << " | Price: $" << products[i].price << endl;
    }
}

Product* findProductById(int id) {
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return nullptr;
}

void addToCart(CartNode*& cart, Product product, int quantity) {
    CartNode* newNode = new CartNode{product, quantity, nullptr};
    if (!cart) {
        cart = newNode;
    } else {
        CartNode* temp = cart;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Added " << quantity << " of " << product.name << " to cart.\n";
}

void viewCart(CartNode* cart) {
    if (!cart) {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "\nYour Cart:\n";
    float total = 0;
    while (cart) {
        cout << "Product: " << cart->product.name 
             << " | Quantity: " << cart->quantity 
             << " | Price: $" << cart->product.price 
             << " | Subtotal: $" << cart->product.price * cart->quantity << endl;
        total += cart->product.price * cart->quantity;
        cart = cart->next;
    }
    cout << "Total: $" << total << endl;
}

void checkout(CartNode*& cart) {
    if (!cart) {
        cout << "Your cart is empty. Nothing to checkout.\n";
        return;
    }

    cout << "\nChecking out...\n";
    viewCart(cart);

    while (cart) {
        CartNode* temp = cart;
        cart = cart->next;
        delete temp;
    }
    cout << "Thank you for your purchase!\n";
}

int main() {
    CartNode* cart = nullptr;
    int choice, productId, quantity;

    while (true) {
        cout << "\n1. Display Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(INT_MAX, '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
    case 1:
        displayProducts();
        break;

    case 2: {
        cout << "Enter Product ID to add to cart: ";
        cin >> productId;
        cout << "Enter quantity: ";
        cin >> quantity;
        
        if (cin.fail() || quantity <= 0) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid Product ID or Quantity.\n";
            break;
        }

        Product* product = findProductById(productId);
        if (product) {
            addToCart(cart, *product, quantity);
        } else {
            cout << "Product not found.\n";
        }
        break;
    }

    case 3:
        viewCart(cart);
        break;

    case 4:
        checkout(cart);
        break;

    case 5:
        cout << "Exiting...\n";
        return 0;

    default:
        cout << "Invalid option. Please try again.\n";
}
    }
    return 0;
}
