#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail;

int main()
{
    return 0;
}

void creation()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = 0;
    newNode->prev = 0;
    newNode->data = 10;

    if (head == 0)
    {
        head = tail = newNode;
    }
    else
    {
        // Link forward
        tail->next = newNode;
        // Link backward
        newNode->prev = tail;
        // Cicular link forward
        newNode->next = head;
        // Cicular link backward
        head->prev = newNode;
        // Update link
        tail = newNode;
    }
}

void traversal()
{
    // Assume a circular doubly linked list exists

    struct node *temp;
    temp = head;

    while (temp != tail)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    // Still need to print last one
    printf("%d", temp->data);
}
