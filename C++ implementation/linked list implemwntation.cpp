#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<typeinfo>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

class Node;
class LinkedList;

//class to represent a Node in LinkedList
class Node{
public:
    int data;
    Node *next;
private:
    //TO DO
};

//class to represent a LinkedList
class LinkedList{
public:
    Node H,T;
    Node *head = &H;
    Node *tail = &T;
    LinkedList();
    void insert_node(int, int);
    void delete_node(int);
    void free_node(Node *);
    void print(void);
    void find_data(int);
    int len();
    void print_len();
private:
    //TO DO
};

//initialize a Linked List with only head and tail
LinkedList::LinkedList(){
    head->data = -1;
    head->next = tail;
    tail->data = -1;
    tail->next = NULL;
}

//return the length of this Linked List(without head and tail)
int LinkedList::len(){
    Node *ptr = head;
    int counter = 0;
    while(ptr->next != tail){
        ptr = ptr->next;
        counter++;
    }
    return counter;
}

//print the length
void LinkedList::print_len(){
    cout<<len()<<endl;
}

//insert a new Node into this LinkedList
void LinkedList::insert_node(int posi,int data){
    Node *insertNode = new Node();
    insertNode->data = data;
    insertNode->next = NULL;
    Node *currentNode = head;
    int currentIndex = -1;
    if(posi >= len()){
        cout<<"position over the length!!"<<endl;
        return;
    }
    while(currentIndex != posi){
        currentNode = currentNode->next;
        currentIndex++;
    }
    //insert after head
    if(currentNode->data == -1){
        insertNode->next = currentNode->next;
        head->next =insertNode;
        return;
    }
    //insert before tail
    if(currentNode->next == tail){
        insertNode->next = tail;
        currentNode->next = insertNode;
        return;
    //other situation (middle)
    }else{
        insertNode->next = currentNode->next;
        currentNode->next = insertNode;
        return;
    }
}

//release the memory of this Node
void LinkedList::free_node(Node *ptr){
    delete ptr;
}

//delete a Node
void LinkedList::delete_node(int posi){
    Node *current_ptr = head;
    int current_index = -1;
    if(posi > len()){
        cout<<"不要瞎掰好嗎?"<<endl;
        return;
    }
    while((current_index+1) != posi){
        current_ptr = current_ptr->next;
        current_index++;
    }
    //delete the first term
    if(posi == 0){
        Node *ptr = head->next;
        head->next = head->next->next;
        free_node(ptr);
        return;
    }
    //delete the last term
    if(posi == len()){
        Node *ptr = current_ptr->next;
        current_ptr->next = tail;
        free_node(ptr);
        return;
    //delete the other term
    }else{
        Node *ptr = current_ptr->next;
        current_ptr->next = current_ptr->next->next;
        free_node(ptr);
    }
}

//return the index of corresponding data
void LinkedList::find_data(int data){
    Node *current_Node = head;
    int current_Index = -1;
    while(current_Node->next->data != data){
        current_Node = current_Node->next;
        current_Index++;
        if(current_Node == tail){
            cout<<"這筆資料不在此Linked List裡"<<endl;
            return;
        }
    }
    current_Index++;
    cout<<"位置在 "<<current_Index<<endl;
}

//print all the element with form of [, , ,]
void LinkedList::print(void){
    Node *currentNode = head->next;
    cout<<"[";
    while(currentNode->data != -1){
        cout<<currentNode->data<<",";
        currentNode = currentNode->next;
    }
    cout<<"]"<<endl;
}

//main function start
int main(){
    LinkedList L;
    char key;
    int newData;
    int position;
    while(1){
        cout<<"i: 插入"<<endl;
        cout<<"p: 印出"<<endl;
        cout<<"d: 刪除"<<endl;
        cout<<"f: 尋找"<<endl;
        cout<<"e: 離開"<<endl;
        key = getche();
        switch(key){
            case 'i':
                cout<<"\n請輸入插入資料 ";
                cin>>newData;
                cout<<"\n請輸入插入位置 ";
                cin>>position;
                L.insert_node(position,newData);
                continue;
            case 'p':
                cout<<endl;
                L.print();
                continue;
            case 'd':
                cout<<"\n請輸入刪除位置 ";
                cin>>position;
                L.delete_node(position);
                continue;
            case 'f':
                cout<<"\n請輸入想找的資料 ";
                cin>>newData;
                L.find_data(newData);
                continue;
            case 'e':
                cout<<"Bye!Bye!"<<endl;
                exit(0);
            default:
                cout<<endl;
                L.print_len();
        }
    }
    return 0;
}
