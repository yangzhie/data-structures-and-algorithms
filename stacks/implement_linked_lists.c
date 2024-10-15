#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

// Imagine this as head
struct node *top = 0;

int main()
{
    return 0;
}

// We will always push and pop from the beginning (node that head points to)
void push(int x) // Argument to be pushed
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;   // User data stored
    newNode->next = top; // Update the new node to point to last node created

    // Update top
    top = newNode;
}

void pop()
{
    struct node *temp;
    temp = top;

    if (top == 0)
    {
        printf("List is empty.");
    }
    else
    {
        printf("Popped element is: %d", top->data);

        // Now we remove the top
        top = top->next;

        // Free it
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = top;

    if (top == 0)
    {
        printf("List is empty.");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    if (top == 0)
    {
        printf("List is empty.");
    }
    else
    {
        printf("Top element is: %d", top->data);
    }
}
