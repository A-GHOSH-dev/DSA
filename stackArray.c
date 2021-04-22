#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int top = -1;
int stack_array[MAX];

int pop();
int peek();
int isEmpty();
int isFull();
void display();
int element;
void push(int element);

int main()
{
    int option,element;
    while(1)
    {
        printf("\n1. Push / Insert An Element in Stack");
        printf("\n2. Pop / Delete An Element From Stack");
        printf("\n3. Display All Contents of Stack");
        printf("\n4. Display Top-Most Content of Stack");
        printf("\n5. Exit\n");
        printf("\nSelect an Option:\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\nEnter The Element To Be Inserted:\t");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                element = pop();
                printf("Element Deleted:\t%d",element);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Top-Most Element of Stack:\t%d",peek());
                break;

            case 5: exit(1);
        }
    }
    return 0;
}

int pop()
{
    if(isEmpty())
    {
        printf("\nStack Undeflow\n");
        exit(1);
    }
    else
    {
        element = stack_array[top];
        top = top - 1;
        return element;
    }
}

int peek()
{
    if(isEmpty())
    {
        printf("\nStack Undeflow\n");
        return 1;
    }
    else
    {
        return stack_array[top];
    }
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top == MAX - 1)
        return 1;
    else
        return 0;
}

void display()
{
    int count;
    if(isEmpty())
    {
        printf("\nStack is Empty\n");
        return;
    }
    else
    {
        for(count = top; count >= 0; count--)
        {
            printf("%d\t",stack_array[count]);
        }
    }
}

void push(int element)
{
    if(isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack_array[top] = element;
    }
}
