#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100      // Maximum number of transactions stored

// Structure to manage bank transactions
struct BankAccount
{
    int balanceHistory[MAX_TRANSACTIONS]; // Stores balance history
    int lastTransactionIndex;     // Index of last transaction
};

// Initialize the bank account
void initializeBankAccount(struct BankAccount *account)
{
    account->lastTransactionIndex = -1;  // No transactions initially
}

// Function to deposit money
void depositMoney(struct BankAccount *account)
{
    if (account->lastTransactionIndex == MAX_TRANSACTIONS - 1)
    {
        printf("\n!! Transaction limit reached. Cannot deposit more money !!\n");
        return;
    }

    int depositAmount;
    printf("\nEnter the amount to deposit: ");
    scanf("%d",&depositAmount);

    if (depositAmount <= 0)
    {
        printf("\n!! Invalid deposit amount. Please enter a valid amount !!\n");
        return;
    }

    // Update transaction history with new balance
    account->lastTransactionIndex++;
    account->balanceHistory[account->lastTransactionIndex] = (account->lastTransactionIndex == 0) ? depositAmount : account->balanceHistory[account->lastTransactionIndex - 1] + depositAmount;
    printf("\n*!! Deposit Successful !!*\n");
}

// Function to withdraw money
void withdrawMoney(struct BankAccount *account)
{
    if (account->lastTransactionIndex == -1)
    {
        printf("\n!! No balance available. Please deposit first !!\n");
        return;
    }

    int currentBalance = account->balanceHistory[account->lastTransactionIndex]; // Get current balance
    printf("\nAvailable balance: %d", currentBalance);

    int withdrawAmount;
    printf("\nEnter amount to withdraw: ");
    scanf("%d",&withdrawAmount);

    if (withdrawAmount <= 0)
    {
        printf("\n!! Invalid withdrawal amount. Please enter a valid amount !!\n");
    }
    else if (withdrawAmount > currentBalance)
    {
        printf("\n!! Insufficient balance. Cannot withdraw more than available !!\n");
    }
    else
    {
        account->balanceHistory[account->lastTransactionIndex] -= withdrawAmount; // Deduct withdrawal amount
        printf("\n*!! Withdrawal Successful !!*\n");
        printf("Remaining balance: %d\n", (account->lastTransactionIndex >= 0) ? account->balanceHistory[account->lastTransactionIndex] : 0);
    }
}

// Function to display the current balance
void displayAccountBalance(const struct BankAccount *account)
{
    if (account->lastTransactionIndex == -1)
    {
        printf("\n!! No transactions available. Please deposit first !!\n");
        return;
    }

    printf("\nCurrent Account Balance: %d\n", account->balanceHistory[account->lastTransactionIndex]);

    // Log transaction in file
    FILE *file = fopen("Transactions.txt", "a+");
    if (file == NULL)
    {
        printf("\n!! Error opening transaction file !!\n");
        return;
    }
    fprintf(file, "Current Balance: %d\n", account->balanceHistory[account->lastTransactionIndex]);
    fclose(file);
}

int main()
{
    struct BankAccount account;
    initializeBankAccount(&account); // Initialize account

    int userChoice;
    while (1)
    {
        printf("\n------ Banking System ------");
        printf("\n1. Deposit Money");
        printf("\n2. Withdraw Money");
        printf("\n3. Check Balance");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&userChoice);

        switch (userChoice)
        {
            case 1:
                depositMoney(&account);
                break;
            case 2:
                withdrawMoney(&account);
                break;
            case 3:
                displayAccountBalance(&account);
                break;
            case 4:
                printf("\n!! Thank You For Using Our Banking System !!\n");
                exit(0);
            default:
                printf("\n!! Invalid choice. Please enter a valid option !!\n");
        }
    }
    return 0;
}
