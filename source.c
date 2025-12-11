#include <stdio.h>

struct Item {
    char name[50];
    float price;
    int qty;
};

int main() {
    struct Item items[50];
    int n, i;
    float subtotal = 0, discount = 0, tax = 0, total = 0;
    float discountPct, taxPct;

    printf("===== TRANSACTION BILLING SYSTEM =====\n\n");

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nItem %d name: ", i + 1);
        scanf("%s", items[i].name);

        printf("Item %d price: ", i + 1);
        scanf("%f", &items[i].price);

        printf("Item %d quantity: ", i + 1);
        scanf("%d", &items[i].qty);

        subtotal += items[i].price * items[i].qty;
    }

    printf("\nEnter discount percentage: ");
    scanf("%f", &discountPct);

    printf("Enter tax/GST percentage: ");
    scanf("%f", &taxPct);

    discount = subtotal * (discountPct / 100.0);
    tax = (subtotal - discount) * (taxPct / 100.0);
    total = subtotal - discount + tax;

    printf("\n\n=========== FINAL BILL ===========\n");
    printf("%-20s %-10s %-10s %-10s\n", "Item", "Price", "Qty", "Total");

    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-10.2f\n",
               items[i].name,
               items[i].price,
               items[i].qty,
               items[i].price * items[i].qty);
    }

    printf("-------------------------------------------\n");
    printf("Subtotal: %.2f\n", subtotal);
    printf("Discount (%.2f%%): -%.2f\n", discountPct, discount);
    printf("Tax (%.2f%%): +%.2f\n", taxPct, tax);
    printf("-------------------------------------------\n");
    printf("TOTAL PAYABLE: %.2f\n", total);
    printf("===========================================\n");

    return 0;
}