#include <stdio.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head, *tail;

int main()
{
    return 0;
}

// head and tail pointers should be maintained
// Need tail pointer to insert at the end

void enqueue(int x)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = 0;

    // Case 1: If queue is empty
    if (head == 0 && tail == 0)
    {
        head = tail = newNode; // newNode's address is stored in both head and tail
    }
    // Case 2: If queue is not empty
    else
    {
        // Always insert from rear end, thus only touch tail
        tail->next = newNode;
        // Move tail to the new node
        tail = newNode;
    }
}

void dequeue() // Always the front data would be deleted
{
    struct node *temp;
    temp = head;

    // Case 1: If queue is empty
    if (head == 0 && tail == 0)
    {
        printf("Queue is empty\n");
    }
    // Case 2: If queue is not empty
    else
    {
        // Move head to the next node
        head = head->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = head;

    // Case 1: If queue is empty
    if (head == 0 && tail == 0)
    {
        printf("Queue is empty\n");
    }
    // Case 2: If queue is not empty
    else
    {
        temp = head;
        while(temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    // Case 1: If queue is empty
    if (head == 0 && tail == 0)
    {
        printf("Queue is empty\n");
    }
    // Case 2: If queue is not empty
    else
    {
        printf("Front element: %d\n", head->data);
    }
}