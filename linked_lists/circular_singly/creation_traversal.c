#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *temp;

int main()
{
    return 0;
}

// All a singly circular linked list needs is to store the address of the first node (head) into the last node's next pointer
void creation()
{
    // Create new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Initialize new node
    newNode->data = 10;
    newNode->next = NULL;

    // Initialize pointers
    if (head == 0)
    {
        head = newNode;
        temp = head;
    }
    else
    {
        // Link new node to existing list
        temp->next = newNode;
        // Update temp
        temp = newNode;
    }

    // This makes it a singly circular linked list
    temp->next = head;
}

void traversal()
{
    // Assume a linked list exists

    temp = head;

    while (temp->next != 0)
    {
        printf("%d", temp->data);

        // Update temp
        temp = temp->next;
        // Cannot use temp = newNode since it doesn't exist
    }
}