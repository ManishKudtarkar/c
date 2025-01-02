#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
int main(){
    bool safe(int arr[][5],int r,int c){
        if(r<=4 && c<=4 && arr[r][c]==1){
            return true;
        }
        return false;
    }
    bool solution(int arr[][5],int sol[][5],int r,int c){
        if(r==4 && c==4 && arr[r][c]==1){
            sol[r][c]=1;
            return true;
        }
        if(safe(arr,r,c)==true){
            sol[r][c]=1;
            if(solution(arr,sol,r,c+1)==true){
                return true;
            }
            if(solution(arr,sol,r+1,c)==true){
                return true;
            }
        }
        sol[r][c]=0;
        return false;
    }
    
    int arr[5][5]={{1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,1,1,0,0},
                   {1,0,1,0,1},
                   {1,0,1,1,1}};
                   
    int sol[5][5]={{0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0}};
    solution(arr,sol,0,0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",sol[i][j]);
        }
        printf("\n");
    }
                   
}


