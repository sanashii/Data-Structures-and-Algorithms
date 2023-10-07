#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct names{
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

typedef struct node{
    Studrec stud;
    struct node *link;
}*Studlist;

Studlist initList(Studlist stud);
void insertFirst(Studlist *S, Studrec student); 
void insertLast(Studlist *S, Studrec student); 
void delete(Studlist *S, char *IDtoDelete);
int locate(Studlist S, char *IDtoLocate);
Studrec retrieve(Studlist S,  char *studID);
void makeNull(Studlist *S);
void sortList(Studlist S);
void printList(Studlist S);

int main(){
    Studlist S = initList(S);
    Studrec student1 = {{"Lindsay", "Caitlin", 'L'}, "21035116", "Computer Science", 3};
    Studrec student2 = {{"Barcena", "Thea", 'P'}, "10089665", "Optometry", 3};
    Studrec student3 = {{"Bacus", "James", 'V'}, "21254757", "Computer Science", 2};
    Studrec student4 = {{"Baulita", "Andrea", 'M'}, "21100883", "Computer Science", 2};
    Studrec student5 = {{"Beagle", "Bailey", 'M'}, "00011554", "Vet Med", 1};
    
    //insertFirst(&S, student4);
    insertFirst(&S, student1);
    insertLast(&S, student2);
    insertLast(&S, student3);
    insertFirst(&S, student4);
    insertLast(&S, student5);

    printf("\n=== LIST AFTER INSERTING FIRST AND LAST ===\n");
    printList(S);

    printf("\n=== LIST AFTER DELETING '10089665' OR THEA & NON-EXISTENT ID ===\n");
    delete(&S, "10089665");
    delete(&S, "lobot");
    printList(S);

    printf("\n=== LIST AFTER LOCATING '00011554' AND NON-EXISTENT ID ===\n");
    locate(S, "10089665");
    locate(S, "00011554");
    printList(S);

    printf("\n=== LIST AFTER retrieving '00011554' AND NON-EXISTENT ID ===\n");
    Studrec tempstud;
    tempstud = retrieve(S, "10089665");
    printf("\nStudent ID:\t %s", tempstud.ID);
    printf("\nStudent name:\t %s %c %s", tempstud.name.FName, tempstud.name.MI, tempstud.name.LName);
    printf("\nCourse:\t\t %s", tempstud.course);
    printf("\nYear Level:\t %d\n\n", tempstud.year);
    tempstud = retrieve(S, "00011554");
    printf("\nStudent ID:\t %s", tempstud.ID);
    printf("\nStudent name:\t %s %c %s", tempstud.name.FName, tempstud.name.MI, tempstud.name.LName);
    printf("\nCourse:\t\t %s", tempstud.course);
    printf("\nYear Level:\t %d\n\n", tempstud.year);
    
    printf("\n=== LIST AFTER SORTING BASED ON FNAME ===\n");
    printList(S);

    return 0;
}

Studlist initList(Studlist stud){
    return stud = NULL;
}

void insertFirst(Studlist *S, Studrec student){
    Studlist temp;
    temp = (Studlist)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = student;
        temp->link = NULL;
        if(*S == NULL){
            (*S) = temp;
        }else{
            temp->link = *S;
            *S = temp;
            //free(temp);
        }
    }
}

void insertLast(Studlist *S, Studrec student) {
    Studlist *trav, temp;
    for(trav = S; *trav != NULL; trav = &(*trav)->link){}
    if(*trav == NULL){
        temp = (Studlist)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->stud = student;
            temp->link = NULL;
            *trav = temp; 
        }
    }
}


void delete(Studlist *S, char *IDtoDelete){
    Studlist *trav, temp;
    for(trav = S; *trav != NULL && strcmp((*trav)->stud.ID, IDtoDelete) != 0; trav = &(*trav)->link){}
    if(*trav == NULL){
        printf("\n----- STUDENT %s NOT FOUND! -----\n", IDtoDelete);
    }else{
        if((*trav)->link != NULL){
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }else{ // if its at the end of the lists
            (*trav)->link = NULL;
        }
    }
}

int locate(Studlist S, char *IDtoLocate){ // using PN 
    Studlist trav;
    int ctr = 0;
    for(trav = S; trav->link != NULL && strcmp(trav->stud.ID, IDtoLocate) != 0; trav = trav->link, ctr++){}
    if(trav->link == NULL && strcmp(trav->stud.ID, IDtoLocate) != 0){
        printf("\n--- STUDENT %s NOT FOUND / DOESN'T EXIST! ---\n", IDtoLocate);
    }else{
        printf("\n--- STUDENT %s FOUND AT INDEX %d ---\n", IDtoLocate, ctr);
    }
}

Studrec retrieve(Studlist S, char *studID){
    Studlist trav;
    Studrec temp = {{"XXXXXX", "XXXXXX", 'X'}, "XXXXX", "XXXXXX", -1};
    for(trav = S; trav->link != NULL && strcmp(trav->stud.ID, studID) != 0; trav = trav->link){}
    if(trav->link == NULL && strcmp(trav->stud.ID, studID) != 0){
        printf("\n--- STUDENT %s NOT FOUND / DOESN'T EXIST! ---\n", studID);
    }else{
        temp = trav->stud;
    }

    return temp;
}

void makeNull(Studlist *S){
    *S = NULL;
}

void sortList(Studlist S){
    
}

void printList(Studlist S){
    Studlist trav;
    for(trav = S; trav != NULL; trav = trav->link){ //! CM: the condition of trav->link != NULL wont print the very last bc of this condition
        printf("\nStudent ID:\t %s", trav->stud.ID);
        printf("\nStudent name:\t %s %c %s", trav->stud.name.FName, trav->stud.name.MI, trav->stud.name.LName);
        printf("\nCourse:\t\t %s", trav->stud.course);
        printf("\nYear Level:\t %d\n\n", trav->stud.year);
    }
}