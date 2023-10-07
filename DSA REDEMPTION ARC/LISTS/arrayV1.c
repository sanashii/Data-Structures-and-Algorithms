#include<stdio.h>
#include<string.h>
#define MAX 5
// VERSION 1 ADT LIST IMPLEMENTATION //
typedef struct node{
    char LName[16];
    char FName[24];
    char MI;
}Names;

typedef struct student{
    Names name;
    char ID[9];
    char course[24];
    int year;
}Studrec;

typedef struct list{
    Studrec stud[MAX];
    int count;
}LIST;

// OPERATIONS:
LIST initList(LIST L);
void insert(LIST *L, char *lname, char *fname, char MI, char *ID, char *course, int year);
void shift(Studrec *a, Studrec *b);
void delete(LIST *L, char *IDtoDelete);
int locate(LIST L, char *lnameToLocate); // returns the index of the student's info in the record
Studrec retrieve(LIST L, char *ID);
void makeNull(LIST *L);
void printList(LIST L);

int main(){
    LIST L = initList(L);
    insert(&L, "Lindsay", "Caitlin", 'M', "21035116", "Computer Science", 3);
    insert(&L, "Barcena", "Thea", 'P', "35477621", "Optemetry", 3);
    insert(&L, "Baulita", "Andrea", 'M', "21100883", "Computer Science", 3);
    insert(&L, "Bacus", "James", 'V', "20311459", "Computer Science", 3);
    insert(&L, "Beagle", "Bailey", 'M', "34517621", "Vet Med", 1);
    insert(&L, "Dupe", "Loopie", 'L', "00000000", "IT", 2);
    printList(L);

    printf("\n================ LIST AFTER DELETION ====================");
    delete(&L, "35477621");
    delete(&L, "3451762");
    printList(L);

    printf("\nLocating student 'Barcena'... %d", locate(L, "Barcena"));
    printf("\nLocating student 'Beagle'... %d\n", locate(L, "Beagle"));    

    Studrec stud = retrieve(L, "3451761");
    printf("\nStudent ID:\t %s", stud.ID);
    printf("\nStudent name:\t %s %c %s", stud.name.FName, stud.name.MI, stud.name.LName);
    printf("\nCourse:\t\t %s", stud.course);
    printf("\nYear Level:\t %d\n\n", stud.year);

    makeNull(&L);
    printList(L);

    return 0; 
}

LIST initList(LIST L){
    L.count = 0;
    return L;
}

void insert(LIST *L, char *lname, char *fname, char MI, char *studID, char *studCourse, int studYear){ // can be improved by using a studrec instead of individual vars
    if(L->count < MAX){
        strcpy(L->stud[L->count].name.LName, lname);
        strcpy(L->stud[L->count].name.FName, fname);
        L->stud[L->count].name.MI = MI;
        strcpy(L->stud[L->count].ID, studID);
        strcpy(L->stud[L->count].course, studCourse);
        L->stud[L->count].year = studYear;
        L->count++;
    }else{
        printf("\nList is full! Can no longer add the student.");
    }
}

void shift(Studrec *a, Studrec *b){
    *a = *b;
}

void delete(LIST *L, char *IDtoDelete){
    int ctr;
    for(ctr = 0; ctr < L->count && strcmp(L->stud[ctr].ID, IDtoDelete) != 0; ctr++){}
    if(ctr == L->count){
        printf("\nSTUDENT DOES NOT EXIST!");
    }else{
        for(int ctr1 = ctr; ctr1 < L->count; ctr1++){
            shift(&L->stud[ctr1], &L->stud[ctr1 + 1]);
        }
         L->count--;
    }
}

int locate(LIST L, char *lnameToLocate){
    int ctr, retVal = 1;
    for(ctr = 0; ctr < L.count && strcmp(L.stud[ctr].name.LName, lnameToLocate) != 0; ctr++){}
    if(ctr == L.count){
        printf("\nSTUDENT IS NOT FOUND IN THE RECORD!\n");
        retVal = 0;
    }
    return retVal;
}

void makeNull(LIST *L){
    L->count = 0; // do we make the list empty like this or?
}

Studrec retrieve(LIST L, char *ID){
    Studrec studRet = {{"XXX", "XXXXX", 'X'}, "00000000", "XX", 0};
    int ctr;
    for(ctr = 0; ctr < L.count && strcmp(L.stud[ctr].ID, ID) != 0; ctr++){}
    if(ctr == L.count){
        printf("\nSTUDENT DOES NOT EXIT!\n");
    }else{
        studRet = L.stud[ctr];
    }
    return studRet;
}

void printList(LIST L){
    int ctr;
    if(L.count == 0){
        printf("\nLIST IS EMPTY!\n");
    }else{
        for(ctr = 0; ctr < L.count; ctr++){
        printf("\nStudent ID:\t %s", L.stud[ctr].ID);
        printf("\nStudent name:\t %s %c %s", L.stud[ctr].name.FName, L.stud[ctr].name.MI, L.stud[ctr].name.LName);
        printf("\nCourse:\t\t %s", L.stud[ctr].course);
        printf("\nYear Level:\t %d\n\n", L.stud[ctr].year);
    }
    }
}