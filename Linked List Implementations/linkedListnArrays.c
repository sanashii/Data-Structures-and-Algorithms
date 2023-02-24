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

void deleteStud(ArrayList *arr, int index);
void sortLinkedList(LinkedList list);
void displayArrayList(ArrayList arr);
void displayLinkedList(LinkedList comsci);

int main(){
	ArrayList arr = {{0}};
	LinkedList temp, cur, comsci = NULL, it = NULL, ict = NULL, math = NULL;
	int ctr, flag = 1;
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
	
	// start of menu sorting
	do{
		printf("\n\n------ MENU ------\n\t[1] Sort by BS CS\n\t[2] Sort by BS IT\n\t[3] Sort by BS ICT\n\t[4] Sort by BS Math\n\t[5] View original List\n\t[6] Exit\nSelect an option: ");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				for(ctr = arr.count - 1; ctr >= 0; ctr--){
					if(strcmp("BSCS", arr.stud[ctr].course) == 0){
						temp = (LinkedList)malloc(sizeof(struct node));
						strcpy(temp->stud.fName, arr.stud[ctr].fName);
						temp->stud.MI = arr.stud[ctr].MI;
						strcpy(temp->stud.lName, arr.stud[ctr].lName);
						temp->stud.ID = arr.stud[ctr].ID;
						strcpy(temp->stud.course, arr.stud[ctr].course);
						temp->stud.yearLvl = arr.stud[ctr].yearLvl;
						temp->link = NULL;
						if(ctr == arr.count - 1){
							comsci = temp;
							cur = comsci;
						}else{
							cur->link = temp;
							cur = temp;
						}
						deleteStud(&arr, ctr);
					}
				}
				printf("\n--------------------------- COMPUTER SCIENCE ---------------------------\n");
				sortLinkedList(comsci);

				break;
			case 2:
				for(ctr = arr.count - 1; ctr >= 0; ctr--){
					if(strcmp("BSIT", arr.stud[ctr].course) == 0){
						temp = (LinkedList)malloc(sizeof(struct node));
						strcpy(temp->stud.fName, arr.stud[ctr].fName);
						temp->stud.MI = arr.stud[ctr].MI;
						strcpy(temp->stud.lName, arr.stud[ctr].lName);
						temp->stud.ID = arr.stud[ctr].ID;
						strcpy(temp->stud.course, arr.stud[ctr].course);
						temp->stud.yearLvl = arr.stud[ctr].yearLvl;
						temp->link = NULL;
						if(ctr == arr.count - 1){
							it = temp;
							cur = it;
						}else{
							cur->link = temp;
							cur = temp;
						}
						deleteStud(&arr, ctr);
					}
				}
				printf("\n------------------------- INFORMATION TECHNOLOGY -------------------------\n");
				sortLinkedList(it);

				break;
			case 3:
				for(ctr = arr.count - 1; ctr >= 0; ctr--){
					if(strcmp("BSICT", arr.stud[ctr].course) == 0){
						temp = (LinkedList)malloc(sizeof(struct node));
						strcpy(temp->stud.fName, arr.stud[ctr].fName);
						temp->stud.MI = arr.stud[ctr].MI;
						strcpy(temp->stud.lName, arr.stud[ctr].lName);
						temp->stud.ID = arr.stud[ctr].ID;
						strcpy(temp->stud.course, arr.stud[ctr].course);
						temp->stud.yearLvl = arr.stud[ctr].yearLvl;
						temp->link = NULL;
						if(ctr == arr.count - 1){
							ict = temp;
							cur = ict;
						}else{
							cur->link = temp;
							cur = temp;
						}
						deleteStud(&arr, ctr);
					}
				}
				printf("\n------------------------ INFO & COMMS TECHNOLOGY ------------------------\n");
				sortLinkedList(ict);

				break;
			case 4:
				for(ctr = arr.count - 1; ctr >= 0; ctr--){
					if(strcmp("BSMath", arr.stud[ctr].course) == 0){
						temp = (LinkedList)malloc(sizeof(struct node));
						strcpy(temp->stud.fName, arr.stud[ctr].fName);
						temp->stud.MI = arr.stud[ctr].MI;
						strcpy(temp->stud.lName, arr.stud[ctr].lName);
						temp->stud.ID = arr.stud[ctr].ID;
						strcpy(temp->stud.course, arr.stud[ctr].course);
						temp->stud.yearLvl = arr.stud[ctr].yearLvl;
						temp->link = NULL;
						if(ctr == arr.count - 1){
							math = temp;
							cur = math;
						}else{
							cur->link = temp;
							cur = temp;
						}
						deleteStud(&arr, ctr);
					}
				}
				printf("\n-------------------------------- MATH --------------------------------\n");
				sortLinkedList(math);

				break;
			case 5:
				displayArrayList(arr);
				break;
			case 6:
				flag = 0;
				break;
			default:
				printf("Invalid input. Try again.");
		};
	}while(flag);
	free(cur);
	free(temp); 
	return 0;
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
	displayLinkedList(list);
}


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

void displayLinkedList(LinkedList comsci){
	LinkedList cur = comsci;
	printf("%-16s%-10s%-16s%-8s\t%-10s%-8s\n", "First Name", "MI", "Last Name", "ID", "Course", "Year");
	do{
		printf("%-16s%-10c%-16s%-8u\t%-10s%-8d\n", cur->stud.fName, cur->stud.MI, cur->stud.lName, cur->stud.ID, cur->stud.course, cur->stud.yearLvl);
		cur = cur->link;
	}while(cur != NULL);
}

void deleteStud(ArrayList *arr, int index) {
    if (index < 0 || index >= arr->count) {
        return;
    }

    for (int i = index; i < arr->count - 1; i++) {
        arr->stud[i] = arr->stud[i + 1];
    }

    memset(&arr->stud[arr->count - 1], 0, sizeof(studtype));
    arr->count--;
}


