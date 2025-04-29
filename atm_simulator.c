#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTION 100 // Maximum number of transactions

// Global variables for transaction history
char transactionHistory[MAX_TRANSACTION][100];
int transactionCount = 0;

// Function declarations
int pinVerification(int pin);
void checkBalance(double balance);
void depositMoney(double *balance);
void withdrawMoney(double *balance);
void showTransactionHistory();
void addTransaction(const char *transaction);
void displayMenu();
void clearInvalidBuffer();

int main() {
    double balance = 1000.0; // Initial balance
    int enteredPin;
    int attempts = 3; // Number of attempts

    // PIN verification loop
    while (attempts > 0) {
        printf("Enter your PIN: ");
        if (scanf("%d", &enteredPin) != 1) { // Check if input is a number
            printf("Invalid input. Please enter numbers only.\n");
            clearInvalidBuffer(); // Clear the input buffer
            continue; // Restart the loop
        }
        clearInvalidBuffer(); // Clear the input buffer after scanf

        if (pinVerification(enteredPin)) {
            printf("PIN accepted! Access granted.\n");
            break; // Exit the loop if PIN is correct
        } else {
            attempts--;
            printf("Incorrect PIN. You have %d attempts left.\n", attempts);

            if (attempts == 0) {
                printf("You have been locked out due to too many failed attempts.\n");
                return 0; // Exit the program
            }
        }
    }

    // ATM menu loop
    int option;
    while (1) {
        displayMenu();
        printf("Enter your option: ");
        if (scanf("%d", &option) != 1) { // Check if input is a number
            printf("Invalid input. Please enter a number.\n");
            clearInvalidBuffer(); // Clear the input buffer
            continue; // Restart the loop
        }
        clearInvalidBuffer(); // Always clear after the scanf

        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                depositMoney(&balance);
                break;
            case 3:
                withdrawMoney(&balance);
                break;
            case 4:
                showTransactionHistory();
                break;
            case 5:
                printf("Thank you for using the ATM simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// Function to verify PIN
int pinVerification(int enteredPin) {
    int correctPin = 4321;
    return enteredPin == correctPin; // Return true if correct
}

// Function to check balance
void checkBalance(double balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

// Function to deposit money
void depositMoney(double *balance) {
    double deposit;
    printf("Enter the amount to deposit: ");
    if (scanf("%lf", &deposit) != 1 || deposit <= 0) { // Check if input is a number
        printf("Invalid deposit amount.\n");
        clearInvalidBuffer(); // Clear the input buffer
        return; // Exit the function
    }
    clearInvalidBuffer();
    *balance += deposit; // Update balance
    printf("Deposit successful! New balance: $%.2f\n", *balance);

    // Log the transaction
    char transaction[100];
    snprintf(transaction, sizeof(transaction), "Deposited: $%.2f", deposit);
    addTransaction(transaction);
}

// Function to withdraw money
void withdrawMoney(double *balance) {
    double withdraw;
    printf("Enter the amount to withdraw: ");
    if (scanf("%lf", &withdraw) != 1 || withdraw <= 0) { // Check if input is a number
        printf("Invalid withdrawal amount.\n");
        clearInvalidBuffer(); // Clear the input buffer
        return; // Exit the function
    }
    clearInvalidBuffer();
    if (withdraw > 0 && withdraw <= *balance) {
        *balance -= withdraw; // Update balance
        printf("Withdrawal successful! New balance: $%.2f\n", *balance);

        // Log the transaction
        char transaction[100];
        snprintf(transaction, sizeof(transaction), "Withdrew: $%.2f", withdraw);
        addTransaction(transaction);
    } else {
        printf("Insufficient balance.\n");
    }
}

// Function to add a transaction to the history
void addTransaction(const char *transaction) {
    if (transactionCount < MAX_TRANSACTION) {
        strcpy(transactionHistory[transactionCount], transaction); // Add transaction to history
        transactionCount++;
    } else {
        printf("Transaction history is full. Cannot log more transactions.\n");
    }
}

// Function to view transaction history
void showTransactionHistory() {
    printf("Transaction History:\n");
    if (transactionCount == 0) {
        printf("No transactions available.\n");
    } else {
        for (int i = 0; i < transactionCount; i++) {
            printf("%d. %s\n", i + 1, transactionHistory[i]); // Display each transaction
        }
    }
}

// Function to display ATM menu
void displayMenu() {
    printf("\nATM Simulator\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Transaction History\n");
    printf("5. Exit\n");
}

// Function to clear invalid input
void clearInvalidBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear all the input buffer
}