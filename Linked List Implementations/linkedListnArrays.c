#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#define SIZE 10

typedef struct{ // student struct definition
	char fName[24], MI, lName[16];
	unsigned int ID;
	char course[8];
	int yearLvl;
}studtype;

typedef struct node{ // linked list implementation
	studtype stud;
	struct node *link;
}*LinkedList;

typedef struct{ // adt list (via array of structs)
	studtype stud[SIZE];
	int count;
}ArrayList;


void displayArrayList(ArrayList arr){
	int ctr;
	if(arr.count == 0){
		printf("Original list is now empty. Everything has been added and sorted into their respective linked list.");
	}else{
		printf("\n---------------------------- ORIGINAL LIST ----------------------------\n");
		printf("%-16s%-10s%-16s%-8s\t%-10s%-8s\n", "First Name", "MI", "Last Name", "ID", "Course", "Year");
		for(ctr = 0; ctr < arr.count; ctr++){ // to recreate in tabular form
			printf("%-16s%-10c%-16s%-8u\t%-10s%-8d\n", arr.stud[ctr].fName, arr.stud[ctr].MI, arr.stud[ctr].lName, arr.stud[ctr].ID, arr.stud[ctr].course, arr.stud[ctr].yearLvl);
		}
		printf("\nList count: %d", arr.count);
	}
}

void deleteStud(ArrayList *arr, int *index){
    int ctr;
    for(ctr = *index; ctr < arr->count; ctr++){
        arr->stud[ctr] = arr->stud[ctr + 1];
    }
    arr->count -= 1;
    *index -= 1;
}

void displayLinkedList(LinkedList list){
	LinkedList cur = list;
	printf("%-16s%-10s%-16s%-8s\t%-10s%-8s\n", "First Name", "MI", "Last Name", "ID", "Course", "Year");
	do{
		printf("%-16s%-10c%-16s%-8u\t%-10s%-8d\n", cur->stud.fName, cur->stud.MI, cur->stud.lName, cur->stud.ID, cur->stud.course, cur->stud.yearLvl);
		cur = cur->link;
	}while(cur != NULL);
}

