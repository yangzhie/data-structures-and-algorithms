#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0;

int main()
{
    return 0;
}

// Two approaches: iterating & recursion
// Research via recursion method later

// Essentially what will happen is two things:
// head will point to the last node
// Every single link will point backwards
// i.e if node 1 --> node 2, it will become node 1 <-- node 2

// Will have to traverse and at the same time, reverse the link
void reverse()
{
    // These pointers will contain address' for the nodes
    struct node *prevNode, *currentNode, *nextNode;

    // Will be 0 at start because the first node will have no previous node to refer to
    prevNode = 0;

    // These two will point to head at start because we need to traverse the list
    currentNode = nextNode = head;

    // Start traversing
    while(nextNode != 0)
    {
        // Before updating the current node's address to 0, need to move nextNode to node after nextNode, or else we will lose link
        // Can also use currentNode->next, same thing
        nextNode = nextNode->next;

        // Break/update link of current node
        // currentNode's address part now stores previous node's address
        currentNode->next = prevNode;

        // Now the previous node becomes the current node
        prevNode = currentNode;

        // Move currentNode forward too
        // At this point, the currentNode and nextNode are basically the same
        currentNode = nextNode;
    }

    // At this point, head still points to the first node
    // Also at this point, nextNode and currentNode are both 0, but prevNode is not (compare lines 48 and 52)
    // This is SOOOOOOOO important to my understanding now
    head = prevNode;
}

// Think of prevNode, currentNode and nextNode as JUST POINTERS, because THEY ARE
// head = prevNode - these are are pointing to a node, they are not actual nodes
// The actual nodes are accessed by ->next!
// GET IT THROUGH YOUR HEAD!
// Loving and hating linked lists at the same time. You think you understand it, then you don't.