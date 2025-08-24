#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ✅ Structure to represent an account
struct Account {
    int accountNumber;
    char name[100];
    double balance;
};

// ⚡ Function to create a new account
void createAccount() {
    struct Account acc;
    FILE *file = fopen("accounts.txt", "a");

    if (file == NULL) {
        printf("⚠️ Could not open accounts.txt\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);

    printf("Enter name: ");
    scanf("%s", acc.name);

    printf("Enter initial balance: ");
    scanf("%lf", &acc.balance);

    fwrite(&acc, sizeof(struct Account), 1, file);
    fclose(file);

    printf("✅ Account created successfully!\n");
}

// ⚡ Function to deposit money
void deposit() {
    int num;
    double amount;
    struct Account acc;
    FILE *file = fopen("accounts.txt", "r+");

    if (file == NULL) {
        printf("⚠️ Could not open accounts.txt\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &num);

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.accountNumber == num) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            acc.balance += amount;

            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);

            printf("✅ Deposit successful. New balance = %.2lf\n", acc.balance);
            fclose(file);
            return;
        }
    }

    printf("⚠️ Account not found!\n");
    fclose(file);
}

// ⚡ Function to withdraw money
void withdraw() {
    int num;
    double amount;
    struct Account acc;
    FILE *file = fopen("accounts.txt", "r+");

    if (file == NULL) {
        printf("⚠️ Could not open accounts.txt\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &num);

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.accountNumber == num) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (acc.balance >= amount) {
                acc.balance -= amount;
                fseek(file, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, file);
                printf("✅ Withdrawal successful. New balance = %.2lf\n", acc.balance);
            } else {
                printf("⚠️ Insufficient balance!\n");
            }

            fclose(file);
            return;
        }
    }

    printf("⚠️ Account not found!\n");
    fclose(file);
}

// ⚡ Function to check account balance
void checkBalance() {
    int num;
    struct Account acc;
    FILE *file = fopen("accounts.txt", "r");

    if (file == NULL) {
        printf("⚠️ Could not open accounts.txt\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &num);

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.accountNumber == num) {
            printf("👤 Name: %s\n", acc.name);
            printf("💰 Balance: %.2lf\n", acc.balance);
            fclose(file);
            return;
        }
    }

    printf("⚠️ Account not found!\n");
    fclose(file);
}

// ⚡ Main menu
int main() {
    int choice;

    while (1) {
        printf("\n===== 🏦 Bank Management CLI =====\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: exit(0);
            default: printf("⚠️ Invalid choice!\n");
        }
    }

    return 0;
}
