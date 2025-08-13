#ifndef USERS_H
#define USERS_H
#include <string>
#include <vector>
#include <map>


using namespace std;
class UsersLogic
{
    private:
   // Structure for User Input
    struct User{
        string Fname;
        string Lname;
        string Username;
        string Password;
        double amount;
        double Balance;
       };

// Map to store user
map <string, User> StoreUsers;
// vector to store Transaction
vector <string> TransactionHistoryInfo;
// Initial Balance
double InitialBalance=0.00;

// Login Input
  string Set_Username;
  string Set_Password;



    public:
        // Menu function
        void UserMenu();
        // Register Function
        void UserRegister();
        //Login Function
        void UserLogin();
        // Transation Integration
        void IntergrationABC();
        //Deposit function
        void Deposit(double Amount);
        // Withdraw function
        void Withdraw(double Amount);
       // Transaction hostory function
       void TransactionHistory();


    //protected:
};
#endif // USERS_H
