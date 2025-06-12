#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string n, int accNum) : name(n), accountNumber(accNum), balance(0.0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
            cout << "New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
                cout << "Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
        } else {
            cout << "Invalid withdraw amount!" << endl;
        }
    }

    void showAccount() const {
        cout << "\nAccount Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Function to find account index by account number
int findAccount(const vector<BankAccount>& accounts, int accNum) {
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1; // not found
}

int main() {
    vector<BankAccount> accounts;

    int choice;

    do {
        cout << "\n----- Main Menu -----" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Access Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 1) {
            string name;
            int accNum;

            cout << "Enter your name: ";
            getline(cin, name);

            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore();

            // Check if account number already exists
            if (findAccount(accounts, accNum) != -1) {
                cout << "Account number already exists! Try again." << endl;
            } else {
                accounts.push_back(BankAccount(name, accNum));
                cout << "Account created successfully!" << endl;
            }

        } else if (choice == 2) {
            if (accounts.empty()) {
                cout << "No accounts available. Create an account first." << endl;
                continue;
            }

            int accNum;
            cout << "Enter your account number: ";
            cin >> accNum;
            cin.ignore();

            int index = findAccount(accounts, accNum);
            if (index == -1) {
                cout << "Account not found!" << endl;
                continue;
            }

            int accChoice;
            double amount;
            do {
                cout << "\n--- Account Menu ---" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Show Account Details" << endl;
                cout << "4. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> accChoice;
                cin.ignore();

                switch (accChoice) {
                    case 1:
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        cin.ignore();
                        accounts[index].deposit(amount);
                        break;
                    case 2:
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        cin.ignore();
                        accounts[index].withdraw(amount);
                        break;
                    case 3:
                        accounts[index].showAccount();
                        break;
                    case 4:
                        cout << "Logging out from account." << endl;
                        break;
                    default:
                        cout << "Invalid choice! Try again." << endl;
                }
            } while (accChoice != 4);

        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
