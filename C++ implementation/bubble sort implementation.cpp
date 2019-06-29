#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define INIT 10

using namespace std;

void BubbleSort(int * L){
    int i,j,temp;
    for(i = 0;i < INIT;i++){
        for(j = 0;j <= (INIT-i);j++){
            if(L[j] > L[j + 1]){
                temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int *L = (int* )malloc(sizeof(int)*INIT);
    int i;
    for(i = 0;i < INIT;i++){
        L[i] = rand()%10000 + 1;
    }
    cout<<"[";
    for(i = 0;i < INIT;i++){
        cout<<L[i]<<",";
    }
    cout<<"]"<<endl;
    cout<<"\n\n\n";
    BubbleSort(L);
    cout<<"[";
    for(i = 0;i < INIT;i++){
        cout<<L[i]<<",";
    }
    cout<<"]"<<endl;
    free(L);
    return 0;
}
