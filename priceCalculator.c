#include <stdio.h>

int main()
{
    float price;
    float numberOfProducts;
    float VAT;
    float unitPrice;
    float totalPrice;

    printf("\n Saissisez le prix H.T du produit \n");
    scanf("%f", &price);
    printf("\n Saissisez le nombre de produit \n");
    scanf("%f", &numberOfProducts);
    printf("\n Saissisez le Taux de TVA\n");
    scanf("%f", &VAT);
    
    unitPrice = price + (price * (VAT/100));
    totalPrice = unitPrice * numberOfProducts;

    printf("\n Le prix à l'unité est de : %.2f € et le prix total est de  %.2f €\n", unitPrice, totalPrice);

    return 0;
}
