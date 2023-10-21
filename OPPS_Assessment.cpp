#include <iostream>
#include <ctime>
using namespace std;

class BankAccount {
private:
    double initialBalance;
    double currentBalance;

public:
    BankAccount() {
        initialBalance = 60000;
        currentBalance = 20000;
    }

     getBalance() {
        return currentBalance;
    }

     deposit(double amount) {
        if (amount > 0) {
            currentBalance += amount;
            cout << "Deposit successful. New balance: Rs. " << currentBalance <<endl;
        } else {
            cout << "Invalid deposit amount." <<endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && currentBalance >= amount) {
            currentBalance -= amount;
            cout << "Withdrawal successful. New balance: Rs. " << currentBalance << endl;
            return true;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
            return false;
        }
    }
};

int main() {
    
    time_t currentTime = time(0);
    cout << "Welcome to the Bank" << endl;
    cout << "Current Date and Time: " <<ctime(&currentTime);

    // ATM PIN
    int pin = 1469;
    int attempts = 1;

    int choice;

    do {
        cout << "MENU: " << endl;
        cout << "1. Enter ATM Pin" <<endl;
        cout << "2. Help" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int enteredPin;
            cout << "Enter your ATM PIN: ";
                cin >> enteredPin;

                if (enteredPin == pin) {
                    cout << "PIN accepted. Access granted." << endl;
                    // Display Menu Screen
                    int menuChoice;
                    BankAccount account;
                    do {
                        cout << "MENU: " <<endl;
                        cout << "1. Deposit" <<endl;
                        cout << "2. Withdraw" << endl;
                        cout << "3. Check Balance" << endl;
                        cout << "4. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> menuChoice;

                        switch (menuChoice) {
                            case 1:
                                double depositAmount;
                                cout << "Enter the amount to deposit: Rs. ";
                                cin >> depositAmount;
                                account.deposit(depositAmount);
                                break;
                            case 2:
                                double withdrawalAmount;
                                cout << "Enter the amount to withdraw: Rs. ";
                                cin >> withdrawalAmount;
                                account.withdraw(withdrawalAmount);
                                break;
                            case 3:
                                cout << "Current balance: Rs. " << account.getBalance() <<endl;
                                break;
                            case 4:
                                cout << "Exiting ATM. Have a nice day!" << endl;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    } while (menuChoice != 4);
                } else {
                    if (attempts < 1) {
                        cout << "Incorrect PIN. Maximum attempts reached. Exiting." <<endl;
                        return 0;
                    } else {
                        cout << "Incorrect PIN. " << attempts << " attempts left." << endl;
                        attempts--;
                    }
                }
                break;
            case 2:
                cout << "Help: This is a simple ATM application. Enter your ATM PIN to access your account." <<endl;
                break;
            case 3:
                cout << "Exiting ATM. Have a nice day!" << endl;
				                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
