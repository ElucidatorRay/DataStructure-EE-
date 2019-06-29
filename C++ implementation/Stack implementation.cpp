#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<typeinfo>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define INIT 10

using namespace std;

class Stack{
public:
    int top;
    int *ptr;
    int len;
    Stack();
    void update();
    int Pop();
    void Push(int);
    void insertion_sort();
};
Stack::Stack(){
    int i;
    top = -1;
    len = INIT;
    ptr = (int*)malloc(sizeof(int)*INIT);
    for(i = 0;i<=len - 1;i++){
        ptr[i] = 0;
    }
}
void Stack::update(){
    int *new_ptr;
    int i;
    len = len*2;
    new_ptr = (int*)realloc(ptr,sizeof(int)*len);
    free(ptr);
    ptr = new_ptr;
}

int Stack::Pop(){
    if(top == -1){
        cout<<"no element in this stack!!"<<endl;
    }
    top--;
    return ptr[top + 1];
}
void Stack::Push(int newData){
    top++;
    ptr[top] = newData;
}

void Stack::insertion_sort(){
    int i,j;
    for(i = 1;i<=top;i++){
        int temp = ptr[i];
        for(j = i;j >= 0 && temp < ptr[j-1];j--){
            ptr[j] = ptr[j-1];
        }
        ptr[j] = temp;
    }
}

int main(){
    srand(time(NULL));
    Stack S;
    char operate;
    int newData;
    int i;
    while(1){
        cout<<endl<<"i: 推入"<<endl<<"o: 取值"<<endl<<"q: 結束"
        <<endl<<"p: 印出"<<endl<<"s: 排序"<<endl<<">>>";
        operate = getche();
        cout<<endl;
        switch(operate){
            case 'i':
                cout<<"輸入要推入之資料: ";
                cin>>newData;
                S.Push(newData);
                continue;
            case 'o':
                if(S.top == -1){
                    cout<<"No element in this stack"<<endl;
                }
                cout<<S.Pop()<<endl;
                continue;
            case 'q':
                cout<<"Bye!Bye!"<<endl;
                cout<<S.len;
                free(S.ptr);
                exit(0);
            case 'p':
                cout<<"[";
                for(i = 0;i<=S.top;i++){
                    cout<<S.ptr[i]<<",";
                }
                cout<<"]"<<endl;
                continue;
            case 's':
                S.insertion_sort();
                continue;
            default:
                cout<<"請重新輸入!"<<endl;
                continue;
        }
    }
    return 0;
}
