#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    return 0;
}

struct node *head = 0, *temp;

// Count the nodes of a linked list = length of linked list
void linked_list_length()
{
    // We have to traverse the list, hence temp exists
    // Init temp
    temp = head;

    int count = 0;

    // Traverse temp until NULL/0
    while(temp != 0)
    {
        count++;
        // "Increment" temp
        temp = temp->next;
    }

    printf("Length: %d", count);
}