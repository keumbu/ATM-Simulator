#include <stdio.h>

int main(){
    int option;
    double balance = 1000.0; // Initial balance  
 

    while(1){
        printf("ATM Simulator\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Your balance is: $%.2f\n", balance);
                break;
            case 2:
                double deposit;
                printf("Enter amount to deposit: ");
                scanf("%lf", &deposit);
                if(deposit > 0){
                    balance += deposit;
                    printf("Deposit successful!New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid deposit amount\n");
                }
                break;
            case 3:
                double withdraw;
                printf("Enter amount to withdraw: ");
                scanf("%lf", &withdraw);
                if(withdraw > 0 && withdraw <= balance){
                    balance -= withdraw;
                    printf("Withdrawn successful! New balance: $%.2f\n", balance);
                } else {
                    printf("Insufficient balance.\n");
                }
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