#include <stdio.h>

int main()
{
}

int deque[5];
int front, rear = -1;

void enqueue_front(int x)
{
    // Case: queue is full
    if ((front == 0 && rear == 4) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }

    // Case: queue is empty
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }

    // Case: first element
    // We insert front front by going *backwards* in the array
    else if (front == 0)
    {
        front = 5 - 1;
        deque[front] = x;
    }

    // Case: normal
    else
    {
        front--;
        deque[front] = x;
    }
}

void enqueue_rear(int x)
{
    // Case: queue is full
    if ((front == 0 && rear == 4) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }

    // Case: queue is empty
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }

    // Case: last element
    // We insert rear rear by going *forward* in the array
    else if (rear == 5 - 1)
    {
        rear = 0;
        deque[rear] = x;
    }

    // Case: normal
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void display()
{
    int i = front; // Start printing from the front

    while(i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % 5; // Remember, this is a circular queue!
    }

    printf("%d\n", deque[rear]); // We exclude the last value in the while loop
}

void get_front()
{
    printf("Front element: %d\n", deque[front]);
}

void get_rear()
{
    printf("Rear element: %d\n", deque[rear]);
}

void dequeue_front()
{
    // Case: queue is empty
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case: only one element
    else if(front == rear)
    {
        printf("Deleted element: %d\n", deque[front]);
        front = rear = -1;
    }

    // Case: last element
    else if(front == 5 - 1)
    {
        printf("Deleted element: %d\n", deque[front]);
        front = 0;
    }

    // Case: normal
    else
    {
        printf("Deleted element: %d\n", deque[front]);
        front++;
    }
}

void dequeue_rear()
{
    // Case: queue is empty
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    // Case: only one element
    else if(front == rear)
    {
        printf("Deleted element: %d\n", deque[rear]);
        front = rear = -1;
    }

    // Case: first element
    else if(rear == 0)
    {
        printf("Deleted element: %d\n", deque[rear]);
        rear = 5 - 1;
    }

    // Case: normal
    else
    {
        printf("Deleted element: %d\n", deque[rear]);
        rear--;
    }
}