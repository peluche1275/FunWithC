typedef enum Mention mention;

    enum Mention
{
    AUCUNE = 0,
    SATISFAISANT = 1,
    BIEN = 2,
    TRES_BIEN = 3
};

typedef struct NoteStudent NoteStudent;

struct NoteStudent
{
    char name[20];
    double note;
    mention appreciation;
};