#include <stdio.h>

// Static memory allocation because arrays are fixed size
// Array must follow FIFO

int queue[5];

// The -1 means that the queue is empty
int front = -1;
int rear = -1;

int main()
{
}

void enqueue(int x)
{
    // Case 1: If queue is full
    if (rear == 5 - 1)
    {
        printf("Queue is full\n");
    }

    // Case 2: If queue is empty
    else if (front == -1 && rear == -1)
    {
        // Both front and rear would be increased and point to 0
        front = rear = 0;
        queue[rear] = x; // Inserting from rear (queue[0] = x)
    }

    // Case 3: If queue is not empty
    else
    {
        rear++; // move rear to the next position
        queue[rear] = x;
    }
}

void dequeue()
{
    // Case 1: If queue is empty
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case 2: If queue has only one element
    else if (front == rear)
    {
        front = rear = -1; // Empty the queue
    }

    // Case 3: If queue has more than one element
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++; // Move front to the next position
    }
}

void display()
{
    // Case 1: If queue is empty
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case 2: If queue is not empty
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void peek()
{
    // Case 1: If queue is empty
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case 2: If queue is not empty
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}