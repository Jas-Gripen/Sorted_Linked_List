/*
*   This is a sorted linked list
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *construct_node(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void add_first(int data);
void show_list();
void sort_add(int data);
void add_last(int data);
bool max_1_nodes(int data);
void remove_first();

Node *construct_node(int data);
Node *head;
Node *tail;
int N;  // Number of nodes

int main()
{
    head = NULL;
    tail = NULL;
    N = 0;
    int input1;
    int input2;
    while(1)
    {
        printf("Press \'1' to add or \'2\' to remove\n");
        scanf("%d", &input1);
        if(input1 == 1)
        {
            scanf("%d", &input2);
            sort_add(input2);
            show_list();
        }
       if (input1 == 2)
       {
           remove_first();
           show_list();
       }
    }
}


void add_first(int data)
{
    Node *new_node = construct_node(data);

    if (N == 0)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    N++;

}

void add_last(int data)
{
    Node *new_node = construct_node(data);

    if (N == 0)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    N++;

}
// Check if the new node should be the first
// or the last node
bool max_1_nodes(int data)
{
    if (N == 0)
    {
        add_first(data);
        return true;
    }

    else if (N == 1)
    {
        if (head->data >= data)
        {
            add_first(data);
            return true;
        }
        else
        {
            add_last(data);
            return true;
        }
    }
    else
    {
        return false;
    }
}

void sort_add(int data)
{
    if (max_1_nodes(data))
    {
        return;
    }

    else
    {
        Node *temp = head;
        if (tail->data <= data)
        {
            add_last(data);
            return;
        }
        for(int i = 0; i < N; i++)
        {
            if (data <= temp->data)
            {
                if (temp->prev == NULL)
                {
                    add_first(data);
                    return;
                }
                else
                {
                    Node *new_node = construct_node(data);
                    Node *left = temp->prev;
                    left->next = new_node;
                    new_node->prev = left;
                    new_node->next = temp;
                    temp->prev = new_node;
                    N++;
                    return;
                }
            }
            temp = temp->next;
        }
    }
}

void remove_first()
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    N--;
}

void show_list()
{
    Node *temp = head;
    for(int i = 0; i < N - 1; i++)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}