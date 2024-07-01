#include <stdio.h>
#define MAX_ITEMS 5
typedef struct {
    char name[30];
    float price;
} MenuItem;
void displayMenu(MenuItem menu[], int size);
float calculateTotal(MenuItem menu[], int size, int quantities[]);
int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Pasta", 7.49},
        {"Salad", 4.99},
        {"Soda", 1.99}
    };

    int quantities[MAX_ITEMS] = {0};
    int choice, quantity;
    char continueOrder;

    do {
        displayMenu(menu, MAX_ITEMS);
        printf("Enter the item number to order (1-%d): ", MAX_ITEMS);
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_ITEMS) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);

        if (quantity < 1) {
            printf("Invalid quantity, please try again.\n");
            continue;
        }

        quantities[choice - 1] += quantity;

        printf("Do you want to order another item? (y/n): ");
        scanf(" %c", &continueOrder);

    } while (continueOrder == 'y' || continueOrder == 'Y');

    float total = calculateTotal(menu, MAX_ITEMS, quantities);
    printf("\n----- BILL -----\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (quantities[i] > 0) {
            printf("%s x%d = $%.2f\n", menu[i].name, quantities[i], menu[i].price * quantities[i]);
        }
    }
    printf("----------------\n");
    printf("Total: $%.2f\n", total);

    return 0;
}

void displayMenu(MenuItem menu[], int size) {
    printf("\n--- MENU ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float calculateTotal(MenuItem menu[], int size, int quantities[]) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += menu[i].price * quantities[i];
    }
    return total;
}
