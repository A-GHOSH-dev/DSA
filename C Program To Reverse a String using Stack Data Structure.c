//C Program To Reverse a String using Stack Data Structure

#include<stdio.h>
#include<string.h>

#define MAX 20

int element;
int top = -1;
char stack_array[MAX];
void push(char element);
int isEmpty();
int isFull();
char pop();

void main()
{
        char stack_string[30];
        int count;
        printf("Enter A String:\t");
        scanf("%s", stack_string);
        for(count = 0; count < strlen(stack_string); count++)
        {
                push(stack_string[count]);
        }
        for(count = 0; count < strlen(stack_string); count++)
        {
                stack_string[count] = pop();
        }
        printf("%s", stack_string);
        printf("\n");
}

void push(char element)
{
        if(isFull())
        {
                printf("\nStack Overflow\n");
        }
        else
        {
                top = top + 1;
                stack_array[top] = element;
        }
}

char pop()
{
        if(isEmpty())
        {
                printf("\nStack Underflow\n");
                return 1;
        }
        else
        {
                element = stack_array[top];
                top = top - 1;
                return element;
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
        if(top == MAX-1)
                return 1;
        else
                return 0;
}
