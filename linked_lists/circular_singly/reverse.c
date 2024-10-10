#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;
struct node *currentNode, *previousNode, *nextNode;

int main()
{
    return 0;
}

void reverse()
{
    // Assume a list exists

    // Start traversing from first node
    currentNode = tail->next;
    nextNode = currentNode->next;
    while (currentNode != tail)
    {
        // Update previousNode
        previousNode = currentNode;

        // Move current forward
        currentNode = nextNode;

        // Move nextNode forward
        nextNode = currentNode->next;

        // The reversal
        currentNode->next = previousNode;
    }

    // At this point, the last and first node have been swapped
    // Have to update the tail pointer

    // Points the new last node to former last node (last reversal)
    nextNode->next = tail;

    // Update tail
    tail = nextNode;
}