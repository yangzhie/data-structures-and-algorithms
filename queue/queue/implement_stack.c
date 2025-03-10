#include <stdio.h>

int main()
{
    return 0;
}

// Queue follows FIFO, but stack follows LIFO
// So if you have 5 3 7 in a queue and want to dequeue 5 (front)
// But front is where you insert from in queue and stack does not allow that
// So you have to dequeue 7 and 3 first to get to 5
// 5 3 7 --> 3 7 5 --> 3 7

int stack1[5];
int stack2[5];

int top1, top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == 5 - 1)
    {
        printf("Stack is full\n");
    }

    else
    {
        top1++;
        stack1[top1] = data;
    }
}

int pop1()
{
    if (top1 == -1)
    {
        printf("Stack is empty\n");
    }

    else
    {
        int data = stack1[top1];
        top1--;
        return data;
    }
}

void enqueue(int x)
{
    push1(x);
    count++; // Keep track of number of elements in the queue
}

void dequeue()
{
    int i;

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
    }

    else
    {
        // Pop/transfer all elements from stack1 to stack2
        for(i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);
        }

        // Actual element to be deleted
        int b = pop2();
        printf("Deleted element: %d\n", b);

        count--;

        // Push all elements back to stack1
        for(i = 0; i < count; i++)
        {
            int c = pop2();
            push1(c);
        }
    }
}

void display()
{
    for(int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
}