#include <stdio.h>
#include <stdlib.h>

/*
 * Like arrays, linked lists also store items.
 * But they do not store them consecutively like arrays.
 * These are called collections.
 *
 * The "linked" in Linked Lists comes from the data in the collections having
 * stored both the data and the address of the next value to refer to.
 * This completeness of a data, being a value + address of next value
 * is known as a "node".
 *
 * In the last data of the collection, instead of a pointer to the next data,
 * instead "null" is stored.
 *
 * The "head" points to the first node in the Linked List.
 *
 * In arrays, direct-access only. In Linked Lists, sequential-access only, including the last node.
 * Though, insertion and deletion is easier.
 */

/**********************************************************************************************/

/*
 * ***Types of Linked Lists***
 *
 * **Singly Linked Lists**
 * - Common one
 * - Each node contains a data part + pointer to next node
 * - Contains a head, it is not a node, but just a pointer to the first node
 * - Only forward traversal is possible
 *
 * struct node
 * {
 *     int a;             // The variable/value located in current node
 *     struct node *next; // The address of the next node
 * }
 *
 * **Doubly Linked Lists**
 * - Has double pointers
 * - 3 parts: 1 data part + 2 address parts
 * - One of these two pointers is a pointer to previous node, and the other is pointer to next node
 * - The first pointer which the head points to and the last pointer of last node is "null"
 *
 * struct node
 * {
 *     int a;             // The variable/value located in current node
 *     struct node *prev; // The address of the previous node
 *     struct node *next; // The address of the next node
 * }
 *
 * **Circular Linked Lists**
 * - Variation of singly linked list
 * - Difference is instead of the last node's next pointer being "null", the address of
 *   the first node is stored
 *
 * **Doubly Circular Linked Lists**
 * - Variation of doubly linked list
 * - Last node's next pointer stores address of first node
 * - First node's prev pointer stores address of last node
 */

/**********************************************************************************************/
void creation_and_traversal();

int main()
{
    creation_and_traversal();
    return 0;
}

/**********************************************************************************************/

// Define node
struct node
{
    int data;
    struct node *next;
};

void creation_and_traversal()
{
    // Defining head
    // head points to struct node, imagine int *p
    // Initially, head is 0/null, does not store anything
    struct node *head = NULL;

    // To accomodate for having more than 2 nodes
    // This is because we cannot move the *head or else would lose referencer to first node
    // Traverses the list
    struct node *temp;

    // In this pointer we store every single new node that we create henceforth
    struct node *newNode;

    // The number of nodes the user inputs
    int number_of_nodes;

    // User input: number of nodes
    printf("How many nodes do you want to insert? ");
    scanf("%d", &number_of_nodes);

    for (int i = 0; i < number_of_nodes; i++)
    {
        /**********************************************************************************************/

        // Creating a new node
        // malloc returns a pointer to the starting address of that memory block, AKA void pointer
        // Thus, we need to type cast it so we can store the address it gives
        // We store the pointer that malloc returns inside the newNode pointer
        newNode = (struct node *)malloc(sizeof(struct node)); // 4 bytes + 4 bytes = 8 bytes

        // User input for data
        printf("Enter the data for node %d: ", i + 1);
        // Cannot directly access members of a struct and use &data
        // Read as: newNode's data part of the struct
        scanf("%d", &newNode->data);

        // Sets up the address part after the data part has been inserted
        newNode->next = NULL;

        /**********************************************************************************************/

        // Now we need to put the newNode into the linkage
        // We store the first node's address into head
        // This condition ensures head is only set at the starting case
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            // Currently, the last node's address part (next) is NULL
            // So we update the last node's address part to hold this new node's address
            // We link this last node to the new node by setting its next pointer to point to newNode
            // This means that the current node (referred to by temp) will now have its next pointer updated to point to the new node you are adding (newNode)
            // In this case, temp is a pointer to the last node
            temp->next = newNode;
            // temp is still pointing to the last node
            // Updates temp to point to the new node
            // In this case, temp itself is updated instead of the last node
            temp = newNode;
        }
    }

    // Now, traverse the linked list and print its data
    printf("\nTraversing the linked list:\n");
    temp = head; // Start from the head node
    while (temp != NULL)
    {
        // Print the data of the current node
        printf("%d -> ", temp->data);
        // Move to the next node
        temp = temp->next;
    }
    printf("NULL\n");
}