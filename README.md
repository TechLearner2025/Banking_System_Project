# Banking System

## Project Description
This project is a simple Banking System implemented in C. It allows users to perform basic banking operations such as depositing money, withdrawing money, and checking the account balance. The system maintains a transaction history of up to 100 transactions.

## Features
- Deposit Money: Allows users to deposit money into their account, updating the balance history accordingly.
- Withdraw Money: Allows users to withdraw money if sufficient balance is available.
- Check Balance: Displays the current account balance and logs it to a file named 'Transactions.txt'.
- Transaction History: Keeps track of the balance history for up to 100 transactions.

## Inputs
1. Deposit Money (Option 1): Enter the amount to deposit.
2. Withdraw Money (Option 2): Enter the amount to withdraw.
3. Check Balance (Option 3): Displays the current balance and logs it to 'Transactions.txt'.
4. Exit (Option 4): Exits the program.

## File Structure
- Main Code File: Contains the implementation of the banking system.
- Transactions.txt: Stores the balance history when the user checks their account balance.

## Requirements
- Standard C compiler (e.g., GCC).
- Console environment for program interaction.

## Compilation and Usage
1. Compile the code using `gcc -o BankingSystem BankingSystem.c`.
2. Run the executable with `./BankingSystem`.
3. Follow the on-screen instructions to perform banking operations.

## Future Improvements
- Adding authentication features for better security.
- Implementing persistent storage of transaction history across multiple program runs.
- Improving input validation and error handling.

