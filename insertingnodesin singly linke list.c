#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

Node *
insertNodeAtPosition(Node *head, int data, int position)
{
    int i = 0;
    Node *prev;
    Node *pcurr;
    Node *pnew;

    pnew = malloc(sizeof(Node));
    pnew->data = data;

    // find the correct place to insert
    prev = NULL;
    for (pcurr = head;  pcurr != NULL;  pcurr = pcurr->next, i += 1) {
        if (i >= position)
            break;
        prev = pcurr;
    }

    // link up the element that will follow the new node
    pnew->next = pcurr;

    // insert into middle or end of list
    if (prev != NULL)
        prev->next = pnew;

    // insert into empty list or _before_ the first node
    else
        head = pnew;

    return head;
}

void
printlist(Node *head)
{
    Node *pcurr;

    printf("List:");

    for (pcurr = head;  pcurr != NULL;  pcurr = pcurr->next)
        printf(" %d",pcurr->data);

    printf("\n");
}

int
main(void)
{
    FILE *fi;
    Node *head = NULL;
    int count;
    int newval;
    int pos;

    fi = fopen("input.txt","r");
    if (fi == NULL) {
        perror("input.txt");
        exit(1);
    }

    fscanf(fi," %d",&count);

    for (int i = 0;  i < count;  ++i) {
        fscanf(fi," %d",&newval);
        printf("new: %d\n",newval);
        head = insertNodeAtPosition(head,newval,count + 10);
    }
    printlist(head);

    while (1) {
        if (fscanf(fi," %d %d",&newval,&pos) != 2)
            break;
        printf("insert: %d at %d\n",newval,pos);
        head = insertNodeAtPosition(head,newval,pos);
    }
    printlist(head);

    fclose(fi);

    return 0;
}
