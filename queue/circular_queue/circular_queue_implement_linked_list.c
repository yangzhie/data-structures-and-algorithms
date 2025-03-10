#include <stdio.h>

// Implement using circular linked list

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

// Head and tail pointers should be maintained
// Need tail pointer to insert at the end

void enqueue(int x)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
        tail->next = head;
    }

    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void dequeue()
{
    struct node *temp;
    temp = head;

    if (head == NULL && tail == NULL)
    {
        printf("Queue is empty\n");
    }

    else if (head == tail)
    {
        printf("Deleted element: %d\n", head->data);
        head = tail = NULL;
        free(temp);
    }

    else
    {
        printf("Deleted element: %d\n", head->data);
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void display() 
{
    struct node *temp;
    temp = head;

    if (head == NULL && tail == NULL)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("Elements in the queue are: ");
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void peek()
{
    if (head == NULL && tail == NULL)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("Front element: %d\n", head->data);
    }
}