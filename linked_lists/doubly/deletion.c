#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail, *temp;

int main()
{
    return 0;
}

void delete_from_beginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;

    // We assume there are 3 pre-existing nodes in the list

    // 1. New pointer (temp) at start of list
    // 2. Link head to second node
    // 3. Link prev pointer of new first node to NULL
    // 4. Free temp

    // 1.
    temp = head;

    // 2.
    head = head->next;

    // 3.
    head->prev = 0;

    // 4.
    free(temp);
}

void delete_from_end()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;

    // We assume there are 3 pre-existing nodes in the list

    // 1. New pointer (temp) at start of list, traverse to end of list
    // 2. Set addr of next pointer of the second last node to NULL
    // 3. Set tail to point to the new last node
    // 4. Free the last node

    // 1.
    temp = tail;

    // 2.
    tail->prev->next = 0;

    // 3.
    tail = tail->prev;

    // 4.
    free(temp);
}

void delete_from_specific_position()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    head = 0;
    int position;
    int i = 1;

    // We assume there are 4 pre-existing nodes in the list and we want to delete the 3rd node

    // 1. Traverse a pointer to the specified position
    // 2. Reassign the link of the node in front's prev to the node in back
    // 3. Reassign the link of the node in back's next to the node in front
    // 4. Free the node to be deleted

    // 1.
    temp = head;
    while (i < position)
    {
        // Move addr onto next node
        temp = temp->next;
        i++;
    }

    // 2.
    temp->next->prev = temp->prev;

    // 3.
    temp->prev->next = temp->next;

    // 4.
    free(temp);
}