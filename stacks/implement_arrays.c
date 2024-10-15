#include <stdio.h>

#define N 5

int stack[N];
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    push();
    pop();
    peek();
    display();
}

void push()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    if (top == N - 1) // Case: stack is full
    {
        printf("Overflow Condition.");
    }
    else
    {
        // Increment top
        top++;

        // Insert data at the new position top is at
        stack[top] = x;
    }
}

void pop()
{
    int item;

    if (top == -1) // Case: no data in stack
    {
        printf("Underflow Condition.");
    }
    else
    {
        // Before deleteing/decrementing, store the item so it can be shown (optional)
        item = stack[top];

        // Decrement top
        top--;

        printf("Item: %d", item);
    }
}

// AKA Top operation
void peek()
{
    if (top == -1) // Case: empty stack
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

// Traverse the stack from the top
void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}