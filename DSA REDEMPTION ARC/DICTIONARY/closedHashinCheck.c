#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 23
#define EMPTY 0
#define DELETED -1

typedef int Set[SIZE];
typedef int Dictionary[SIZE];
typedef enum {TRUE,FALSE} boolean;

//Functions
int hashVal(int);
void initHashTable(Dictionary);
void displayHashTable(Dictionary);
void insert(Dictionary,Set,int);
boolean isMember(Dictionary,int);
void deleteELEM(Dictionary, int);
void deleteElemSet(Dictionary, Set, int);

int main() {
  Dictionary numTab;
  int S[] = { 4057, 3042, 3205,  848, 1864, 987, 3082,  414, 1728, 1400, 1223, 2710, 2486, 2885, 1192, 4057 };
  int length = sizeof(S)/sizeof(*S);
  initHashTable(numTab);
  insert(numTab,S,length);
  displayHashTable(numTab);
  
  int num = 4365;
  int num1 = 4563;
  
   //printf("hash value: %d \n", hashVal(S[1]));
   
  if(isMember(numTab,num)==TRUE){
  	 printf("%d is a member:  of the Table.\n\n",num);  
  }else{
  	printf("%d is not a member\n\n",num);
  }
  
  deleteELEM(numTab,num1);
  
  displayHashTable(numTab);
  
  int C[] = {4057, 3205, 1728, 2486, 1192, 5595};
  int length2 = sizeof(C)/sizeof(*C);
  deleteElemSet(numTab, C, length2);
  
  displayHashTable(numTab);
  
  int B[] = {1400, 5595,  121,  139, 1532,  596, 2800, 1167,  213};
  int length1 = sizeof(B)/sizeof(*B);
  insert(numTab,B,length1);
  
  displayHashTable(numTab);

  return 0;
}

int hashVal(int val){
    int temp,retval=0;
    for(temp=0;temp<4;temp++){
      retval = retval+(val%10);
      val =val/10;
    }
    return retval%23;
}

void initHashTable(Dictionary D){
    int temp;
    for(temp = 0;temp<SIZE;temp++){
        D[temp]=EMPTY;
    }
}

void displayHashTable(Dictionary D){
    printf("\nIndex   Content    Hash Value  Search Length\n");
    int temp;
    for(temp=0;temp<SIZE;temp++){
        printf("    %d",temp);
        if(D[temp] == EMPTY){
            printf("    EMPTY");
        }else if(D[temp] == DELETED){
            printf("    DELETED");
        }else{
            printf("    %d",D[temp]);
        }
        if(D[temp]!=EMPTY&&D[temp]!=DELETED){
            printf("          %d",hashVal(D[temp]));
            printf("          %d",temp-hashVal(D[temp])+1);
        }
        printf("\n");
    } 
    printf("\n");
}

boolean isMember(Dictionary D,int val){
    boolean retval;
    int hash = hashVal(val), temp;
    if(D[hash]!=val){
      for(temp = hash+1;temp!=hash && D[temp]!=val;temp = (temp+1)%SIZE){}
      retval = (temp!=hash)?TRUE:FALSE;
    }else{
      retval = TRUE;
    }
    return retval;
}

void insert(Dictionary D,Set Sval,int size){
    int temp,hash,arrSize;
    for(temp=0;temp<size;temp++){
        hash = hashVal(Sval[temp]);
        if(isMember(D,Sval[temp])!=TRUE){
          for(;D[hash]!=EMPTY&&D[hash]!=DELETED;hash = (hash+1)%SIZE){}
          D[hash]=Sval[temp];
        }
    }
}

void deleteELEM(Dictionary D, int val){
	int hash = hashVal(val),temp;
	if(D[hash]!=val){
		for(temp=hash+1;temp!=hash&&D[temp]!=val;temp =(temp+1)%SIZE){}
		if(D[temp]==val){
			D[temp]=DELETED;
			printf("%d has been deleted.\n",val);
		}else{
			printf("The number %d is not found in the dictionary.\n",val);
		}
	}else{
		printf("%d has been deleted.\n",val);
		D[hash]=DELETED;
	}
}

void deleteElemSet(Dictionary D, Set Sval, int size){
	int temp, trav;
	for(temp = 0; temp<size;temp++){
		int hash = hashVal(Sval[temp]);
		if(D[hash]!=Sval[temp]){
			for(trav=hash+1;trav!=hash&&D[trav]!=Sval[temp];trav = (trav+1)%SIZE){}
			if(D[trav]==Sval[temp]){
				D[trav]=DELETED;
				printf("%d has been deleted.\n",Sval[temp]);
			}else{
				printf("%d could not be found.\n",Sval[temp]);
			}
		}else{
			D[hash]=DELETED;
			printf("%d has been deleted.\n",Sval[temp]);
		}
	}
	printf("\n");
}