#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail, *current, *nextNode;

int main()
{
    return 0;
}

void reverse()
{
    // All we do is reverse the links, doubly linked lists are good this way

    // 1. Swapping the values of the next and prev pointer using just 1 pointer is not possible
    // since you will lose values. Thus, a new pointer, next, will be used.
    // 2. Swap the next and prev addr
    // 3. Update current node
    // 4. Switch the head and tail

    // 1.
    current = head;
    while (current != 0)
    {
        // The next node will always be 1 node ahead of current
        nextNode = current->next; // Updated

        // 2.
        current->next = current->prev;
        current->prev = nextNode;

        // 3.
        current = nextNode; // Updated
    }
    // 4.
    // After the while loop, current and nextNode will be on the same node
    current = head; // Can use current or nextNode
    head = tail;
    tail = current;
}