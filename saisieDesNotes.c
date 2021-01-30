#include <stdio.h>
#include <string.h>
#include "saisieDesNotes.h"
#define CLASSROOMSIZE 3

int enterClassroom(NoteStudent Classroom[]);

void enterStudent(NoteStudent *noteStudent);

void printAppreciation(mention appreciation);

void appreciationCalcul(NoteStudent *noteStudent);

void showClassroomNotes(NoteStudent Classroom[]);

NoteStudent *searchStudentNote(NoteStudent Classroom[]);

void updateStudentNote(NoteStudent *noteStudent);

void calculateClassroomStatistics(NoteStudent Classroom[], int chosenParameter);

void sortByAlphabeticOrder(NoteStudent Classroom[]);

void bubbleSort(NoteStudent Classroom[]);

void selectionSort(NoteStudent Classroom[]);

void binarySearch(NoteStudent Classroom[], int parameterChosen);

int main()
{
    NoteStudent Classroom[CLASSROOMSIZE];
    int registeredClassroom = 0;
    int userSelection;

    while (1)
    {
        printf("Choissisez votre action :\n \n"
               "  1 - Saisir la note des élèves \n"
               "  2 - Voir les notes de la Classe \n"
               "  3 - Chercher un élève \n"
               "  4 - Modifier une note \n"
               "  5 - Voir la moyenne \n"
               "  6 - Voir la note la plus basse \n"
               "  7 - Voir la note la plus haute \n"
               "  8 - Tri par ordre alphabetique \n"
               "  9 - Tri par bulle \n"
               " 10 - Tri par selection \n"
               " 11 - Recherche dichotomique des notes\n"
               " 12 - Recherche dichotomique des élèves\n"
               "  \n"
               " 0 - Quitter \n\n");

        scanf("%d", &userSelection);

        if (registeredClassroom)
        {
            switch (userSelection)
            {
            case 1:
                enterClassroom(Classroom);
                break;
            case 2:
                showClassroomNotes(Classroom);
                break;
            case 3:
                searchStudentNote(Classroom);
                break;
            case 4:
                updateStudentNote(searchStudentNote(Classroom));
                break;
            case 5:
                calculateClassroomStatistics(Classroom, 1);
                break;
            case 6:
                calculateClassroomStatistics(Classroom, 2);
                break;
            case 7:
                calculateClassroomStatistics(Classroom, 3);
                break;
            case 8:
                sortByAlphabeticOrder(Classroom);
                showClassroomNotes(Classroom);
                break;
            case 9:
                bubbleSort(Classroom);
                showClassroomNotes(Classroom);
                break;
            case 10:
                selectionSort(Classroom);
                showClassroomNotes(Classroom);
                break;
            case 11:
                selectionSort(Classroom);
                binarySearch(Classroom, 1);
                break;
            case 12:
                sortByAlphabeticOrder(Classroom);
                binarySearch(Classroom, 2);
                break;
            default:
                printf("\nFin du programme.\n\n");
                return 0;
            }
        }
        else
        {
            if (userSelection == 1)
            {
                registeredClassroom = enterClassroom(Classroom);
            }
            else if (userSelection > 1)
            {
                printf("Les notes des élèves n'ont pas étaient saisis.\n");
            }
            else
            {
                printf("\nFin du programme.\n\n");
                return 0;
            }
        }
    }
}

// CHOICE 1 //

int enterClassroom(NoteStudent Classroom[])
{
    for (int i = 0; i < CLASSROOMSIZE; i++)
    {
        enterStudent(&Classroom[i]);
    }
    return 1;
}

void enterStudent(NoteStudent *noteStudent)
{
    char temp;

    printf("Saisir le nom et le prénom de l'élève.\n");
    scanf("%c", &temp);
    scanf("%[^\n]", noteStudent->name);
    printf("Saisir la note de l'élève.\n");
    scanf("%lf", &noteStudent->note);

    appreciationCalcul(noteStudent);

    printf("Vous avez enregistrer la note de %.1f pour %s avec mention : ", noteStudent->note, noteStudent->name);
    printAppreciation(noteStudent->appreciation);
    printf("\n\n");
}

void appreciationCalcul(NoteStudent *noteStudent)
{
    if (noteStudent->note > 14)
    {
        noteStudent->appreciation = TRES_BIEN;
    }
    else if (noteStudent->note > 12)
    {
        noteStudent->appreciation = BIEN;
    }
    else if (noteStudent->note > 10)
    {
        noteStudent->appreciation = SATISFAISANT;
    }
    else
    {
        noteStudent->appreciation = AUCUNE;
    }
}

void printAppreciation(mention appreciation)
{
    switch (appreciation)
    {
    case 3:
        printf("Très bien");
        break;
    case 2:
        printf("Bien");
        break;
    case 1:
        printf("Satisfaisant");
        break;
    case 0:
        printf("Aucune");
        break;

    default:
        printf("Pas d'appréciation enregistrée");
    }
}

// CHOICE 2 //

void showClassroomNotes(NoteStudent Classroom[])
{
    printf("\nListe des notes de la Classe : \n\n");
    for (int i = 0; i < CLASSROOMSIZE; i++)
    {
        printf("%s | Note : %.1f | Mention : ", Classroom[i].name, Classroom[i].note);
        printAppreciation(Classroom[i].appreciation);
        printf("\n");
    }
    printf("\n");
}

// CHOICE 3 //

