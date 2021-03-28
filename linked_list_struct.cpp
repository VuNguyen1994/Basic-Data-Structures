#include <stdio.h>
#include <iostream>
#include <map>

struct Node
{
    /* data */
    int data;
    struct Node * next;
};

struct linked_list_struct
{
    struct Node * head;
};

void print_linked_list(linked_list_struct * a){
    struct Node * current = a->head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        if(current != NULL) printf("->");
    }
    printf("\n");
}

void insert(linked_list_struct * a, int value){
    if (a->head == NULL){
        a->head = new Node;
        a->head->data = value;
    }
    else
    {
        // Append new node to the sorted linked list. Step 1: find the location
        struct Node * current = a->head;
        struct Node * prev = current;
        while (current != NULL && current->data <= value){
            prev = current;
            current = current->next;
        }
        if (current == NULL){
            // Reach the end, prev would be the last not-null node. Append new node the the last node
            prev->next = new Node;
            prev->next->data = value;
        }
        else
        {
            // Current > inserted value and prev is <= value. Append new node in between of prev and current
            struct Node * newnode = new Node;
            newnode->data = value;
            newnode->next = current;
            // Check if inserted value is going be new head (smallest)
            if (value < a->head->data){
                a->head = newnode;
            }
            else{
                prev->next = newnode;
            }
        }
    }
}

void delete_node(linked_list_struct * a, int val){
    struct Node * current = a->head;
    struct Node * prev = current;
    while (current != NULL && current->data != val)
    {
        /* code */
        prev = current;
        current = current->next;
    }
    if (current->data = val){
        // Delete the current node. 
        if (val == a->head->data)
        {
            /* Remove the head */
            a->head = current->next;
        }
        else
        {
            prev->next = current->next;    
        }
        free(current);
    }
    else
    {
        printf("Node %d not in Linked list\n", val);
    }

}

void remove_dups(linked_list_struct * a){
    struct Node * current = a->head;
    struct Node * check_node = a->head;
    while (current != NULL)
    {
        /* code */
        check_node = current ->next;
        while (check_node != NULL)
        {
            if (check_node->data == current->data){
                // remove dups
                current->next = check_node->next;
                free(check_node);
                check_node = current->next;
            }
            else{
                check_node = check_node->next;
            }
        }
        current = current->next;
    }
}

int main(int argc, char *argv[]){
    struct linked_list_struct * a = (struct linked_list_struct *) malloc(sizeof(linked_list_struct));
    insert(a, 2);
    insert(a, 4);
    insert(a, 3);
    insert(a, 1);
    insert(a, 5);
    insert(a, 3);
    insert(a, 3);
    insert(a, 5);
    printf("Linked List: \n");
    print_linked_list(a);
    printf("After rm dups\n");
    remove_dups(a);
    print_linked_list(a);
    int del_val = 1;
    printf("After delete node %d\n", del_val);
    delete_node(a, del_val);
    print_linked_list(a);

    return 0;
}





