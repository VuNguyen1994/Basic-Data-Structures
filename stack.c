#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// #include <map>
// #include <bits/stdc++.h>
// using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node * next;
};

struct stack
{
    struct Node * head;
};

void print_stack(stack * a){
    struct Node * current = a->head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        if(current != NULL) printf("->");
    }
    printf("\n");
}

void push(stack * a, int value){
    if (a->head == NULL){
        a->head = (struct Node *) malloc(sizeof(Node));
        a->head->data = value;
    }
    else
    {
        //Create a new node and push to the top of the stack
        struct Node * newNode = (struct Node *) malloc(sizeof(Node));
        newNode->data = value;

        newNode->next = a->head;
        a->head = newNode;
    }
}

struct Node * pop(stack * a){
    struct Node * current = a->head;
    if (current == NULL)
    {
        return current;
    }
    else
    {
        struct Node * newhead = current->next;
        a->head = newhead;
        return current;
    }
}

struct Node * peek(stack * a){
    return a->head;
}

int isEmpty(stack * a){
    if (a->head == NULL)
    {
        return 1;   
    }
    else
    {
        return 0;
    }
    
}

int main(int argc, char *argv[]){
    struct stack * a = (struct stack *) malloc(sizeof(stack));
    printf("Linked List isempty(): %d\n", isEmpty(a));
    push(a, 2);
    push(a, 4);
    push(a, 3);
    push(a, 1);
    push(a, 5);
    push(a, 3);
    push(a, 3);
    push(a, 5);
    printf("Linked List: \n");
    print_stack(a);
    printf("Linked List isempty(): %d\n", isEmpty(a));
    printf("After pop()\n");
    struct Node * p = pop(a);
    print_stack(a);
    printf("Peek: %d\n", peek(a)->data);

    return 0;
}

