#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

//class to represent a Node of binary tree
class Node{
public:
    int data;
    int height;
    Node *left;
    Node *right;
};

//class to represent a binary tree
class AVL_tree{
public:
    Node *root = new Node();
    root = NULL;
    Node* newNode(int);
    void insert_Node(int);
    int height(Node *);
    void delete_Node(int);
    bool hasRight(Node *);
    bool hasLeft(Node *);
private:
    void RightRotation();
    void LeftRotation();
};

//build a new Node (suppose all new Node is add in leaf)
Node* AVL_tree::newNode(int newData){
    node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

//insert a new Node into this tree
void AVL_tree::insert_Node(int newData){
    Node *currentNode = root;
    //handle the empty tree
    if(currentNode == NULL){
        currentNode->data = newData;
        currentNode->left = NULL;
        currentNode->right = NULL;
        currentNode->height = 0;
    }
    //handle not empty tree(need a new Node)
    Node *newNode = new Node();
    Node *leaf = new Node();
    while(currentNode != NULL){
        leaf = currentNode;
        if(currentNode->data > newNode->data){
            currentNode = currentNode->left;
        }else if(currentNode->data < newNode->data){
            currentNode = currentNode->right;
        }else{
            cout<<"this data has been in this tree"<<endl;
            return;
        }
    }
    if(leaf->data > newNode->data){
        leaf->left = newNode;
        newNode->height = leaf->height + 1;
    }else{
        leaf->right = newNode;
        newNode->height = leaf->height + 1;
    }
}

//
void AVL_tree::delete_Node(int deleteData){

}

//main function start
int main(){
    AVL_tree T;

    return 0;
}
