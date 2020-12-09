#include <stdio.h>
#include <string.h>

int main()
{

    short int customerAge;
    short int numberOfLicenceYears;
    short int totalAccidents;
    short int numberOfContractYears;
    short int score = 0;
    char contractType[10];

    printf("Saissisez l'âge du client :\n");
    scanf("%hd", &customerAge);

    printf("Saissisez le nombre d'année dont le client est titulaire du permis :\n");
    scanf("%hd", &numberOfLicenceYears);

    printf("Saissisez le nombre d'accidents du client :\n");
    scanf("%hd", &totalAccidents);

    printf("Saissisez le nombre d'année dont le client est assuré :\n");
    scanf("%hd", &numberOfContractYears);

    if (customerAge >= 25)
    {
        score++;
    }

    if (numberOfLicenceYears >= 2)
    {
        score++;
    }

    score = score - totalAccidents;

    if (numberOfLicenceYears >= 5)
    {
        score++;
    }

    switch (score)
    {
    case 3:
        strcpy(contractType, "Bleu");
        break;
    case 2:
        strcpy(contractType, "Vert");
        break;
    case 1:
        strcpy(contractType, "Orange");
        break;
    case 0:
        strcpy(contractType, "Rouge");
        break;
    default:
        strcpy(contractType, "Refusé");
        break;
    }

    printf("\n Le contrat est %s \n", contractType);

    return 0;
}