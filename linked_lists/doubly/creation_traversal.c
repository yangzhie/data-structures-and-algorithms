#include <stdio.h>

/*
 * **Doubly Linked Lists**
 * Contains two links, one to next node, one to previous node
 * Thus it contains three parts, one data part and two address parts
 * The first node's previous part will point to NULL/0
 *
 * Pros:
 * - Forward + backward traversal
 * - For deletion of node, only one pointer is enough
 *
 * Cons:
 * - Takes more memory space (4 + 4 + 4 = 12 bytes)
 */

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    creation_and_traversal();
    return 0;
}

void creation_and_traversal()
{
    // head will point to the first node, tail will point to the last node
    struct node *head = NULL, *tail = NULL;

    // temp for traversal
    struct node *temp;

    // Pointer to store each new node created
    struct node *newNode;

    int number_of_nodes;

    // User input
    printf("How many nodes do you want to insert? ");
    scanf("%d", &number_of_nodes);

    // Creating new nodes
    for (int i = 0; i < number_of_nodes; i++)
    {
        /**********************************************************************************************/

        // Allocating memory for a new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // User input
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &newNode->data);

        // Initialize the prev and next pointers of the new node
        newNode->prev = NULL;
        newNode->next = NULL;

        // Node is now created, but not linked to the list yet
        // At this point, the node looks like this: 0 | data | 0

        /**********************************************************************************************/

        // Inserting the new node into the doubly linked list
        if (head == NULL)
        {
            // If this is the first node, head and tail point to it
            head = tail = newNode;

            // At this point, the addresses look like this:
            // head->[NULL | data | NULL]
            // tail->[NULL | data | NULL]
            // newNode->[NULL | data | NULL]
        }
        else
        {
            // Links previous node to new node
            /*
             * Need to: link new node to end of list
             * Update next pointer of current tail to point to the new node
             *
             * Existing List:     [ prev | data1 | NULL ]         <-- tail
             * New Node (isolated): [ NULL | data2 | NULL ]       <-- newNode
             */

            /*
             * Existing List:     [ prev | data1 | newNodeAddr ]  <-- tail
             *                               |
             *                              V
             * New Node (linked): [ NULL | data2 | NULL ]         <-- newNode
             */
            tail->next = newNode;



            // Establish backward link
            /*
             * Existing List: [ prev | data1 | newNodeAddr ]  <-- tail
             *                           |
             *                           V
             * New Node:      [ NULL | data2 | NULL ]         <-- newNode
             */

            /*
             * Existing List: [ prev | data1 | newNodeAddr ]    <-- tail
             *                           |         ^
             *                          V          |
             * New Node:   [ tailAddr | data2 | NULL ]          <-- newNode
             */
            newNode->prev = tail;



            // Update tail pointer to point to newly added node
            // tail becomes existing list and moves forward
            /*
             * Existing List:     [ prev | data1 | newNodeAddr ]  <-- tail
             *                             |
             *                             V
             * New Node (linked): [ tailAddr | data2 | NULL ]     <-- newNode
             */

            /*
             * Existing List: [ prev | data1 | newNodeAddr ]
             *                          |
             *                         V
             * New Tail:      [ oldTailAddr | data2 | NULL ]  <-- tail
             */
            tail = newNode;
        }
    }

    /**********************************************************************************************/

    // Traverse the doubly linked list in forward direction
    printf("\nTraversing the linked list forward:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    /**********************************************************************************************/

    // Traverse the doubly linked list in backward direction
    printf("\nTraversing the linked list backward:\n");
    temp = tail;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}