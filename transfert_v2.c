#include <stdio.h>

int main()
{

    long int A;
    long int B;
    long int C;
    long int firstInterchangor;
    long int secondInterchangor;

    printf("\n Saissisez A\n");
    scanf("%ld", &A); // 2
    printf("\n Saissisez B\n");
    scanf("%ld", &B); // 7
    printf("\n Saissisez C\n");
    scanf("%ld", &C); //4

    printf("\n Vous aviez saisi : \n \n A = %ld B = %ld C = %ld\n", A, B, C);
    
    firstInterchangor = A;
    secondInterchangor = B;
    A = C;
    B = firstInterchangor;
    C = secondInterchangor;

    printf("\n Vous avez maintenant : \n \n A = %ld B = %ld C = %ld\n", A, B, C);

    return 0;
}
