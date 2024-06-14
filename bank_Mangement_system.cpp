#include <iostream>
#include <string>
#include <iomanip> // using set precision function
using namespace std;

//  define structure for bank account
struct Bank
{
    string accountName;
    int accountNumber;
    float balance;
    string accountType;
    float interestRate;
};

// function to display account information
const int maximum = 100; // only 100 account constant
Bank accounts[maximum];  // define array
int accountCount = 0;
int number = 1001;

// define the function to create account
void createAccount()
{
    if (accountCount >= maximum)
    {
        cout << "maximum number of accounts reached" << endl;
        return;
    }
    // sign name
    cout << "Enter account name: ";
    cin >> accounts[accountCount].accountName;
    // sign account number
    accounts[accountCount].accountNumber = number;
    number++;
    // sign account type
    cout << "Enter account type (savings/checking): ";
    cin >> accounts[accountCount].accountType;
    if (accounts[accountCount].accountType == "savings")
    {
        accounts[accountCount].interestRate = 0.03;
    }
    else
    {
        accounts[accountCount].interestRate = 0.0;
    }
    // sign initial balance
    accounts[accountCount].balance = 0.0;

    cout << "Account created successfully! Account Number: " << accounts[accountCount].accountNumber << endl;

    accountCount++;
}
// define the function to display specifically account
void viewAccountDetails(int accountNumber)
{
    for (int i = 0; i < accountCount; ++i)
    {
        // check the account and display this account
        if (accounts[i].accountNumber == accountNumber)
        {
            cout << "AccountName: " << accounts[i].accountName << endl;
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Account Type: " << accounts[i].accountType << endl;
            cout << "Balance: " << fixed << setprecision(2) << accounts[i].balance << endl;
            cout << "Interest Rate: " << accounts[i].interestRate * 100 << "%" << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}
// define the function to deposit amount
void deposit(int accountNumber, float amount)
{
    for (int i = 0; i < accountCount; ++i)
    {
        // check the account and deposit
        if (accounts[i].accountNumber == accountNumber)
        {
            accounts[i].balance += amount;
            cout << "deposit successful new balance: " << fixed << setprecision(2) << accounts[i].balance << endl;
        }
    }
    cout << "Account not found!" << endl;
}
// define the function to withdraw the amount
void withdraw(int accountNumber, float amount)
{
    for (int i = 0; i < accountCount; ++i)
    {
        // check the account
        if (accounts[i].accountNumber == accountNumber)
        {
            // check the amount
            if (accounts[i].balance >= amount)
            {
                accounts[i].balance -= amount;
                cout << "withdrawal successful and new balance: " << fixed << setprecision(2) << accounts[i].balance << endl;
            }
            else
            {
                cout << "insufficient balance!" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}
// define the function to withdraw the transfer
void transfer(int fromAccountNumber, int toAccountNumber, float amount)
{
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < accountCount; ++i)
    {
        // check the both account
        if (accounts[i].accountNumber == fromAccountNumber)
            fromIndex = i;
        if (accounts[i].accountNumber == toAccountNumber)
            toIndex = i;
    }
    // when index is change then if run
    if ((fromIndex != -1) && (toIndex != -1))
    {
        // check the amount
        if (accounts[fromIndex].balance >= amount)
        {
            accounts[fromIndex].balance -= amount;
            accounts[toIndex].balance += amount;
            cout << "Transfer successful!" << endl;
        }
        else
        {
            cout << "Insufficient balance in source account!" << endl;
        }
    }
    else
    {
        cout << "accounts not found!" << endl;
    }
}
// define the function to view to all account
void viewAllAccounts()
{
    if (accountCount == 0)
    {
        cout << "No accounts found!" << endl;
        return;
    }
    // loop for display the all account
    for (int i = 0; i < accountCount; ++i)
    {
        cout << "Account Name: " << accounts[i].accountName << endl;
        cout << "Account Number: " << accounts[i].accountNumber << endl;
        cout << "Account Type: " << accounts[i].accountType << endl;
        cout << "Balance: " << fixed << setprecision(2) << accounts[i].balance << endl;
        cout << "Interest Rate: " << accounts[i].interestRate * 100 << "%" << endl;
        cout << "---------------------------------------" << endl;
    }
}
// define the function to calculate interest
void calculateInterest()
{
    for (int i = 0; i < accountCount; ++i)
    {
        //  check the account and when savings account then run if
        if (accounts[i].accountType == "savings")
        {
            accounts[i].balance += accounts[i].balance * accounts[i].interestRate;
        }
    }
    cout << "Calculates and adds interest to Savings accounts." << endl;
}
// define the function to close the account
void closeAccount(int accountNumber)
{
    int index = -1;
    // check the account
    for (int i = 0; i < accountCount; ++i)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            index = i;
        }
    }
    // when index is change then run if
    if (index != -1)
    {
        for (int i = index; i < accountCount - 1; ++i)
        {
            accounts[i] = accounts[i + 1];
        }
        accountCount--;
        cout << "Account closed successfully!" << endl;
        return;
    }
    else
    {
        cout << "Account not found!" << endl;
    }
}

int main()
{
    char choice;
    while (true)
    {
        cout << "-------------------";
        cout << "\nBanking System Menu\n";
        cout << "-------------------" << endl;

        cout << "1. Create a new account\n";
        cout << "2. View account details\n";
        cout << "3. Deposit money\n";
        cout << "4. Withdraw money\n";
        cout << "5. Transfer money between accounts\n";
        cout << "6. View all accounts\n";
        cout << "7. Calculate interest for Savings accounts\n";
        cout << "8. Close an account\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int accountNumber, toAccountNumber;
        float amount;

        switch (choice)
        {
        case '1':
            createAccount();
            break;
        case '2':
            cout << "Enter account number: ";
            cin >> accountNumber;
            viewAccountDetails(accountNumber);
            break;
        case '3':
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit(accountNumber, amount);
            break;
        case '4':
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(accountNumber, amount);
            break;
        case '5':
            cout << "Enter from account number: ";
            cin >> accountNumber;
            cout << "Enter to account number: ";
            cin >> toAccountNumber;
            cout << "Enter amount to transfer: ";
            cin >> amount;
            transfer(accountNumber, toAccountNumber, amount);
            break;
        case '6':
            viewAllAccounts();
            break;
        case '7':
            calculateInterest();
            break;
        case '8':
            cout << "Enter account number: ";
            cin >> accountNumber;
            closeAccount(accountNumber);
            break;
        case '9':
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
