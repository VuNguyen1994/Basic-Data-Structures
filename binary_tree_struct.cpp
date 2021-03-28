#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct binary_tree
{
    struct Node * root;
};

void inorder(Node * node){
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node * node){
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


void postorder(Node * node){
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void print_bt(binary_tree * a){
    struct Node * current = a->root;
    cout << "Binary Tree Presentation (Root = " << a->root->data << ")" << endl;
    cout << "Inorder" << endl;
    inorder(current);
    cout << endl;
    cout << "Preorder" << endl;
    preorder(current);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(current);
    cout << endl;
}

void insert(binary_tree * a, int val){
    if (a->root == NULL){
        a->root = new Node;
        a->root->data = val;
    }
    else
    {
        struct Node * current = a->root;
        struct Node * parent = a->root;
        while (current != NULL){
            parent = current;
            if (val >= current->data)
                current = current->right;
            else
                current = current->left;
        }
        // current is NULL, add the val as the child of the current parent node
        struct Node * newnode = new Node;
        newnode->data = val;
        if (val >= parent->data)
            parent->right = newnode;
        else
            parent->left = newnode;
    }
}

int main(int argc, char *argv[]){
    struct binary_tree * a = (struct binary_tree *) malloc(sizeof(binary_tree));
    insert(a, 3);
    insert(a, 4);
    insert(a, 1);
    insert(a, 4);
    insert(a, 6);
    insert(a, 2);
    print_bt(a);
    return 0;
}