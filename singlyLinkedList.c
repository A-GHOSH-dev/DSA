#include<stdlib.h>
#include<stdio.h>

struct node
{
      int information;
      struct node *link;
};

struct node *create_list(struct node *starting_node);
void display(struct node *starting_node);
void count(struct node *starting_node);
void search(struct node *starting_node, int data);
struct node *addatbeginning(struct node *starting_node, int data);
struct node *addatend(struct node *starting_node, int data);
struct node *addafter(struct node *starting_node, int data, int item);
struct node *addbefore(struct node *starting_node, int data, int item);
struct node *addatposition(struct node *starting_node, int data, int position);
struct node *deletenode(struct node *starting_node, int data);
struct node *reverselist(struct node *starting_node);

int main()
{
      struct node *starting_node = NULL;
      int option, data, item, position;
      while(1)
      {
            printf("\n1. Create a new linked list");
            printf("\n2. Display the elements of the linked list");
            printf("\n3. Count the total number of elements in the linked list");
            printf("\n4. Search an element in the linked list");
            printf("\n5. Add an element to beginning");
            printf("\n6. Add an element at the end");
            printf("\n7. Add an element after a node");
            printf("\n8. Add an element before a node");
            printf("\n9. Add an element at a position");
            printf("\n10. Delete an element in the linked list");
            printf("\n11. Reverse the singly linked list");
            printf("\n12. Quit");
            printf("\nEnter Your Choice:\t");
            scanf("%d", &option);
            switch(option)
            {
                  case 1: starting_node = create_list(starting_node);
                          break;
                  case 2: display(starting_node);
                          break;
                  case 3: count(starting_node);
                          break;
                  case 4: printf("\nEnter the element to search:\t");
                          scanf("%d", &data);
                          search(starting_node, data);
                          break;
                  case 5: printf("\nEnter the element to add at beginning:\t");
                          scanf("%d", &data);
                          starting_node = addatbeginning(starting_node, data);
                          break;
                  case 6: printf("\nEnter the element to insert at the end:\t");
                          scanf("%d", &data);
                          starting_node = addatend(starting_node, data);
                          break;
                  case 7: printf("\nEnter the element to be inserted after a node:\t");
                          scanf("%d", &data);
                          printf("\nEnter the element after which to insert:\t");
                          scanf("%d", &item);
                          starting_node = addafter(starting_node, data, item);
                          break;
                  case 8: printf("\nEnter the element to be insert before a nide:\t");
                          scanf("%d", &data);
                          printf("\nEnter the element before which to insert:\t");
                          scanf("%d", &item);
                          starting_node = addbefore(starting_node, data, item);
                          break;
                  case 9: printf("\nEnter the element to be inserted at a position:\t");
                          scanf("%d", &data);
                          printf("\nEnter the position at which to insert:\t");
                          scanf("%d", &position);
                          starting_node = addatposition(starting_node, data, position);
                          break;
                 case 10: printf("\nEnter the element to be deleted from the linked list:\t");
                          scanf("%d", &data);
                          starting_node = deletenode(starting_node, data);
                          break;
                 case 11: starting_node = reverselist(starting_node);
                          break;
                 case 12: exit(1);
                 default: printf("\nWrong Input. Enter a proper Input\n");
            }
      }
      return 0;
}

struct node *create_list(struct node *starting_node)
{
      int count, limit, data;
      printf("\nEnter the number of nodes:\t");
      scanf("%d", &limit);
      starting_node = NULL;
      if(limit == 0)
      {
            return starting_node;
      }
      printf("\nEnter the element to insert:\t");
      scanf("%d", &data);
      starting_node = addatbeginning(starting_node, data);
      for(count = 2; count <= limit; count++)
      {
            printf("\nEnter the element to insert:\t");
            scanf("%d", &data);
            starting_node = addatend(starting_node, data);
      }
      return starting_node;
}

void display(struct node *starting_node)
{
      struct node *new_node;
      if(starting_node == NULL)
      {
            printf("\nLinked list is empty");
            return;
      }
      new_node = starting_node;
      printf("\nLinked list elements:\n");
      while(new_node != NULL)
      {
            printf("%d\t", new_node -> information);
            new_node = new_node -> link;
      }
}

