#include <stdio.h>
#include <string.h>

short int customerAge;
short int timeLicenceHolder;
short int totalAccidents;
short int numberOfContractYears;
short int score = 0;
char contractType[10];

void userEntries()
{
    printf("Saissisez l'âge du client :\n");
    scanf("%hd", &customerAge);

    printf("Saissisez le nombre d'année dont le client est titulaire du permis :\n");
    scanf("%hd", &timeLicenceHolder);

    printf("Saissisez le nombre d'accidents du client :\n");
    scanf("%hd", &totalAccidents);

    printf("Saissisez le nombre d'année dont le client est assuré :\n");
    scanf("%hd", &numberOfContractYears);
}

void scoreGeneration()
{
    if (customerAge >= 25)
    {
        score++;
    }

    if (timeLicenceHolder >= 2)
    {
        score++;
    }

    score = score - totalAccidents;

    if (numberOfContractYears >= 5)
    {
        score++;
    }
}

void definitionOfTheContract()
{

    const char *colorsOfTheContract[] = {"Rouge", "Orange", "Vert", "Bleu"};

    if (score >= 0)
    {
        strcpy(contractType, colorsOfTheContract[score]);
        printf("\n Le contrat est %s.\n", contractType);
    }
    else
    {
        printf("\n Nous ne pouvons pas accepter ce client. \n");
    }
}

int main()
{

    userEntries();

    scoreGeneration();

    definitionOfTheContract();

    return 0;
}