NoteStudent *searchStudentNote(NoteStudent Classroom[])
{
    char nameOfTheStudentToSearch[20];
    char temp;

    printf("Entrez le nom d'un élève.\n");
    scanf("%c", &temp);
    scanf("%[^\n]", nameOfTheStudentToSearch);
    int find = 0;

    printf("%s", nameOfTheStudentToSearch);

    for (int i = 0; i < CLASSROOMSIZE; i++)
    {
        if (strcmp(Classroom[i].name, nameOfTheStudentToSearch) == 0)
        {
            find = 1;
            printf("La note de %s est %.1f\n", Classroom[i].name, Classroom[i].note);
            return &Classroom[i];
        }
    }

    if (find == 0)
    {
        printf("Nous n'avons pas trouver l'élève.\n\n");
        return 0;
    }
}

// CHOICE 4 //

void updateStudentNote(NoteStudent *noteStudent)
{
    if (noteStudent)
    {
        printf("Quelle est la nouvelle note ?\n");
        scanf("%lf", &noteStudent->note);
        appreciationCalcul(noteStudent);
    }
    else
    {
        printf("Nous n'avons pas trouvé l'élève.\n");
    }
}

// CHOICE 5 , 6 , 7 //

void calculateClassroomStatistics(NoteStudent Classroom[], int chosenParameter)
{
    double average = 0;
    double highestNote = 0;
    double lowestNote = 20;

    for (int i = 0; i < CLASSROOMSIZE; i++)
    {
        average = average + Classroom[i].note;

        if (Classroom[i].note > highestNote)
        {
            highestNote = Classroom[i].note;
        }

        if (Classroom[i].note < lowestNote)
        {
            lowestNote = Classroom[i].note;
        }
    }

    average = average / CLASSROOMSIZE;

    switch (chosenParameter)
    {
    case 1:
        printf("La moyenne est de %.1f\n\n", average);
        break;
    case 2:
        printf("La note la plus basse est %.1f\n", lowestNote);
        break;
    case 3:
        printf("La note la plus grande est %.1f\n", highestNote);
        break;
    default:
        printf("Pas d'option choisie");
    }
}

// SORT ALGORITHMS //

void sortByAlphabeticOrder(NoteStudent Classroom[])
{
    printf("Voici la classe en ordre alphabetic \n\n");

    NoteStudent temp;

    for (int i = 0; i < CLASSROOMSIZE; i++)
    {

        for (int j = i + 1; j < CLASSROOMSIZE; j++)
        {
            if (strcmp(Classroom[i].name, Classroom[j].name) > 0)
            {
                temp = Classroom[i];
                Classroom[i] = Classroom[j];
                Classroom[j] = temp;
            }
        }
    }

    for (int i = 0; i < CLASSROOMSIZE; i++)
    {
        printf("%s \n", Classroom[i].name);
    }
}

void bubbleSort(NoteStudent Classroom[])
{
    printf("Voici la classe en ordre croissant \n\n");

    NoteStudent temp;

    for (int i = 0; i < CLASSROOMSIZE - 1; i++)
    {
        for (int j = 0; j < CLASSROOMSIZE - i - 1; j++)
        {
            if (Classroom[j].note > Classroom[j + 1].note)
            {
                temp = Classroom[j];
                Classroom[j] = Classroom[j + 1];
                Classroom[j + 1] = temp;
            }
        }
    }
}

void selectionSort(NoteStudent Classroom[])
{
    NoteStudent temp;
    int temporaryIndex;

    for (int i = 0; i < CLASSROOMSIZE - 1; i++)
    {
        temporaryIndex = i;
        for (int j = i + 1; j < CLASSROOMSIZE; j++)
        {
            if (Classroom[temporaryIndex].note > Classroom[j].note)
            {
                temporaryIndex = j;
            }
        }

        temp = Classroom[temporaryIndex];
        Classroom[temporaryIndex] = Classroom[i];
        Classroom[i] = temp;
    }
}


void binarySearch(NoteStudent Classroom[], int parameterChosen)
{
    int valuePosition = -1;
    int startSearchArea = 0;
    int middleSearchArea;
    int endSearchArea = CLASSROOMSIZE - 1;
    
    int noteToSearch;
    char nameToSearch[20];
    char temp;

    if (parameterChosen == 1)
    {
        printf("Note à rechercher : ");
        scanf("%d", &noteToSearch);
    }
    else if (parameterChosen == 2)
    {
        printf("Nom à rechercher : ");
        scanf("%c", &temp);
        scanf("%[^\n]", nameToSearch);
    }

    while ((startSearchArea <= endSearchArea) && (valuePosition == -1))
    {
        middleSearchArea = (endSearchArea + startSearchArea) / 2;

        if (parameterChosen == 1)
        {
            if (noteToSearch < Classroom[middleSearchArea].note)
            {
                endSearchArea = middleSearchArea - 1;
            }
            else if (noteToSearch > Classroom[middleSearchArea].note)
            {
                startSearchArea = middleSearchArea + 1;
            }
            else
            {
                valuePosition = middleSearchArea;
            }
        }
        else if (parameterChosen == 2)
        {
            if (strcmp(nameToSearch, Classroom[middleSearchArea].name) < 0)
            {
                endSearchArea = middleSearchArea - 1;
            }
            else if (strcmp(nameToSearch, Classroom[middleSearchArea].name) > 0)
            {
                startSearchArea = middleSearchArea + 1;
            }
            else
            {
                valuePosition = middleSearchArea;
            }
        }
    }

    if (valuePosition == -1)
    {
        printf("Nous n'avons pas trouvé le bulletin recherché.\n");
    }
    else
    {
        printf("Bulletin : \n"
               "%s | Note : %.1f \n",
               Classroom[valuePosition].name, Classroom[valuePosition].note);
    }
}