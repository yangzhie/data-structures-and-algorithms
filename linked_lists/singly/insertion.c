#include <stdio.h>
#include <stdlib.h>

void insertion_beginning();
void insertion_specific();

int main()
{
    // insertion_beginning();
    return 0;
}

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *newNode;
struct node *temp;

/**********************************************************************************************/

void insertion_beginning()
{
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data you want to insert: \n");
    scanf("%d", &newNode->data);

    // Sets the next pointer of the new node (newNode) to point to the current head of the linked list
    // The new node will now be linked to the existing list, effectively becoming the first node
    newNode->next = head;

    // This line updates the head pointer to point to the new node
    head = newNode;
}

/**********************************************************************************************/

// Insertion at the end is trivial

/**********************************************************************************************/

void insertion_specific()
{
    int position;
    int length_of_linked_list;
    int i = 1;

    printf("Enter the position you wish to insert at: \n");
    scanf("%d", &position);

    if (position > length_of_linked_list)
    {
        printf("Invalid position.");
    }
    else
    {
        // Traversing the list
        temp = head;

        while (i < position)
        {
            // temp's next pointer now is stored in temp
            // remember, temp is a pointer to a node
            temp = temp->next;
            i++;
            // After this loop, temp has reached the desired position and after this position the new node is inserted
        }

        // Making the new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // User input
        printf("Enter the data you wish to insert: \n");
        scanf("%d", &newNode->data);

        // Now we need to establish the link b/w previous node and front node
        // Establish the front (right) link first always

        // This is the previous node's next pointer which has the next node's address
        // We need the next node's address to be stored in the new node's address
        newNode->next = temp->next;

        // Now we establish the previous node's link
        temp->next = newNode;
    }
}