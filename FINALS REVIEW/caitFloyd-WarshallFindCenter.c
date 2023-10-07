
#include <stdio.h>
#define INT_MAX 100000
#define size 5


void FuncDijkstra(int matrix[][size], int V[], int Source);
void FuncFloyd(int matrix[][size], int Floyd[][size]);
void FuncWarsh(int matrix[][size], int Warsh[][size]);
void FindCenter(int matrix[][size]);

void main(){

    int labadj[size][size] = { {INT_MAX,10,INT_MAX,30,100}, {INT_MAX,INT_MAX,50,INT_MAX,INT_MAX}, {20,INT_MAX,INT_MAX,INT_MAX,10},
                               {INT_MAX,INT_MAX,20,INT_MAX,60}, {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX} };
    
    for(int x = 0; x<size; x++){
        for(int y=0; y<size; y++){
            printf("%10d || ", labadj[x][y]);
        }
        printf("\n");
    }
    
    int vertices[size] = {1,1,1,1,1}; //bit implementation
    
    FuncDijkstra(labadj,vertices,3);
    
    int A[size][size] = {0};
    FuncFloyd(A,labadj);
    
    int x,y;
    printf("Floyd Matrix: \n");
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            printf("%10d ||", A[x][y]);
        }
        printf("\n");
    }
    
    int center[size][size] = { {0,3,5,7,9}, {INT_MAX,0,2,4,6}, {INT_MAX,3,0,2,4}, {INT_MAX,1,3,0,7}, {INT_MAX,2,4,4,0}};
    FindCenter(center);

}

void FuncDijkstra(int matrix[][size], int V[], int Source){
    
    int x,y;
    int w,v;
    int S[5], Diff[5];

    //1. initialize Source
    for(x=0; x<size; x++){
        S[x] = (x == Source)?1:0;
    }
    printf("SET S: %d %d %d %d %d", S[0], S[1], S[2], S[3], S[4]);
    
   //2. initialize result array 
    int Dijkstra[size];
    Dijkstra[Source] = INT_MAX;
    for(x=Source+1; x != Source; x = (x + size + 1) % size){
        Dijkstra[x] = matrix[Source][x];
    }
    
    
    printf("\nSet Dijkstra: ");
    printf("%d ", Dijkstra[0]);
    printf("%d ", Dijkstra[1]);
    printf("%d ", Dijkstra[2]);
    printf("%d ", Dijkstra[3]);
    printf("%d ", Dijkstra[4]);
    printf("\n");
    
    //3. check paths
    for(x=1; x<size-1; x++){
        //a. choose vertex w in V-S

        //get V-S
        for(y=0; y<size; y++){
            Diff[y] = (V[y] && S[y])?0:1;
        }
        
        //find w 
       for(y=0; y<size && Diff[y] != 1; y++){}
       w = y;
    
       for(y=0; y<size; y++){
            if(Diff[y] == 1 && Dijkstra[y] < Dijkstra[w]){
                w = y;
            }
        }
       

        //b. add w to S here 
        S[w] = 1;
        
        
        //c. for each vertex in V-S, check path
        
        for(y=0; y<size; y++){
            Diff[y] = (V[y] && S[y])?0:1;
        }
        
        for(v=0; v<size; v++){
            if(Diff[v] == 1){
                Dijkstra[v] = (Dijkstra[v] < Dijkstra[w] + matrix[w][v])? Dijkstra[v] : Dijkstra[w] + matrix[w][v];
            }
        }
        
        
    }
      
    printf("\nDjikstra Result\n");
        for(x=0; x<size; x++){
            if(x ==Source){
                printf("%d is the source\n",x);
            }else{
                printf("Cost to %d is %d\n", x,Dijkstra[x]);
        }  
    }
    
}

void FuncFloyd(int matrix[][size], int Floyd[][size]){
    int i,j,k;
    
    //Copy A to C
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            matrix[i][j] = Floyd[i][j]; 
        }
    }
    
    //Diagonal to 0
    for(i=0; i<size; i++){
        matrix[i][i] = 0;
    }

    
    //Find paths
    for(k = 0; k<size; k++){
        for(i = 0; i<size; i++){
            for(j = 0; j<size; j++){
                if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    
}

void FuncWarsh(int matrix[][size], int Warsh[][size]){
    int i,j,k;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            matrix[i][j] = Warsh[i][j];
        }
    }
    
    for(k=0; k<size; k++){
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                if(matrix[i][j] == 0){
                    matrix[i][j] = matrix[i][k] && matrix[k][j];
                }
            }
        }
    }
    
}

void FindCenter(int matrix[][size]){
    int A[size][size] = {0};
    FuncFloyd(A, matrix);
    
    
    
    int x,y;
    
    printf("Floyd Matrix: \n");
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            printf("%10d ||", A[x][y]);
        }
        printf("\n");
    }
    

    //find eccentricity in matrix[][size]
    int ecc[size];
    
    for(x=0; x<size; x++){
        ecc[x] = A[0][x];
    }
    
    //check column
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            if(matrix[y][x] > ecc[x]){
                ecc[x] = A[y][x];
            }
        }
    }
    
    for(x=0; x<size; x++){
        printf("MAX eccentricity of %d is: %d \n", x, ecc[x]);
    }
    
    int min;
    min = 0;
    for(x=0; x<size; x++){
        if(ecc[x] < ecc[min]){
            min = x;
        }
    }
    
    if( min = 0){
        printf("%c", 'a');
    }else if( x = 1){
        printf("%c", 'b');
    }else if( x = 2){
        printf("%c", 'c');
    }else if( x = 3){
        printf("%c", 'd');
    }else if( x = 4){
        printf("%c", 'e');
    }
    
}