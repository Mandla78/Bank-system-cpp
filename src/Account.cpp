#include "Account.h"

// Constructors
Account::Account() {}

Account::Account(string accNo, string userName, string userPin, double initialBal) {
    accountNumber = accNo;
    name = userName;
    pin = userPin;
    balance = initialBal;
}

// Getters
string Account::getAccountNumber() const { return accountNumber; }
string Account::getName() const { return name; }
string Account::getPin() const { return pin; }

// Deposit
void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposit successful. New Balance: R" << balance << endl;
    recordTransaction("Deposit", amount);
}

// Withdraw
bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrawal successful. New Balance: R" << balance << endl;
        recordTransaction("Withdrawal", amount);
        return true;
    } else {
        cout << "Insufficient funds" << endl;
        return false;
    }
}

// Transfer
bool Account::transfer(Account &recipient, double amount) {
    if (withdraw(amount)) {
        recipient.deposit(amount);
        recordTransaction("Transfer", amount, recipient.accountNumber);
        return true;
    }
    return false;
}

// Show balance
void Account::showBalance() {
    cout << "Account balance for: " << accountNumber << ": R" << balance << endl;
}

// Record transaction
void Account::recordTransaction(const string &type, double amount, const string &target) {
    string fileName = accountNumber + "_history.txt";
    ofstream fout(fileName, ios::app);
    if (fout.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // remove newline

        fout << "[" << dt << "] ";
        fout << type << " R" << amount;
        if (!target.empty()) fout << " -> " << target;
        fout << endl;
        fout.close();
    }
}

// Show history
void Account::showTransactionHistory() const {
    string fileName = accountNumber + "_history.txt";
    ifstream fin(fileName);
    if (fin.is_open()) {
        string line;
        cout << "Transaction history for " << accountNumber << ":\n";
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    } else {
        cout << "No transaction history found.\n";
    }
}

// Save accounts
void Account::saveAll(map<string, Account> &accounts) {
    ofstream fout("accounts.txt");
    for (auto &pair : accounts) {
        fout << pair.second.accountNumber << " "
             << pair.second.pin << " "
             << pair.second.name << " "
             << pair.second.balance << endl;
    }
    fout.close();
}

// Load accounts
void Account::loadAll(map<string, Account> &accounts) {
    ifstream fin("accounts.txt");
    string accNo, userName, userPin;
    double bal;
    while (fin >> accNo >> userName >> userPin >> bal) {
        accounts[accNo] = Account(accNo, userName, userPin, bal);
    }
    fin.close();
}

// Generate account number
string Account::generateAccountNumber() {
    srand(time(0));
    int randNum = rand() % 900000 + 100000;
    return "ACC" + to_string(randNum);
}

// Register user
void Account::registerUser(map<string, Account> &accounts) {
    string accNo, name, pin;

    cout << "Enter your name (no spaces): ";
    cin >> name;
    cout << "Set a 4-digit PIN: ";
    cin >> pin;

    do {
        accNo = generateAccountNumber();
    } while (accounts.find(accNo) != accounts.end());

    Account newAcc(accNo, name, pin);
    accounts[accNo] = newAcc;
    Account::saveAll(accounts);

    cout << "Account Created Successfully\nAccount Number: " << accNo << endl;
}

// Login
Account* Account::login(map<string, Account> &accounts) {
    string accNo, pin;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter PIN: ";
    cin >> pin;

    if (accounts.find(accNo) != accounts.end() && accounts[accNo].getPin() == pin) {
        cout << "Login Successful. Welcome: " << accounts[accNo].getName() << "\n";
        return &accounts[accNo];
    } else {
        cout << "Invalid Account Number or PIN\n";
        return nullptr;
    }
}

// Update account map
void Account::updateAccountNumberInMap(map<string, Account> &accounts, const Account &acc) {
    accounts[acc.getAccountNumber()] = acc;
}
