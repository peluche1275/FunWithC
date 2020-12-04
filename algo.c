#include <stdio.h>
#include <unistd.h>

int main()
{

    long int A;
    long int B;
    long int Interchangor;

    printf("\n Bonjour et bienvenue dans : \n \n 'L'échangeur de Variables 2000' (Entier seulement) ! \n \n Merci de saisir votre première variable : \n\n");
    scanf("%ld", &A);
    printf("\n Vous avez saisi : %ld \n Merci de saisir votre seconde variable\n \n", A);
    scanf("%ld", &B);
    printf("\n Vous avez saisi : %ld\n \n", B);

    Interchangor = B;
    B = A;
    A = Interchangor;

    printf("Chargement en cours\n");
    sleep(2);
    printf("\n Incroyable, vos variables sont interchangées : %ld et %ld\n", A, B);

    return 0;
}
