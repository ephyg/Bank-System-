// include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Create Account
void createAccount(string name, string password)
{
    ofstream create;
    create.open("accounts.txt", ios::out | ios::app);
    create << name << endl;
    create << password << endl;
    create.close();
}

// Login User
bool login(string name, string password)
{
    ifstream log;
    log.open("accounts.txt");
    string n, p;
    if (log.is_open())
    {
        while (log >> n)
        {
            log >> p;
            if (name == n && password == p)
            {
                return true;
            }
        }
    }
    log.close();
    return false;
}

// Deposit Money

void deposit(double &balance, double val)
{
    cout << "Beginnin balance: $ " << balance << endl;
    balance += val;
    cout << "Deposit amount : $ " << val << endl;
    cout << "Your balance is : $ " << balance << endl;
}

// Withdraw Money

bool withdraw(double &balance, double val)
{
    if (balance >= val)
    {
        balance = balance + val;

        return true;
    }
    else
    {
        return false;
    }
}

// Display Your Balance
void displayBalance(double balance, double val)
{
    double temp1 = balance;
    if (val < 0)
    {
        balance = temp1 - val;
        cout << "Beginning balance: $" << balance << endl;
        cout << "Withdraw amount: $" << val << endl;
        cout << "Your balance is : $" << temp1 << endl;
    }
    else
    {

        balance -= val;
        cout << " Beginning balance: $" << balance << endl;
        cout << "Deposit amount : $" << val << endl;
        cout << "Your balance is : $" << temp1 << "." << endl;
    }
}

// Choose Your Preference
void bankingMenu()
{
    double balance = 0, amount;
    while (true)
    {
        cout << "Please select an option: " << endl;
        cout << "d -> Deposit Money " << endl;
        cout << "w -> Withdraw Money" << endl;
        cout << "r -> Request Balance" << endl;
        cout << "q -> Quit" << endl;
        cout << ">";
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'd':
        case 'D':
            cout << "Enter amount of deposit: $";
            cin >> amount;
            deposit(balance, amount);
            // cout << "$" << amount << " was deposited." << endl;
            break;
        case 'w':
        case 'W':
            cout << "Enter amount of withdrawal: $";
            cin >> amount;
            if (amount > balance)
            {
                cout << "Sorry withdrawal amount exceeds the balance." << endl;
            }
            else
            {
                amount = -amount;
                withdraw(balance, amount);
            }
            break;
        case 'r':
        case 'R':
            displayBalance(balance, amount);
            break;
        case 'q':
        case 'Q':
            return;
        default:
            cout << "Wrong option" << endl;
            break;
        }
        cout << endl;
    }
}

// User verify login
void mainMenu()
{
    string name, password; // User login
    while (true)
    {
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << ">";
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'l':
        case 'L':
            cout << "Please enter your user id: ";
            cin >> name;
            cout << "Please enter your password: ";
            cin >> password;
            if (login(name, password))
            {
                cout << "Access Granted - " << name << endl;
                bankingMenu();
                return;
            }
            else
            {
                cout << "******** LOGIN FAILED! ********" << endl;
            }
            break;
        case 'c':
        case 'C':
            cout << "Please enter your user name: ";
            cin >> name;
            cout << "Please enter your password: ";
            cin >> password;
            createAccount(name, password);
            cout << "Thank You! Your account has been created!" << endl;
            break;
        case 'q':
        case 'Q':
            cout << "Thanks for banking with COP2513.F16 " << name << endl;
            break;
        default:
            cout << "Wrong option" << endl;
        }
        cout << endl;
    }
}

int main()
{
    cout << "Welcome to CBE Bank"<<endl;
    mainMenu();
    return 0;
}
