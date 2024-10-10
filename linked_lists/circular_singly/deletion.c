#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail, *temp;

int main()
{
    return 0;
}

void delete_beginning()
{
    // Means the node after last node (which tail points to) AKA first node
    // Assume a list exists

    // Last node contains addr of first node
    temp = tail->next;

    // Update last node's next to point to new first node
    tail->next = temp->next;

    // Free last node
    free(temp);
}

void delete_end()
{
    // Means the node which tail points to AKA last node
    // Assume a list exists

    // Have to traverse since we cannot go backwards
    struct node *current, *previous;
    current = tail->next;
    while (current->next != tail->next)
    {
        previous = current;
        // Move current
        current = current->next;
    }

    // Essentially re-routed so that the new last node points to the first node
    previous->next = tail->next;

    // Update tail
    tail = previous;

    // Free former last node
    free(current);
}

void delete_specific()
{
    // Assume a list exists
    // Assume we want to delete node at position = 3

    struct node *current, *nextNode;
    int position;
    int i = 1;
    int l;

    // Pointer to first node
    current = tail->next;
    l = get_length();

    // Traverse
    while (i < position - 1) // If position = 1, same as delete_beginning
    {
        current = current->next;
        i++;
    }

    // The node we want to delete
    nextNode = current->next;

    // Update addr of the node before to point to node after
    current->next = nextNode->next;

    // Free node
    free(nextNode);
}