#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0, *temp;

int main()
{
    return 0;
}

void delete_from_beginning()
{
    // We can simply point the head to the second node instead of the first
    // This destroys the link to the first node
    // But the first node will still have some data
    // So we have to free that memory (free the garbage)

    temp = head;

    // Can access the address part of the first node by either temp or head
    // Now head contains the address of the second node instead of first
    // Link has been destroyed
    head = head->next;

    // Since temp is still pointing to the first node, we can free it from temp
    free(temp);
}

void delete_from_end()
{
    // If you store NULL/0 in the second last node, it would mean it doesn't point anywhere
    // So the last node is detached from the list
    // Will have to traverse the list till last node
    // You will also need to free the memory of former-last node

    // We will have to maintain two pointers
    // One for freeing the space, one for updating the second last node
    struct node *prevNode;

    // temp points to first node
    temp = head;

    // Essentially, the loop becomes un-true at the last node
    // By that time, temp becomes 0 but the prevNode is not updated because the control becomes un-true
    // Thus, the prevNode actually points to the second last node and temp points to last node (genius!)
    while (temp->next != 0)
    {
        // Maintain prevNode alongside temp so they can traverse together
        prevNode = temp;
        // Then move temp onto next node
        temp = temp->next;
    }

    // Setting second last node's address part to NULL/0
    prevNode->next = 0;
    // Freeing last node memory
    free(temp);
}

void delete_from_specific_position()
{
    // If you delete a node from a position, say 3, then the link of 2 needs to connect to the link of 4
    // So in 2's address part, 4's address needs to be stored instead of 3's
    // To reach 3, travsersal of the list is needed
    // We will maintain two pointers, one to reach specified position (nextNode), one to reach the node before the specified position (temp (pos - 1))

    struct node *nextNode;

    int position;
    int i = 1;

    // At the moment, in temp we have start address to first node, nextNode has nothing
    temp = head;

    // User input
    printf("Enter position: \n");
    scanf("%d", &position);

    // At the moment, i = 1 and position - 1 only goes up to 
    // This goes on until the node before (prevNode) the desired node to be removed
    while(i < position - 1)
    {
        // Move temp until position - 1
        // Points to the node after temp at the end of the control flow
        temp = temp->next;
        i++;
    }

    // This is the node to be removed
    // Assigns the address of the node following temp (i.e., the node that temp->next points to) to nextNode
    // Essentially, nextNode now points to the node that comes after temp in the linked list
    nextNode = temp->next;

    // Now we can update the prevNode and then free the node to be removed

    // THIS MAKES SENSE
    // nextNode's address part is nextNode->next
    // temp is currently pointing to the node before the node to be removed's
    // So, we update the address part of temp to point to the node after one to be removed (access thru nextNode->next)
    temp->next = nextNode->next;

    // Frees the actual node data at position
    free(nextNode);
}