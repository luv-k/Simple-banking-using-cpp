#include <iostream>
#include <string>
#include <vector>

// Account class
class Account {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    Account(std::string accNo, std::string holderName, double initialBalance)
        : accountNumber(accNo), accountHolderName(holderName), balance(initialBalance) {}

    std::string getAccountNumber() const {
        return accountNumber;}


    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. Remaining balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!" << std::endl;
        }
    }

    // Method to check balance
    double checkBalance() const {
        return balance;
    }

    // Method to get account details
    void displayAccountInfo() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

// Banking System class to manage multiple accounts
class BankingSystem {
private:
    std::vector<Account> accounts;

public:
    // Method to create a new account
    void createAccount(std::string accNo, std::string holderName, double initialDeposit) {
        Account newAccount(accNo, holderName, initialDeposit);
        accounts.push_back(newAccount);
        std::cout << "Account created successfully!" << std::endl;
    }

    // Method to find an account by account number
    Account* findAccount(std::string accNo) {
        for (auto& acc : accounts) {
           if (accNo == acc.getAccountNumber()) // Compare accNo with the account number
            {
                return &acc;
            }
        }
        std::cout << "Account not found!" << std::endl;
        return nullptr;
    }

    // Method to perform deposit operation
    void deposit(std::string accNo, double amount) {
        Account* acc = findAccount(accNo);
        if (acc) {
            acc->deposit(amount);
        }
    }

    // Method to perform withdrawal operation
    void withdraw(std::string accNo, double amount) {
        Account* acc = findAccount(accNo);
        if (acc) {
            acc->withdraw(amount);
        }
    }

    // Method to check balance
    void checkBalance(std::string accNo) {
        Account* acc = findAccount(accNo);
        if (acc) {
            std::cout << "Current balance: $" << acc->checkBalance() << std::endl;
        }
    }

    // Method to display account info
    void displayAccountInfo(std::string accNo) {
        Account* acc = findAccount(accNo);
        if (acc) {
            acc->displayAccountInfo();
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;
    std::string accNo, holderName;
    double amount;

    do {
        std::cout << "\nBanking System Menu:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Display Account Info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                std::cin.ignore();
                std::cout << "Enter Account Holder Name: ";
                std::getline(std::cin, holderName);
                std::cout << "Enter Initial Deposit: ";
                std::cin >> amount;
                bank.createAccount(accNo, holderName, amount);
                break;

            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                std::cout << "Enter Amount to Deposit: ";
                std::cin >> amount;
                bank.deposit(accNo, amount);
                break;

            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                std::cout << "Enter Amount to Withdraw: ";
                std::cin >> amount;
                bank.withdraw(accNo, amount);
                break;

            case 4:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                bank.checkBalance(accNo);
                break;

            case 5:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                bank.displayAccountInfo(accNo);
                break;

            case 6:
                std::cout << "Thank you for using the banking system!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
