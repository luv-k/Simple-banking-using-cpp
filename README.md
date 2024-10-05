# Banking System in C++

This project implements a simple banking system using C++. It allows users to create accounts, deposit and withdraw money, check balances, and display account information. The system manages multiple accounts through a `BankingSystem` class that utilizes the `Account` class for individual account management.

## Features

- **Account Management:** Create new accounts with account numbers and holder names.
- **Deposit & Withdrawal:** Users can deposit and withdraw funds from their accounts.
- **Balance Inquiry:** Check the current balance of an account.
- **Account Information Display:** View detailed account information, including account number, holder name, and current balance.

## Requirements

- A C++ compiler (such as g++, clang++, or any IDE that supports C++).

## How to Compile and Run

1. **Clone or Download the Repository**:
   Clone the repository or download the project files to your local machine.

2. **Navigate to the Project Directory**:
   Open your terminal or command prompt and navigate to the directory where the code is located.

3. **Compile the Code**:
   Use the following command to compile the program:

   ```bash
   g++ -o banking_system main.cpp
   ```

4. **Run the Program**:
   Execute the compiled program using the following command:

   ```bash
   ./banking_system
   ```

## How to Use

1. After running the program, you will see a menu with options to create an account, deposit money, withdraw money, check balance, display account info, or exit.
2. Follow the prompts to enter the required information for each operation.

## Example Usage

- Create a new account:
  ```
  Enter Account Number: 123456
  Enter Account Holder Name: John Doe
  Enter Initial Deposit: 1000
  ```

- Deposit money:
  ```
  Enter Account Number: 123456
  Enter Amount to Deposit: 500
  ```

- Withdraw money:
  ```
  Enter Account Number: 123456
  Enter Amount to Withdraw: 200
  ```

- Check balance:
  ```
  Enter Account Number: 123456
  ```
