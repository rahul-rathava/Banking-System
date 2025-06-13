#include<iostream>
#include <string>
#include <vector>
#include <fstream> // For file I/O

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;
    string password;

public:
    BankAccount(string n, int accNum, string pass) : name(n), accountNumber(accNum), password(pass), balance(0.0) {}

    int getAccountNumber() const { return accountNumber; }
    string getName() const { return name; }
    double getBalance() const { return balance; }
    string getPassword() const { return password; }

    void setBalance(double b) { balance = b; }

    bool checkPassword(string pass) const { return password == pass; }

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

int findAccount(const vector<BankAccount>& accounts, int accNum) {
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

void saveAllAccounts(const vector<BankAccount>& accounts) {
    ofstream file("accounts.txt");
    for (const auto& acc : accounts) {
        file << acc.getAccountNumber() << ","
             << acc.getName() << ","
             << acc.getBalance() << ","
             << acc.getPassword() << endl;
    }
    file.close();
}

void loadAccountsFromFile(vector<BankAccount>& accounts) {
    ifstream file("accounts.txt");
    if (!file) return;

    int accNum;
    string name, pass;
    double balance;
    char comma;

    while (file >> accNum >> comma) {
        getline(file, name, ',');
        file >> balance >> comma;
        getline(file, pass);

        BankAccount acc(name, accNum, pass);
        acc.setBalance(balance);
        accounts.push_back(acc);
    }
    file.close();
}

int main() {
    vector<BankAccount> accounts;
    loadAccountsFromFile(accounts);

    int choice;
    do {
        cout << "\n----- Main Menu -----" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Access Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int accNum;
            string pass;

            cout << "Enter your name: ";
            getline(cin, name);

            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore();

            cout << "Enter the password: ";
            getline(cin, pass);

            if (findAccount(accounts, accNum) != -1) {
                cout << "Account number already exists! Try again." << endl;
            } else {
                accounts.push_back(BankAccount(name, accNum, pass));
                cout << "Account created successfully!" << endl;
                saveAllAccounts(accounts);
            }

        } else if (choice == 2) {
            if (accounts.empty()) {
                cout << "No accounts available. Create an account first." << endl;
                continue;
            }

            int accNum;
            string pass;
            cout << "Enter your account number: ";
            cin >> accNum;
            cin.ignore();

            int index = findAccount(accounts, accNum);
            if (index == -1) {
                cout << "Account not found!" << endl;
                continue;
            }

            cout << "Enter the password: ";
            getline(cin, pass);

            if (!accounts[index].checkPassword(pass)) {
                cout << "Incorrect Password!!" << endl;
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
                        saveAllAccounts(accounts);
                        break;
                    case 2:
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        cin.ignore();
                        accounts[index].withdraw(amount);
                        saveAllAccounts(accounts);
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
