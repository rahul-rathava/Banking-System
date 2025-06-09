#include<iostream>
#include<string>

using namespace std;

class Bankaccount
{
private:
    string name;
    int accountnumber;
    double balance;

public:

    void createaccount(){
        cout<<"Enter Your Name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Account Number: ";
        cin>>accountnumber;

        balance=0.0;
        cout<<"Account Created Successfully!!"<<endl;
    }

    void showaccount(){
        
        cout <<"\nAccount Details: "<<endl;
        cout <<"Account Name: "<<name<<endl;
        cout << "Account Number: "<<accountnumber<<endl;
        cout <<"balance (Amount in ruppee): "<<balance<<endl;
    }
    
};

int main(){

    Bankaccount myaccount;
    myaccount.createaccount();
    myaccount.showaccount();

    return 0;
}

