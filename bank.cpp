#include <iostream>
using namespace std;

// Account information
string names[5] = {"Nehimya Mesfin", "Saron Mickyas", "Saron Mulugeta", "Kibreab Gebremedihen", "Meseret Shimeles"};
int accounts[5] = {8614, 7802, 4895, 6788, 3434};
double balances[5] = {27500, 4300, 1340, 26542, 73563};

// Function to display all accounts
void showAccounts() {
    cout << "Available accounts:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Account Number: " << accounts[i] << ", Name: " << names[i] << ", Balance: ETB" << balances[i] << endl;
    }
}

// Function to check balance
void checkBalance() {
    int acc;
    cout << "Enter your account number: ";
    cin >> acc;

    for (int i = 0; i < 5; i++) {
        if (accounts[i] == acc) {
            cout << names[i] << " your Balance is: ETB" << balances[i] << endl;
            return;
        }
    }

    cout << "Account not found.\n";
}

// Function to deposit money
void deposit() {
    int acc;
    double amount;
    cout << "Enter your account number: ";
    cin >> acc;

    for (int i = 0; i < 5; i++) {
        if (accounts[i] == acc) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            if (amount > 0) {
                balances[i] = balances[i] + amount;
                cout << "Deposit successful. New balance: ETB" << balances[i] << endl;
            } else {
                cout << "Please enter a positive amount.\n";
            }
            return;
        }
    }

    cout << "Account not found.\n";
}

// Function to withdraw money
void withdraw() {
    int acc;
    double amount;
    cout << "Enter your account number: ";
    cin >> acc;

    for (int i = 0; i < 5; i++) {
        if (accounts[i] == acc) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > balances[i]) {
                cout << "Not enough balance.\n";
            } else if (amount <= 0) {
                cout << "Invalid amount.\n";
            } else {
                balances[i] = balances[i] - amount;
                cout << "Withdrawal successful. New balance: ETB" << balances[i] << endl;
            }
            return;
        }
    }

    cout << "Account not found.\n";
}

// Function to transfer money between accounts
void transfer() {
    int fromAcc, toAcc;
    double amount;
    bool foundFrom = false;
    bool foundTo = false;

    cout << "Enter your account number: ";
    cin >> fromAcc;
    cout << "Enter recipient's account number: ";
    cin >> toAcc;

    // Loop to find both accounts
    for (int i = 0; i < 5; i++) {
        if (accounts[i] == fromAcc) {
            foundFrom = true;
            for (int j = 0; j < 5; j++) {
                if (accounts[j] == toAcc) {
                    foundTo = true;
                    cout << "Enter amount to transfer: ";
                    cin >> amount;

                    if (amount > 0 && amount <= balances[i]) {
                        balances[i] = balances[i] - amount;
                        balances[j] = balances[j] + amount;
                        cout << "Transfer successful. \nYour current balance is: ETB"<< balances[i];
                    } else {
                        cout << "Invalid or insufficient amount.\n";
                    }
                    return;
                }
            }
        }
    }

    if (!foundFrom || !foundTo) {
        cout << "Account number not found.\n";
    }
}

// Main menu part
int main() {
    int option;

    cout << "Ensera Bank System Project | Developed by Ensera Team :)\n";
    showAccounts();

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> option;

        if (option == 1) {
            checkBalance();
        } else if (option == 2) {
            deposit();
        } else if (option == 3) {
            withdraw();
        } else if (option == 4) {
            transfer();
        } else if (option != 0) {
            cout << "Invalid choice.\n";
        }

    } while (option != 0);

    cout << "Thank you for using Ensera Bank System.\n";
    return 0;
}