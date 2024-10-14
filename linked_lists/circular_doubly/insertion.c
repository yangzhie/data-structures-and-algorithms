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

void insert_beginning()
{
    // Assume a circular linked list exists

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = 0;
    newNode->prev = 0;
    newNode->data = 10;

    if (head == 0)
    {
        head = tail = newNode;

        // For circular, ensure that both the head and tail are linked to each other
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        // Link new node's next addr
        newNode->next = head;
        // Link existing node's prev addr
        head->prev = newNode;

        // Link prev of new node to last node
        newNode->prev = tail;
        // Link next of last node to new node
        tail->next = newNode;

        // Update head to point to new first node
        head = newNode;
    }
}

void insert_end()
{
    // Assume a circular linked list exists

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = 0;
    newNode->prev = 0;
    newNode->data = 10;

    if (head == 0)
    {
        head = tail = newNode;

        // For circular, ensure that both the head and tail are linked to each other
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        // Link prev of new node to former last node
        newNode->prev = tail;
        // Link last node's next to new node
        tail->next = newNode;

        // Link new node's next to starting node
        newNode->next = head;
        // Link starting node's prev to new node
        head->prev = newNode;

        // Update tail to point to new end node
        tail = newNode;
    }
}

void insert_specific()
{
    // Assume a circular linked list exists

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = 0;
    newNode->prev = 0;
    newNode->data = 10;

    if (head == 0)
    {
        head = tail = newNode;

        // For circular, ensure that both the head and tail are linked to each other
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        int position, i = 1, length;
        length = get_length();

        // Suppose we want to insert at position 3
        struct node *temp;
        temp = head;

        // If position = 1, insert at beginning

        // Traverse till position before desired position on insertion
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        // Link the new node's prev to temp (it's the one for desired position)
        newNode->prev = temp;
        // Link new node's text to the one after temp
        newNode->next = temp->next;

        // Link the node after's prev to new node
        temp->next->prev = newNode;
        // Link temp's next to new node
        temp->next = newNode;
    }
}