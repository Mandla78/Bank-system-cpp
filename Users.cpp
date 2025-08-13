#include "Users.h"
#include <iostream>
#include <string>
#include <cmath>


using namespace std;

// Menu function
void UsersLogic::UserMenu(){
   int choice;
   int  const Terminate_Program = 5;

  do {
    cout<<"\n==== WELCOME TO RUB BANK SYSTEM ==== \n";
    cout<<"1. NEW USER [REGISTER HERE] \n";
    cout<<"2. ALREADY HAVE AN ACCOUNT [LOGIN HERE] \n";
    cout<<"3. BANK INFORMATION \n";
    cout<<"4. RULES AND REGULATION \n";
    cout<<"5. EXIT \n";
    cout<<"Enter ur Option: ";
    cin>>choice;

   // Invalid input
     if (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"INVALID OPTION, Please enter a valid option \n";
        continue;
     }

 switch (choice){
 case 1:
    UserRegister();
    break;
 case 2:
    UserLogin();
    break;
 case 3:
    cout<<"Successfully 3";
    break;
 case 4:
     cout<<"Successfully $";
     break;
 case 5:

    break;

 default:
    cout<<"INVALID OPTION, PLEASE ENTER A VALID OPTION: \n";
    }
  }
  while (choice != Terminate_Program );
}

// Register Function
 void UsersLogic::UserRegister(){
 User NewUser;
    cout<<" \n FILL THESE INPUT TO REGISTER \n";
    cout<<"Enter First Name: ";
    cin>>NewUser.Fname;
    cout<<"Enter Last Name: ";
    cin>>NewUser.Lname;
    cout<<"Enter Username: ";
    cin>>NewUser.Username;
    cout<<"Enter Password: ";
    cin>>NewUser.Password;

 // Check if Username exist
    if (StoreUsers.find(NewUser.Username) != StoreUsers.end()){
        cout<<"USERNAME alredy exist, Pleace refill the form \n";
        UserRegister();
    }

    else {
        StoreUsers[NewUser.Username] = NewUser;
        cout<<"Register Successfully \n";
        UserLogin();
    }
 }

 // Login Function
 void UsersLogic::UserLogin(){
  //string Set_Username;
  //string Set_Password;
  int attempts = 0;
  const int Max_Atempts = 3;

    while (attempts < Max_Atempts){
   cout<<"\n FILL THESE INPUT TO LOGIN \n";
   cout<<"ENTER USERNAME: ";
   cin>>Set_Username;
   cout<<"ENTE]=R PASSWORD: ";
   cin>>Set_Password;

// Check if Username and Password matches
   if (StoreUsers.find(Set_Username) != StoreUsers.end() && StoreUsers[Set_Username].Password == Set_Password){
    cout<<"[LOGIN SUCCESSFULY] WELCOME: "<<StoreUsers[Set_Username].Fname<<" "<<StoreUsers[Set_Username].Lname<<endl;
    IntergrationABC();
   }

 else { attempts++;
        cout<<"INVALID USERNAME OR PASSWORD, Please try again, REMAINING ATTEMTS: "<<Max_Atempts - attempts<<endl;
       }
    }
    cout<<"MAXIMUM ATTEMTS EXCEDED, LOGIN FAIL \n";
 }

 // Transaction Intergration
 void UsersLogic::IntergrationABC(){
   int choice;
   double Amount;

   while(true){

   cout<<"1. DEPOSIT \n";
   cout<<"2. WITHDRAW \n";
   cout<<"3. TRANSACTION HISTORY \n";
   cout<<"4. TRANSFER MONEY \n";
   cout<<"5. USER INFORMATION \n";
   cout<<"6. LOGOUT>>> \n";
   cout<<"Enter ur choice[1-5]: ";
   cin>>choice;

   // Invalid input
     if (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"INVALID OPTION, Please enter a valid option \n";
        continue;
     }

     switch (choice){

     case 1:
     cout<<"ENTER DEPOSIT AMOUNT: R";
     cin>>Amount;
     Deposit(Amount);
     break;

     case 2:
     cout<<"ENTER WITHDRAW AMOUNT: R";
     cin>>Amount;
     Withdraw(Amount);
     break;

     case 3:
     TransactionHistory();
     break;

     case 4:
     cout<<"successfully 4";
     break;

     case 5:
     cout<<"successfully 5";
     break;

     case 6:
     cout<<"THANK FOR USING OUR SYSTEM, PLEASE VISIT AGAIN \n";
     UserMenu();
     break;

     default:
        cout<<"INVALID OPTION, Please enter a valid option [1-6] \n";

     }
   }
 }

 // Deposit function
 void UsersLogic::Deposit(double Amount){
     User NewUser;

    if (StoreUsers.find(Set_Username) != StoreUsers.end() && StoreUsers[Set_Username].Password == Set_Password){
            NewUser.amount = Amount;
            InitialBalance = NewUser.Balance;
     if (NewUser.amount <= 0){
        cout<<"INVALID AMOUNT \n";
     }
     else {
          NewUser.Balance+=NewUser.amount;
          cout<<"AMOUNT DEPOSITED SUCCESSFULLY: R"<<NewUser.amount<<endl;
          cout<<"CURRENT BALANCE: R"<<NewUser.Balance<<endl;
          string Set_Updates= "AMOUNT DEPOSITED: R" + to_string(NewUser.amount)+ ", BALANCE: R"+to_string(NewUser.Balance);
          TransactionHistoryInfo.push_back(Set_Updates);
      }
   }
 }

// Withdraw function
void UsersLogic::Withdraw(double Amount) {

     User NewUser;

    if (StoreUsers.find(Set_Username) != StoreUsers.end() && StoreUsers[Set_Username].Password == Set_Password){
            Amount = NewUser.amount;
            InitialBalance = NewUser.Balance;

      if (NewUser.amount > NewUser.Balance){
        cout<<"INSUFICIENT FUND \n";
      }
      else if (NewUser.amount <= 0){
              cout<<"INVALID AMOUNT \n";
      }
      else{
        NewUser.Balance-=NewUser.amount;
        cout<<"AMOUNT WITHDREW SUCCESSFULLY: R"<<NewUser.amount<<endl;
        cout<<"CURRENT BALANCE: R"<<NewUser.Balance<<endl;
         string Set_Updates= "AMOUNT WITHDREW: R" +to_string(NewUser.amount)+ ", BALANCE: R"+ to_string(NewUser.Balance);
         TransactionHistoryInfo.push_back(Set_Updates);
      }
   }
}

// Transaction hostory function
void UsersLogic::TransactionHistory(){
    if (TransactionHistoryInfo.empty()){
    cout<<"NO TRANSACTION HISTORY AVAILABLE \n";
}
else {
    cout<<"TRANSACTION HISTORY"<<endl;
  // Accessing Transaction History
  for (string & records : TransactionHistoryInfo){
      cout<<records<<endl;
      }
   }
}












































