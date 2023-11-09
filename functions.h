#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct {
    char firstname[41];
    char lastname[41];
    unsigned int birthyear;
    unsigned int weight;
    unsigned int height;
    char favoriteSportClub[41];
} Tperson;

void initFamily(Tperson *myFamily);
void printFamily(const Tperson *myFamily, int familySize);
void printPerson(const Tperson *person);
void sortbyAge(Tperson *myFamily, int familySize);
void sortbyWeight(Tperson *myFamily, int familySize);
void sortbyHeight(Tperson *myFamily, int familySize);
void findOldestFamilyMember(const Tperson *myFamily, int familySize);
void printRandomPerson(const Tperson *myFamily, int familySize);

#endif