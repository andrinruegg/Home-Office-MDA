#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


void initFamily(Tperson *myFamily){
    Tperson firstPerson = {"John", "Doe", 1981, 91, 196, "FC Barelona"};
    Tperson secondPerson = {"Jane", "Doe", 1980, 64, 178, "Real Madrid"};
    Tperson thirdPerson = {"Jack", "Doe", 2008, 40, 163, "FC Zuerich"};
    Tperson fourthPerson = {"Judy", "Doe", 2015, 30, 124, "SC Siebnen"};

    myFamily[0] = firstPerson;
    myFamily[1] = secondPerson;
    myFamily[2] = thirdPerson;
    myFamily[3] = fourthPerson;
}

void printFamily(const Tperson *myFamily, int familySize) {
    for (int i = 0; i < familySize; i++) {
        printf("Name: %s %s\n", myFamily[i].firstname, myFamily[i].lastname);
        printf("Birthyear: %d\n", myFamily[i].birthyear);
        printf("Weight: %d\n", myFamily[i].weight);
        printf("Height: %d\n", myFamily[i].height);
        printf("Favorite Sports Club: %s\n", myFamily[i].favoriteSportClub);
        printf("\n");
    }
}

void printPerson(const Tperson *person) {
    printf("Name: %s %s\n", person->firstname, person->lastname);
    printf("Birthyear: %d\n", person->birthyear);
    printf("Weight: %d\n", person->weight);
    printf("Height: %d\n", person->height);
    printf("Favorite Sports Club: %s\n", person->favoriteSportClub);
    printf("\n");
}

void sortbyAge(Tperson *myFamily, int familySize) {
    Tperson temp;
    for (int i = 0; i < familySize - 1; i++) {
        for (int j = 0; j < familySize - i - 1; j++) {
            if (myFamily[j].birthyear > myFamily[j + 1].birthyear) {
                temp = myFamily[j];
                myFamily[j] = myFamily[j + 1];
                myFamily[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < familySize; i++){
        printf("Name: %s", myFamily[i].firstname);
        printf(" %s\n", myFamily[i].lastname);
        printf("Birthyear: %d\n", myFamily[i].birthyear);
        printf("Weight: %d\n", myFamily[i].weight);
        printf("Height: %d\n", myFamily[i].height);
        printf("Favorite Sports Club: %s\n", myFamily[i].favoriteSportClub);
        printf("\n");
    }

}

void sortbyWeight(Tperson *myFamily, int familySize) {
    Tperson temp;
    for (int i = 0; i < familySize - 1; i++) {
        for (int j = 0; j < familySize - i - 1; j++) {
            if (myFamily[j].weight > myFamily[j + 1].weight) {
                temp = myFamily[j];
                myFamily[j] = myFamily[j + 1];
                myFamily[j + 1] = temp;
            }
        }
    }

    for(int i = 3; i > -1; i--){
        printf("Name: %s", myFamily[i].firstname);
        printf(" %s\n", myFamily[i].lastname);
        printf("Birthyear: %d\n", myFamily[i].birthyear);
        printf("Weigth: %d\n", myFamily[i].weight);
        printf("Height: %d\n", myFamily[i].height);
        printf("Favorite Sports Club: %s\n", myFamily[i].favoriteSportClub);
        printf("\n");
    }

}

void sortbyHeight(Tperson *myFamily, int familySize) {
    Tperson temp;
    for (int i = 0; i < familySize - 1; i++) {
        for (int j = 0; j < familySize - i - 1; j++) {
            if (myFamily[j].height > myFamily[j + 1].height) {
                temp = myFamily[j];
                myFamily[j] = myFamily[j + 1];
                myFamily[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < familySize; i++) {
        printf("Name: %s %s\n", myFamily[i].firstname, myFamily[i].lastname);
        printf("Birthyear: %d\n", myFamily[i].birthyear);
        printf("Weight: %d\n", myFamily[i].weight);
        printf("Height: %d\n", myFamily[i].height);
        printf("Favorite Sports Club: %s\n", myFamily[i].favoriteSportClub);
        printf("\n");
    }

}

void findOldestFamilyMember(const Tperson *myFamily, int familySize) {
    int oldestIndex = 0;
    int oldestYear = myFamily[0].birthyear;

    for (int i = 1; i < familySize; i++) {
        if (myFamily[i].birthyear < oldestYear) {
            oldestYear = myFamily[i].birthyear;
            oldestIndex = i;
        }
    }

    printf("The oldest family member is:\n");
    printPerson(&myFamily[oldestIndex]);
}

void printRandomPerson(const Tperson *myFamily, int familySize) {
    srand(time(NULL));
    int randomIndex = rand() % familySize;
    printf("Random family member details:\n");
    printPerson(&myFamily[randomIndex]);
}

int main(){
    char answer;
    char answer2;

    Tperson myFamily[4];

    initFamily(myFamily);

    printf("Do you want to sort the family or not? (y/n)\n");
    scanf(" %c", &answer);
    if(answer == 'y'){
        printf("What do you want to sort the family by?\n");
        printf("1. Age\n2. Weight\n3. Height\n");
        scanf(" %d", &answer2);
        printf("\n");
        switch (answer2){
            case 1:
                sortbyAge(myFamily, 4);
                break;

            case 2:
                sortbyWeight(myFamily, 4);
                break;

            case 3:
                sortbyHeight(myFamily, 4);
                break;
        }
    }else{
        printFamily(myFamily, 4);
    }

    return 0;
}