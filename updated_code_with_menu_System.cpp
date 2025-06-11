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

        cin.ignore(); 

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

    int choice;
    int amount;

    do{
        cout<<"<------Banking Menu------>"<<endl;
        cout<<"1. Deposit Money"<<endl;
        cout<<"2. Withdraw Money"<<endl;
        cout<<"3. Show Account Details"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter The Amount: "<<endl;
            cin>>amount;
            myAccount.deposit(amount);

            break;

            case 2:
            cout<<"Enter The Amount: "<<endl;
            cin>>amount;
            myAccount.withdraw(amount);

            break;

            case 3:
            myAccount.showAccount();
            break;

            case 4:
            cout<<"Exited Program, Have A Good Day!!"<<endl;
            break;

            default:
            cout<<"invalid choice. Choose Again"<<endl;
        }

    }while(choice!=4);

    return 0;
}
