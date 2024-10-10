#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

int main()
{
    return 0;
}

void insert_beginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 10;
    newNode->next = 0;

    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        // Link new node's next pointer to first node
        // The last node's next pointer contains address of first node
        newNode->next = tail->next;

        // Change addr of Last node's next pointer to new first node
        tail->next = newNode;
    }
}

void insert_specific_position()
{
    // Assume a linked list exists
    // tail pointer is pre-existing, think of it as a head

    int position;
    struct node *temp;     // For traversing
    int l = get_length(l); // Assume get_length returns length of linked list
    int i = 1;

    if (position < 0 || position > l)
    {
        printf("Invalid position.");
    }
    // Remember position == 1 is same as insert_beginning
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = 10;
        newNode->next = 0;

        // Traverse
        temp = tail->next; // tail->next always has first node
        while(i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        // Link the new node's next pointer to node after
        newNode->next = temp->next;

        // Link the node before's next pointer to new node
        temp->next = newNode;
    }
}

int get_length(list) {}