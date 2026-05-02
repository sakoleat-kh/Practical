#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
    private:
    string customerName;
    long long accountNumber;
    double balance;
    string accountType;


    public:
    BankAccount(string name, long long accNum, string type, double initialBalance) {
        customerName = name;
        accountNumber = accNum;
        accountType = type;
        // if (initialBalance >= 0) {
        //     balance = initialBalance;
        // } else {
        //     balance = 0;
        //     cout << "Initial balance cannot be negative. Setting to 0. " << endl;
        // }
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "withdrawal successful! Remaining Balance: $" << balance << endl;
        } else{
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }
    void displayAccount() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current balance: $" <<  balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    BankAccount myAccount("Sak Kol", 1234567890LL, "Savings", 500.00);
    myAccount.deposit(150.00);
    myAccount.withdraw(200.00);
    myAccount.displayAccount();
    myAccount.displayAccount();

    return 0;
}