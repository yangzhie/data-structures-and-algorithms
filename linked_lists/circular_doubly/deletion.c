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

void delete_beginning()
{
    struct node *temp;
    temp = head; // Since first node

    // Before deletion, make head point to next node
    head = head->next;

    // head's prev should contain addr of last node (since it is circular)
    head->prev = tail;

    // tail's next now points to the new first node
    tail->next = head;

    // All links are broken of the node to be deleted, now free
    free(temp);
}

void delete_end()
{
    struct node *temp;
    temp = tail; // Since last node

    // New last node becomes the node before former last node
    tail = tail->prev;

    // New last node's next links to head
    tail->next = head;

    // head's prev links to new last node
    head->prev = tail;

    // Free memory
    free(temp);
}

void delete_specific()
{
    struct node *temp;
    int position, i = 1, length;
    length = get_length();

    temp = head;

    // Assume position = 3

    // Traverse
    while (i < position) // Till 3, the actual node itself
    {
        temp = temp->next;
        i++;
    }

    // Establish new link of previous node to next node
    temp->prev->next = temp->next;
    // Establish new link of next node to node before
    temp->next->prev = temp->prev;

    if (temp->next = head) // Case: 3rd position is the last node
    {
        // Update tail
        tail = temp->prev;
        free(temp);
    }
    else
    {
        free(temp);
    }
}