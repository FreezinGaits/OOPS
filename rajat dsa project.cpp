#include <iostream>
#include <fstream>  
#include <iomanip> 
#include <string>
#include <sstream> 
#include <ctime>     
using namespace std;

struct Transaction {
    string receiverName;
    int amount;
    string date;
    Transaction* link;
};

struct Node {
    int balance;
    Transaction* transactionHistory;
};

Node* start = NULL;
Node* ptr = NULL;

// Function to get the current date in dd-mm-yyyy format
string getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    ostringstream dateStream;
    dateStream << setfill('0') << setw(2) << localTime->tm_mday << "-"
               << setfill('0') << setw(2) << (localTime->tm_mon + 1) << "-"
               << (localTime->tm_year + 1900);

    return dateStream.str();
}

void initializeAccount(int initialBalance) {
    start = new Node;
    start->balance = initialBalance;
    start->transactionHistory = NULL;
    ptr = start;

    // Create a file for storing transactions if it doesn't exist
    ofstream file("transactions.txt", ios::app);
    if (!file) {
        cout << "Error opening transaction file!" << endl;
    }
    file.close();
}

void addTransaction(string receiverName, int amount) {
    string date = getCurrentDate();  // Automatically get current date

    Transaction* newTransaction = new Transaction;
    newTransaction->receiverName = receiverName;
    newTransaction->amount = amount;
    newTransaction->date = date;
    newTransaction->link = ptr->transactionHistory;
    ptr->transactionHistory = newTransaction;

    // Save transaction to file
    ofstream file("transactions.txt", ios::app);
    if (file) {
        file << "Receiver: " << receiverName << endl;
        file << "Amount: " << amount << endl;
        file << "Date: " << date << endl;
        file << "-------------------------------------\n";
    } else {
        cout << "Error writing to transaction file!" << endl;
    }
    file.close();
}

void displayTransactionHistory() {
    system("cls");

    cout << "\n\n\n         Transaction History\n";
    cout << "-------------------------------------\n";

    ifstream file("transactions.txt");
    if (file) {
        string line;
        bool isEmpty = true;
        while (getline(file, line)) {
            isEmpty = false;
            cout << line << endl;
        }

        if (isEmpty) {
            cout << "No transaction history available.\n";
        }
    } else {
        cout << "Error reading transaction file!\n";
    }
    file.close();
}

void checkBalance() {
    system("cls");
    cout << "\nYour current balance is: " << ptr->balance << "\n\n";
}

void moneyTransfer(string receiverName, int amount) {
    if (ptr->balance >= amount) {
        ptr->balance -= amount;
        addTransaction(receiverName, amount);
        cout << "\n\nTransferred " << amount << " to " << receiverName << " successfully.\n\n";
    } else {
        cout << "\n\nInsufficient balance!\n\n";
    }
}

void payBill(int billType, int amount) {
    string billTypes[] = {"Water Bill", "Electricity Bill", "Mobile Recharge", "WiFi Bill", "Gas Booking Bill"};

    if (billType >= 1 && billType <= 5) {
        if (ptr->balance >= amount) {
            ptr->balance -= amount;
            addTransaction(billTypes[billType - 1], amount);
            cout << "\n\n" << billTypes[billType - 1] << " of " << amount << " paid successfully.\n\n";
        } else {
            cout << "\n\nInsufficient balance for bill payment.\n\n";
        }
    } else {
        cout << "\n\nInvalid bill type selected.\n\n";
    }
}

void menu() {
    int choice;
    while (true) {
        system("cls");
        cout << "----------------------------------\n";
        cout << "       Welcome to Paytm\n";
        cout << "----------------------------------\n\n";
        cout << "1. Check Balance\n";
        cout << "2. Money Transfer\n";
        cout << "3. Pay Bills\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;

            case 2: {
                string receiverName;
                int amount;
                cout << "\nEnter receiver's name: ";
                cin >> receiverName;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                moneyTransfer(receiverName, amount);
                break;
            }

            case 3: {
                int billType, amount;
                cout << "\n         Select bill type:\n";
                cout << "         +---------------------------+\n";
                cout << "         |  1. Water Bill            |\n";
                cout << "         |  2. Electricity Bill      |\n";
                cout << "         |  3. Mobile Recharge       |\n";
                cout << "         |  4. WiFi Bill             |\n";
                cout << "         |  5. Gas Booking Bill      |\n";
                cout << "         +---------------------------+\n\n";
                cout << "Enter your choice: ";
                cin >> billType;
                cout << "Enter amount: ";
                cin >> amount;
                payBill(billType, amount);
                break;
            }

            case 4:
                displayTransactionHistory();
                break;

            case 5:
                cout << "\n\nExiting... Thank you for using Paytm!\n\n";
                return;

            default:
                cout << "\n\nInvalid choice! Please try again.\n\n";
        }

        cout << "\nPress any key to continue...";
        cin.ignore();
        cin.get();
    }
}

int main() {
    int initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    initializeAccount(initialBalance);
    menu();
    return 0;
}