void sortLinkedList(LinkedList list){
    int swapped;
    LinkedList ptr1, ptr2 = NULL;
    studtype temp;
    if (list == NULL){
        return;
	}
	
    do {
        swapped = 0;
        ptr1 = list;

        while (ptr1->link != ptr2) {
            if (strcmp(ptr1->stud.lName, ptr1->link->stud.lName) > 0) {
                temp = ptr1->stud;
                ptr1->stud = ptr1->link->stud;
                ptr1->link->stud = temp;
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        ptr2 = ptr1;
    } while (swapped);
}

int main(){
    ArrayList arr = {{0}};
	LinkedList comsci = NULL, it = NULL, ict = NULL, math = NULL;
	int ctr, flag = 1, ctr1;
	for(ctr = 0; ctr < SIZE; ctr++){
		printf("Enter student's full name: ");
		scanf("%s %c %s", arr.stud[ctr].fName, &arr.stud[ctr].MI, arr.stud[ctr].lName);
		printf("Enter ID number: ");
		scanf("%u", &arr.stud[ctr].ID);
		printf("Enter course & year: ");
		scanf("%s %d", arr.stud[ctr].course, &arr.stud[ctr].yearLvl);
		printf("\n");
		arr.count++;
	}
	system("cls");
	displayArrayList(arr);

    do{
        LinkedList temp = NULL, cur = NULL;
        printf("\n\n------ MENU ------\n\t[1] Sort by BS CS\n\t[2] Sort by BS IT\n\t[3] Sort by BS ICT\n\t[4] Sort by BS Math\n\t[5] View original List\n\t[6] View linked list based on their course\n\t[7] Exit\nSelect an option: ");
		int choice;
		scanf("%d", &choice);
        switch(choice){
            case 1:
                system("cls");
                ctr1 = 0;
                for(ctr = 0; ctr < arr.count; ctr++){
                    if(strcmp("BSCS", arr.stud[ctr].course) == 0){
                        printf("\nStudent %s belongs to CS", arr.stud[ctr].fName);
                        studtype stud = arr.stud[ctr];
                        temp = (LinkedList)malloc(sizeof(struct node));
                        temp->link = NULL;
                        temp->stud = stud;
                        if(ctr1 == 0){
                            comsci = temp;
                            cur = comsci;
                        }else{
                            cur->link = temp;
                            cur = temp;
                        }
                        deleteStud(&arr, &ctr);
                        ctr1++;
                    }
                }
                sortLinkedList(comsci);
                printf("\n===== Successfully sorted the CS students =====\n");
                break;
            case 2:
                system("cls");
                ctr1 = 0;
                for(ctr = 0; ctr < arr.count; ctr++){
                    if(strcmp("BSIT", arr.stud[ctr].course) == 0){
                        printf("\nStudent %s belongs to IT", arr.stud[ctr].fName);
                        studtype stud = arr.stud[ctr];
                        temp = (LinkedList)malloc(sizeof(struct node));
                        temp->link = NULL;
                        temp->stud = stud;
                        if(ctr1 == 0){
                            it = temp;
                            cur = it;
                        }else{
                            cur->link = temp;
                            cur = temp;
                        }
                        deleteStud(&arr, &ctr);
                        
                        ctr1++;
                    }
                }
                sortLinkedList(it);
                printf("\n===== Successfully sorted the IT students =====\n");
                break;
            case 3:
                system("cls");
                ctr1 = 0;
                for(ctr = 0; ctr < arr.count; ctr++){
                    if(strcmp("BSICT", arr.stud[ctr].course) == 0){
                        printf("\nStudent %s belongs to ICT", arr.stud[ctr].fName);
                        studtype stud = arr.stud[ctr];
                        temp = (LinkedList)malloc(sizeof(struct node));
                        temp->link = NULL;
                        temp->stud = stud;
                        if(ctr1 == 0){
                            ict = temp;
                            cur = ict;
                        }else{
                            cur->link = temp;
                            cur = temp;
                        }
                        deleteStud(&arr, &ctr);
                        ctr1++;
                    }
                }
                sortLinkedList(ict);
                printf("\n===== Successfully sorted the ICT students =====\n");
                break;
            case 4:
                system("cls");
                ctr1 = 0;
                for(ctr = 0; ctr < arr.count; ctr++){
                    if(strcmp("BSMath", arr.stud[ctr].course) == 0){
                        printf("\nStudent %s belongs to Math", arr.stud[ctr].fName);
                        studtype stud = arr.stud[ctr];
                        temp = (LinkedList)malloc(sizeof(struct node));
                        temp->link = NULL;
                        temp->stud = stud;
                        if(ctr1 == 0){
                            math = temp;
                            cur = math;
                        }else{
                            cur->link = temp;
                            cur = temp;
                        }
                        deleteStud(&arr, &ctr);
                        ctr1++;
                    }
                }
                sortLinkedList(math);
                printf("\n===== Successfully sorted the Math students =====\n");
                break;
            case 5:
                system("cls");
                displayArrayList(arr);
                break;
            case 6:
                system("cls");
                printf("\n--------------------------- COMPUTER SCIENCE ---------------------------\n");
                displayLinkedList(comsci);
				printf("\n------------------------- INFORMATION TECHNOLOGY -------------------------\n");
                displayLinkedList(it);
				printf("\n------------------------ INFO & COMMS TECHNOLOGY ------------------------\n");
                displayLinkedList(ict);
                printf("\n-------------------------------- MATH --------------------------------\n");
                displayLinkedList(math);
                break;
            case 7:
                flag--;
                break;
            
            default:
                printf("Invalid input. Try again.");
        }
    }while(flag);

    return 0; 
}