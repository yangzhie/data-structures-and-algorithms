#include <stdio.h>

int queue[5];

int front = -1;
int rear = -1;

int main()
{
}

// Drawbacks of linear queues is wasteage of space after dequeueing elements
// 1 -2 3 6 6 --> - - 3 6 6 -- > 2 - 3 6 6
// They basically go in an infinite loop of enqueue and dequeue

// For these functions, queue[i]/queue[n] just means the ith/nth element in the queue

void enqueue(int x)
{
    // Case 1: If queue is empty
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }

    // Case 2: If queue is full
    else if ((rear + 1) % 5 == front) // circular queue
    {
        printf("Queue is full\n");
    }

    // Case 3: If queue is not empty
    else
    {
        rear = (rear + 1) % 5; // (rear + 1) % N, where N = size of queue
        queue[rear] = x;
    }
}

void dequeue()
{
    // Case 1: If queue has only one element
    if (front == rear)
    {
        // After deleting the only element, the queue becomes empty
        front = rear = -1;
    }

    // Case 2: If queue is empty
    else if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case 3: If queue is not empty
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front = (front + 1) % 5;
    }
}

void display()
{
    int i = front;

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("Elements in the queue are: ");

        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % 5;
        }

        // Print last element as it was not in loop
        printf("%d\n", queue[rear]);
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("Element at front: %d\n", queue[front]);
    }
}