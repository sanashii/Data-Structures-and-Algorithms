
#include <stdio.h>
#define INT_MAX 100000
#define size 5


void FuncDijkstra(int matrix[][size], int V[], int Source);
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
    
    FuncDijkstra(labadj,vertices,0);
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
    for(x=1; x<size; x++){
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