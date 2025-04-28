#include <stdio.h>
int pinVerification(int pin);
void checkBalance(double balance);
void depositMoney(double *balance);
void withdrawMoney(double *balance);

int main(){
    double balance = 1000.0; // Initial balance  
    int pin = 4321; // ATM PIN
    int enteredPin;
    int attempts = 3;// Number of attempts

    while(attempts > 0){  // PIN verification loop
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);
        if(pinVerification(enteredPin)){
            printf("PIN accepted! Access granted.\n");
            break; //exit the loop if PIN is correct
        } else {
            attempts--;
            printf("Incorrect PIN. You have %d attempts left.\n", attempts);

            if(attempts == 0){
                printf("You have been locked out due to too mamy faild attempts.\n");
                return 1; // Exit the program
        }
    }
   
}
    // ATM menu loop
int option;
    while(1){
        displayMenu();
        printf("Enter your option");
        scanf("%d",&option);
       
        switch(option){
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
                printf("Thank you for using the ATM simulator.Goodbye!\n");
                return 0;
    
            default:
                printf("Invalid option. Please try again.\n");
  
        }
    }
    return 0;
}
   //Function to verify PIN
   int pinVerification(int entreredpin) {
       int correctPin = 4321;
       return entreredpin == correctPin; //Return true if correct
   }
   //Function to check balance
    void checkBalance(double balance) {
         printf("Your current balance is: $%.2f\n", balance);
    }
    //Function to deposit money
    void depositMoney(double *balance){
        double deposit;
        printf("Enter the amount to deposit: ");
        scanf("%1f",&deposit);
        if(deposit > 0){
            *balance += deposit; //update balance
             printf("Deposit successful! New balance: $%.2\n",*balance);
        }else {
            printf("Invalid deposit amount.\n");
        }
    }
    void withdrawMoney(double *balance) {
         double withdraw;
          printf("Enter the amount to withdraw: ");
          scanf("%1f",&withdraw);
         if(withdraw > 0 && withdraw <= *balance) {
            *balance -=withdraw; //Update balance
         } else {
            printf("Insufficient balance.\n");
          }
         }
   //Function to display ATM menu
   void displayMenu(){
       printf("\n=== ATM Simulator ===\n");
       printf("1. Check Balance\n");
       printf("2. Deposit Money\n");
       printf("3. Withdraw Money\n");
       printf("4. Exit\n");
   }