#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;

int main()
{
    return 0;
}

void create()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->prev = 0;
    newNode->next = 0;

    if (head == 0)
    {
        head = tail = newNode;
    }
    else
    {
        // 1. store addr of prev node in new node
        // 2. store addr of new node in prev node
        // 3. update pointers

        // 1.
        tail->next = newNode;
        // 2.
        newNode->prev = tail;
        // 3.
        tail = newNode;
    }
}

void insertion_beginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;

    // We assume there are 3 pre-existing nodes in the list

    // The first node's prev pointer points to addr of new node
    head->prev = newNode;

    // new node's next pointer stores addr of former first node
    newNode->next = head;

    // now head in updated so that newNode is first
    head = newNode;
}

void insertion_end()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;

    // We assume there are 3 pre-existing nodes in the list
    // tail pointer comes in handy here since it has been maintained

    // In the current last node's next pointer would be stored the address of new node
    tail->next = newNode;

    // The addr of the new node's prev pointer will now point to the former last node
    newNode->prev = tail;

    // now update tail so that the new node becomes the last node
    tail = newNode;
}

void insertion_specific()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;
    int position;

    // We assume there are 3 pre-existing nodes in the list
    // In this we omit position = 1 since that is the same as insertion_beginning()

    // New pointer needed since we cannot move head or tail
    struct node *temp;
    // Initialize
    temp = head;

    // Let's say the user wants to insert at position 3, so after node 2 and before node 3
    int i = 1;
    while (i < position - 1)
    {
        // Move addr onto next node
        temp = temp->next;
        i++;
    }

    // 1. Link the newNode's prev pointer to the position - 1 node
    // 2. Link the newNode's next pointer to position + 1 node
    // 3. Link the position - 1 node's next pointer to newNode
    // 4. Link the position + 1 node's prev pointer to newNode

    // 1.
    newNode->prev = temp;

    // 2.
    newNode->next = temp->next;

    // Both position + 1 node's prev pointer and position - 1 node's next pointer will be the same
    // They both point to the new node inserted in their middle!

    // 3.
    temp->next = newNode;

    // 4.
    newNode->next->prev = newNode; // I didn't know we could chain them! Used too much of my brain power just to find out you could do this
}
