#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    void createAccount() {
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your account number: ";
        cin >> accountNumber;

        balance = 0.0;

        cin.ignore(); // clear buffer

        cout << "Account created successfully!" << endl;
    }

    void showAccount() const {
        cout << "\nAccount Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
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
};

int main() {
    BankAccount myAccount;
    myAccount.createAccount();

    myAccount.deposit(1000);
    myAccount.withdraw(500);
    myAccount.withdraw(600);

    myAccount.showAccount();

    return 0;
}
