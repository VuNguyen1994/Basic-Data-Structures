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

struct bst
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

void print_bt(bst * a){
    struct Node * current = a->root;
    cout << "Binary Search Tree Presentation (Root = " << a->root->data << ")" << endl;
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

void insert(bst * a, int val){
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

int minNode(Node * node){
    /* Find the left-most node */
    if (node == NULL)
        return -1;
    struct Node * current = node;
    while (current->left!= NULL)
    {
        current = current->left;
    }
    // printf("DEBUG: minNode %d\n", current->data);
    return current->data;
}

int maxNode(Node * node){
    /* Find the left-most node */
    if (node == NULL)
        return -1;
    struct Node * current = node;
    while (current->right!= NULL)
    {
        current = current->right;
    }
    // printf("DEBUG: maxNode %d\n", current->data);
    return current->data;
}

void delete_node(bst * a, int val){
    struct Node * current = a->root;
    struct Node * parent = current;
    while (current != NULL && current->data != val)
    {
        parent = current;
        if (val > current->data)
            current = current->right;
        else if (val < current->data)
            current = current->left;
        // printf("DEBUG: Node %d\n", current->data);
    }
    if (current == NULL){
        return; //No node found to delete
    }
    if (current->data == val){
        // Remove node current
        if (current->left == NULL && current->right == NULL){
            // If current is a leaf node
            if (current->data == parent->left->data) parent->left = NULL;
            if (current->data == parent->right->data) parent->right = NULL;
            free(current);
        }
        else if(current->left != NULL && current->right == NULL){
            // Current left child exist, need to find the max of the left side to replace. 
            int temp = maxNode(current->left);
            delete_node(a, temp);
            current->data = temp;
        }
        else{
            // Right node is not NULL or both children are not NULL, find the min of the right side to replace the current
            int temp = minNode(current->right);
            delete_node(a, temp);
            current->data = temp;
        }
    }  
}

int main(int argc, char *argv[]){
    struct bst * a = (struct bst *) malloc(sizeof(bst));
    insert(a, 50);
    insert(a, 30);
    insert(a, 20);
    insert(a, 40);
    insert(a, 70);
    insert(a, 60);
    insert(a, 80);
    print_bt(a);

    printf("\nAfter Delete 30\n");
    delete_node(a, 30);
    print_bt(a);
    return 0;
}