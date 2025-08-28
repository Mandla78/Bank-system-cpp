## Bank System in C++


A simple **console-based bank management system** written in C++ that allows users to register, login, deposit, withdraw, transfer funds, and view transaction history. The system persists account information and transaction history using text files. 

-----

## Features

- **User Registration**: Create a new account with a unique account number and 4-digit PIN.  
- **Login System**: Secure login for existing users.  
- **Deposit**: Add funds to an account.  
- **Withdrawal**: Withdraw funds with balance validation.  
- **Transfer**: Transfer money between accounts.  
- **Transaction History**: View past deposits, withdrawals, and transfers.  
- **Persistent Storage**: Accounts and transaction histories are saved in text files.

-----

 ## File Structure
  Bank_System/
├── Account.h # Class declaration
├── Account.cpp # Class implementation
├── main.cpp # Main program with menu interface
├── accounts.txt # Stores account details (auto-generated)
├── <ACC#>_history.txt # Transaction history files (auto-generated)
└── README.md # Project documentation

-----

## How to Compile and Run

1. **Open terminal / command prompt** and navigate to the project folder:  

(a.) cd path/to/Bank_System
(b.) g++ main.cpp Account.cpp -o bank_system
(c.) ./bank_system      # Linux / Mac
    bank_system.exe    # Windows
