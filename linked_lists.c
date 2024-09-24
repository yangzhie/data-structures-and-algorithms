#include <stdio.h>

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


int main()
{
    printf("Linked Lists!\n");
}