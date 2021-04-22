#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
}*top = NULL;

int isEmpty()
{
      if(top == NULL)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}

void push(int item)
{
      struct node *temp;
      temp = (struct node *)malloc(sizeof(struct node));
      if(temp == NULL)
      {
            printf("Stack is Full\n");
            return;
      }
      temp->data = item;
      temp->link = top;
      top = temp;
}

int delete_node()
{
      struct node *temp;
      int item;
      if(isEmpty())
      {
            printf("Stack is Empty\n");
            exit(1);
      }
      temp = top;
      item = temp->data;
      top = top->link;
      free(temp);
      return item;
}

void display()
{
      struct node *ptr;
      if(isEmpty())
      {
            printf("Stack is Empty\n");
            return;
      }
      printf("Stack Elements:\n\n");
      for(ptr = top; ptr != NULL; ptr = ptr->link)
      {
            printf(" %d\n", ptr->data);
      }
      printf("\n");
}

int peek()
{
      if(isEmpty())
      {
            printf("Stack is Empty\n");
            exit(1);
      }
      return top->data;
}

int main()
{
      int option, element;
      while(1)
      {
            printf("1. Push an Element on the Stack\n");
            printf("2. delete_node or Delete an Element from the Stack\n");
            printf("3. Display Top-most item of the Stack\n");
            printf("4. Display All Element of the Stack\n");
            printf("5. Exit\n");
            printf("Enter your Option:\t");
            scanf("%d", &option);
            switch(option)
            {
                  case 1:
                          printf("Enter the item to be Pushed on the Stack:\t");
                          scanf("%d", &element);
                          push(element);
                          break;
                  case 2:
                          element = delete_node();
                          printf("Deleted Element:\t%d\n", element);
                          break;
                  case 3:
                          printf("Element at the Top of Stack:\t%d\n", peek());
                          break;
                  case 4:
                          display();
                          break;
                  case 5:
                          exit(1);
                  default:
                          printf("Wrong Option Selected\n");
            }
      }
      return 0;
}

