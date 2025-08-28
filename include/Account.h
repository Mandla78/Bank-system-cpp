#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

class Account {
private:
    string accountNumber;
    string name;
    string pin;
    double balance;

public:
    // Constructors
    Account();
    Account(string accNo, string userName, string userPin, double initialBal = 0.0);

    // Getters
    string getAccountNumber() const;
    string getName() const;
    string getPin() const;

    // Operations
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account &recipient, double amount);
    void showBalance();
    void showTransactionHistory() const;

    // File handling
    void recordTransaction(const string &type, double amount, const string &target = " ");
    static void saveAll(map<string, Account> &accounts);
    static void loadAll(map<string, Account> &accounts);

    // Utilities
    static string generateAccountNumber();
    static void registerUser(map<string, Account> &accounts);
    static Account* login(map<string, Account> &accounts);
    void updateAccountNumberInMap(map<string, Account> &accounts, const Account &acc);
};

#endif
