/*Given a singly linked list, a position and an element, the task is to write a program to insert that element in a linked list at a given position.
Examples:


Input: 3->5->8->10, data = 2, position = 2
Output: 3->2->5->8->10

Input: 3->5->8->10, data = 11, position = 5
Output: 3->5->8->10->11*/


// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

// A linked list Node
struct Node {
	int data;
	struct Node* next;
};

// Size of linked list
int size = 0;

// function to create and return a Node
Node* getNode(int data)
{
	// allocating space
	Node* newNode = new Node();

	// inserting the required data
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// function to insert a Node at required position
void insertPos(Node** current, int pos, int data)
{
	// This condition to check whether the
	// position given is valid or not.
	if (pos < 1 || pos > size + 1)
		cout << "Invalid position!" << endl;
	else {

		// Keep looping until the pos is zero
		while (pos--) {

			if (pos == 0) {

				// adding Node at required position
				Node* temp = getNode(data);

				// Making the new Node to point to
				// the old Node at the same position
				temp->next = *current;

				// Changing the pointer of the Node previous
				// to the old Node to point to the new Node
				*current = temp;
			}
			else
			// Assign double pointer variable to point to the
			// pointer pointing to the address of next Node
			current = &(*current)->next;
		}
		size++;
	}
}

// This function prints contents
// of the linked list
void printList(struct Node* head)
{
	while (head != NULL) {
		cout << " " << head->data;
		head = head->next;
	}
	cout << endl;
}

// Driver Code
int main()
{
	// Creating the list 3->5->8->10
	Node* head = NULL;
	head = getNode(3);
	head->next = getNode(5);
	head->next->next = getNode(8);
	head->next->next->next = getNode(10);

	size = 4;

	cout << "Linked list before insertion: ";
	printList(head);

	int data = 12, pos = 3;
	insertPos(&head, pos, data);
	cout << "Linked list after insertion of 12 at position 3: ";
	printList(head);

	// front of the linked list
	data = 1, pos = 1;
	insertPos(&head, pos, data);
	cout << "Linked list after insertion of 1 at position 1: ";
	printList(head);

	// insetion at end of the linked list
	data = 15, pos = 7;
	insertPos(&head, pos, data);
	cout << "Linked list after insertion of 15 at position 7: ";
	printList(head);

	return 0;
}

//Linked list before insertion:  3 5 8 10
//Linked list after insertion of 12 at position 3:  3 5 12 8 10
//Linked list after insertion of 1 at position 1:  1 3 5 12 8 10
//Linked list after insertion of 15 at position 7:  1 3 5 12 8 10 15




//C:
#include<stdio.h>
#include<stdlib.h>
void randominsert(int);
void create(int);
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void main ()
{
    int choice,item,loc;
    do
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d",&item);
        if(head == NULL)
        {
            create(item);
        }
        else
        {
            randominsert(item);
        }
        printf("\nPress 0 to insert more ?\n");
        scanf("%d",&choice);
    }while(choice == 0);
}
void create(int item)
{

        struct node *ptr = (struct node *)malloc(sizeof(struct node *));
        if(ptr == NULL)
        {
            printf("\nOVERFLOW\n");
        }
        else
        {
            ptr->data = item;
            ptr->next = head;
            head = ptr;
            printf("\nNode inserted\n");
        }
}
void randominsert(int item)
    {
        struct node *ptr = (struct node *) malloc (sizeof(struct node));
        struct node *temp;
        int i,loc;
        if(ptr == NULL)
        {
            printf("\nOVERFLOW");
        }
        else
        {

            printf("Enter the location");
            scanf("%d",&loc);
            ptr->data = item;
            temp=head;
            for(i=0;i<loc;i++)
            {
                temp = temp->next;
                if(temp == NULL)
                {
                    printf("\ncan't insert\n");
                    return;
                }

            }
            ptr ->next = temp ->next;
            temp ->next = ptr;
            printf("\nNode inserted");
        }

    }
Output

Enter the item which you want to insert?
12

Node inserted

Press 0 to insert more ?
2

