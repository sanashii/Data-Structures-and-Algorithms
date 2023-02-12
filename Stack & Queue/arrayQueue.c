#include<stdio.h>
#include<Windows.h>

typedef struct{
	int qNum;
	char purpose;
	int priority;
}Queue;

void getNum(Queue *queue[], int *ctr);
void printTicket(Queue *queue, int ctr);
void displayNext(Queue *q);
void displayAll(Queue *q, int curMax);

int main(){
	Queue *q;
	q = (Queue *)calloc(50, sizeof(Queue));
	int ctr = 1, input, input2;
	char choice;
	mark:
	printf("Welcome to Simp Services!\n\t[1] Get a number\n\t[2] Display Next\n\t[3] Display All\nSelect an option: ");
	scanf("%d", &input);
	switch(input){
		case 1:
			printf("\n\nMENU:\n\t[1] Loan simp points\n\t[2] Pay your simp debts\n\t[3] Inquire about simp points\nChoose your fighter: ");
			scanf("%d", &input2);
			switch(input2){
				case 1:
					q[ctr - 1].qNum = ctr;
					q[ctr - 1].purpose = 'L';
					printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
					scanf(" %c", &choice);
					if(choice == 'Y' || choice == 'y'){
						q[ctr - 1].priority = 1;
					}else if(choice == 'N' || choice == 'n'){
						q[ctr - 1].priority = 0;
					}
					break;
				case 2:
					q[ctr - 1].qNum = ctr;
					q[ctr - 1].purpose = 'P';
					printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
					scanf(" %c", &choice);
					if(choice == 'Y' || choice == 'y'){
						q[ctr - 1].priority = 1;
					}else if(choice == 'N' || choice == 'n'){
						q[ctr - 1].priority = 0;
					}
					break;
				case 3:
					q[ctr - 1].qNum = ctr;
					q[ctr - 1].purpose = 'I';
					printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
					scanf(" %c", &choice);
					if(choice == 'Y' || choice == 'y'){
						q[ctr - 1].priority = 1;
					}else if(choice == 'N' || choice == 'n'){
						q[ctr - 1].priority = 0;
					}
					break;
			}
			system("cls");
			printTicket(q, ctr - 1);
			ctr++;
			break;
			
		case 2: //print next queue
			displayNext(q);
			break;
			
		case 3: // print all queue
			displayAll(q, ctr);
			break;
	}
	goto mark;
	
	return 0;
}

void printTicket(Queue *queue, int ctr){
	printf("\n\n====== TICKET ======");
	printf("\nQueue Number: %d", ctr + 1);
	if(queue[ctr].purpose == 'L'){
		printf("\nPurpose of Visit: Loan for simp points");
	}else if(queue[ctr].purpose == 'P'){
		printf("\nPurpose of Visit: Payment for simp points");
	}else if(queue[ctr].purpose == 'I'){
		printf("\nPurpose of Visit: Inquiry about simp points");
	}
	if(queue[ctr].priority == 0){
		printf("\nPriority Lane or Regular Lane: R\n\n");
	}else if(queue[ctr].priority == 1){
		printf("\nPriority Lane or Regular Lane: P\n\n");
	}
}

void displayNext(Queue *q){ //! to fix priority display
	// 3 for loops for loans, inquiries, and payments?
	int ctr;
	for(ctr = 0; ctr < 50; ctr++){
		if(q[ctr].purpose == 'L'){
			if(q[ctr].priority == 1){
				printf("\nLoans: %d (Priority)\n\n", q[ctr].qNum);
				break;
			}
		}
		
		if(q[ctr].purpose == 'P'){
			if(q[ctr].priority == 1){
				printf("\nPayments: %d (Priority)\n\n", q[ctr].qNum);
				continue;
			}
		}
		
		if(q[ctr].purpose == 'I'){
			if(q[ctr].priority == 1){
				printf("\nInquiries: %d (Priority)\n\n", q[ctr].qNum);
				continue;
			}
		}
	}
	// how do we print the regular ones after the priority ppl are done?
	// do i need 3 arrays jd? hmm 
}

void displayAll(Queue *q, int curMax){
	int ctr;
	printf("\tQUEUE NUMBER\t|\t\tPRUPOSE\t\t|\t\tPRIORITY\n");
	for(ctr = 0; ctr < curMax - 1; ctr++){
		printf("\t%d\t\t|\t\t%c\t\t|\t\t%d\n", q[ctr].qNum, q[ctr].purpose, q[ctr].priority);
	}
}

/* FIX THIS PARA LIMPYO ANG MAIN BOGWIT KA
void getNum(Queue **queue, int *ctr){
	int input;
	char choice;
	printf("\n\nMENU:\n\t[1] Loan simp points\n\t[2] Pay your simp debts\n\t[3] Inquire about simp points\nChoose your fighter: ");
	scanf("%d", &input);
	switch(input){
		case 1:
			queue[*ctr - 1]->qNum = ctr;
			queue[*ctr - 1]->purpose = 'L';
			printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
			scanf(" %c", &choice);
			if(choice == 'Y' || choice == 'y'){
				queue[*ctr - 1]->priority = 1;
			}else{
				queue[*ctr - 1]->priority = 0;
			}
			break;
		case 2:
			queue[*ctr - 1]->qNum = ctr;
			queue[*ctr - 1]->purpose = 'P';
			printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
			scanf(" %c", &choice);
			if(choice == 'Y' || choice == 'y'){
				queue[*ctr - 1]->priority = 1;
			}else if(choice == 'N' || choice == 'n'){
				queue[*ctr - 1]->priority = 0;
			}
			break;
		case 3:
			queue[*ctr - 1]->qNum = ctr;
			queue[*ctr - 1]->purpose = 'I';
			printf("Are you a PWD, Senior Citizen, or a Pregnant person? [Y/N]: ");
			scanf("%c", &choice);
			if(choice == 'Y' || choice == 'y'){
				queue[*ctr - 1]->priority = 1;
			}else if(choice == 'N' || choice == 'n'){
				queue[*ctr - 1]->priority = 0;
			}
			break;
	}
} */



















