#include "Account.h"

int main() {
    map<string, Account> accounts;
    Account::loadAll(accounts);

    while (true) {
        int choice;
        cout << "\n== Bank System ==\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose option: ";
        cin >> choice;

        if (choice == 1) {
            Account::registerUser(accounts);
        }
        else if (choice == 2) {
            Account* user = Account::login(accounts);
            if (user) {
                int option;
                do {
                    cout << "\n1. Deposit\n2. Withdraw\n3. Transfer\n4. Show balance\n5. Show Transaction History\n6. LogOut\n";
                    cout << "Choose option: ";
                    cin >> option;

                    if (option == 1) {
                        double amt;
                        cout << "Enter amount to deposit: ";
                        cin >> amt;
                        user->deposit(amt);
                    }
                    else if (option == 2) {
                        double amt;
                        cout << "Enter amount to withdraw: ";
                        cin >> amt;
                        user->withdraw(amt);
                    }
                    else if (option == 3) {
                        string toAcc;
                        double amt;
                        cout << "Enter recipient account number: ";
                        cin >> toAcc;
                        if (accounts.find(toAcc) != accounts.end()) {
                            cout << "Enter amount to transfer: ";
                            cin >> amt;
                            user->transfer(accounts[toAcc], amt);
                        } else {
                            cout << "Account not found\n";
                        }
                    }
                    else if (option == 4) {
                        user->showBalance();
                    }
                    else if (option == 5) {
                        user->showTransactionHistory();
                    }

                    Account::saveAll(accounts);
                } while (option != 6);
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid Option\n";
        }
    }

    return 0;
}
