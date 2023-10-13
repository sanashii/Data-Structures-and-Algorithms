#define maxCells 1000
#define maxCS 11
#define maxIT 19

// Problem Definition:
// A list of BSCS and BSIT student records is stored in internal memory represented using cursor-based implementation. 
// The list is to be converted into a dictionary, a set ADT. The dictionary is represented in memory using open-hashing (cursor-based).
// Each group in the header table is sorted in ascending order according to ID.

// *Hash function exists and can be called in your function. The function will accept an element as its parameter and 
// return the appropriate hash value for each element.

// Write the code of the function CreateDic() – the function will convert the list of BSCS and BSIT student records into a dictionary,
// which will be returned to the calling function. Each student record is uniquely identified by the ID.
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char LN[16], FN[24], MI;
}nametype;

typedef struct studtype{
    unsigned long ID;
    nametype name;
    char course[8];
    int yr;
}student;

typedef struct ctype{
    student stud;
    int next;
}celltype;

typedef struct{
    int *Header;
    int CourseCtr;  /*holds the # of elements for each course*/
}CSIT;

typedef CSIT Dictionary[2];
typedef int LIST;

typedef struct{
    celltype heap[maxCells];
    int AvailPtr;   /*holds the index to the first available cell in the VH*/
}*VirtualHeap;

void CreateDic() // use the student ID lng siguro for the hash value