void count(struct node *starting_node)
{
      struct node *new_node;
      int total = 0;
      new_node = starting_node;
      while(new_node != NULL)
      {
            new_node = new_node -> link;
            total++;
      }
      printf("\nTotal number of elements in linked list:\t%d\n", total);
}

void search(struct node *starting_node, int item)
{
      struct node *new_node;
      int position = 1;
      new_node  = starting_node;
      while(new_node != NULL)
      {
            if(new_node -> information == item)
            {
                  printf("\nItem %d found at position no. %d", item, position);
                  return;
            }
            new_node = new_node -> link;
            position++;
      }
      printf("\nItem %d not found in linked list", item);
}

struct node *deletenode(struct node *starting_node, int data)
{
      struct node *new_node, *temp;
      if(starting_node == NULL)
      {
            printf("\nLinked list is empty");
            return starting_node;
      }
      if(starting_node -> information == data)
      {
            temp = starting_node;
            starting_node = starting_node -> link;
            free(temp);
            return starting_node;
      }
      new_node = starting_node;
      while(new_node -> link != NULL)
      {
            if(new_node -> link -> information == data)
            {
                  temp = new_node -> link;
                  new_node -> link = temp -> link;
                  free(temp);
                  return starting_node;
            }
            new_node = new_node -> link;
      }
      printf("\nElement %d not found in linked list", data);
      return starting_node;
}

struct node *reverselist(struct node *starting_node)
{
      struct node *prev, *next, *ptr;
      prev = NULL;
      ptr = starting_node;
      while(ptr != NULL)
      {
            next = ptr -> link;
            ptr -> link = prev;
            prev = ptr;
            ptr = next;
      }
      starting_node = prev;
      return starting_node;
}

struct node *addafter(struct node *starting_node, int data, int item)
{
      struct node *new_node, *temp;
      new_node = starting_node;
      while(new_node != NULL)
      {
            if(new_node -> information == item)
            {
                  temp = (struct node *)malloc(sizeof(struct node));
                  temp -> information = data;
                  temp -> link = new_node -> link;
                  new_node -> link = temp;
                  return starting_node;
            }
            new_node = new_node -> link;
      }
      printf("\n%d Element not present in linked list", item);
      return starting_node;
}

struct node *addatend(struct node *starting_node, int data)
{
      struct node *new_node, *temp;
      temp = (struct node *)malloc(sizeof(struct node));
      temp -> information = data;
      new_node = starting_node;
      while(new_node -> link != NULL)
      {
            new_node = new_node -> link;
      }
      new_node -> link = temp;
      temp -> link = NULL;
      return starting_node;
}

struct node *addatbeginning(struct node *starting_node, int data)
{
      struct node *temp;
      temp = (struct node *)malloc(sizeof(struct node));
      temp -> information = data;
      temp -> link = starting_node;
      starting_node = temp;
      return starting_node;
}

struct node *addbefore(struct node *starting_node, int data, int item)
{
      struct node *new_node, *temp;
      if(starting_node == NULL)
      {
            printf("\nLinked list is empty");
            return starting_node;
      }
      if(item == starting_node -> information)
      {
            temp = (struct node *)malloc(sizeof(struct node));
            temp -> information = data;
            temp -> link = new_node -> link;
            new_node -> link = temp;
            return starting_node;
      }
      new_node = new_node -> link;
      printf("\n%d element not present", item);
      return starting_node;
}

struct node *addatposition(struct node *starting_node, int data, int position)
{
      struct node *temp, *new_node;
      int count;
      temp = (struct node *)malloc(sizeof(struct node));
      temp -> information = data;
      if(position == 1)
      {
            temp -> link = starting_node;
            starting_node = temp;
            return starting_node;
      }
      new_node = starting_node;
      for(count = 1; count < position - 1 && new_node != NULL; count++)
      {
            new_node = new_node -> link;
      }
      if(new_node != NULL)
      {
            printf("There are less than %d element", position);
      }
      else
      {
            temp -> link = new_node -> link;
            new_node -> link = temp;
      }
      return starting_node;
}
