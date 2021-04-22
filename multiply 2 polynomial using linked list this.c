#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef;
    int pow;
    struct node *next;
}poly;
menu()
{
    int ch;
    system("clear");
    printf("\n\t1)Create 1'st Polynomial ");
    printf("\n\t2)Create 2'nd Polynomial ");
    printf("\n\t3)Display");
    printf("\n\t4)Add Polynomials");
    printf("\n\tEnter your choice:");
    scanf("%d",&ch);
    return ch;
}
void b_sort(poly *head)
{
    poly *t1,*temp;
    int i,flag=1,scan;
    t1=(poly *)malloc(sizeof(poly));
    temp=(poly *)malloc(sizeof(poly));
    for(scan=1;flag==1;scan++)
    {
        temp=head->next;
        flag=0;
        for(i=0;i<head->coef-scan;i++)
        {
            if(temp->pow<temp->next->pow)
            {
                t1->coef=temp->coef;
                t1->pow=temp->pow;

                temp->coef=temp->next->coef;
                temp->pow=temp->next->pow;

                temp->next->coef=t1->coef;
                temp->next->pow=t1->pow;

                flag=1;
            }
            temp=temp->next;
        }
    }
}
void create(poly **head)
{
    int coef,pow;
    *head=(poly *)malloc(sizeof(poly));
    printf("\n\tEnter number of terms: ");
    scanf("%d",&(*head)->coef);
    (*head)->next=NULL;
    int i;
    poly *newnode;
    poly  *curr=*head;
    for(i=0;i<(*head)->coef;i++)
    {
        newnode=(poly *)malloc(sizeof(poly));
        system("clear");
        printf("\n\tEnter %d term: ",i+1);
        scanf("%d",&coef);
        printf("\n\tEnter power of %d term: ",i+1);
        scanf("%d",&pow);
        newnode->coef=coef;
        newnode->pow=pow;
        while(curr->next)
            curr=curr->next;
        curr->next=newnode;
        curr=newnode;
    }
    curr->next=NULL;
}
void display(poly *head)
{
    if(head==NULL)
        printf("\n\tEmpty\n");
    else
    {
        poly *temp=head->next;
        while(temp)
        {
            if(temp->next==NULL)
            {
                if(temp->pow==0)
                {
                    printf("%d",temp->coef);
                    return;
                }
                if(temp->pow==1)
                {
                    printf("%dx",temp->coef);
                    return;
                }
                else
                {
                    printf("%dx^%d",temp->coef,temp->pow);
                    return;
                }
            }
            else
            if(temp->pow==1)
                printf("%dx+",temp->coef);
            else
            if(temp->pow==0)
                printf("%d+",temp->coef);
            else
                printf("%dx^%d+",temp->coef,temp->pow);
            temp=temp->next;
        }
    }
}
void adddisplay(poly *head)
{
    if(head==NULL)
        printf("\n\tEmpty\n");
    else
    {
        poly *temp=head->next->next;
        while(temp)
        {
            if(temp->next==NULL)
            {
                if(temp->pow==0)
                {
                    printf("%d",temp->coef);
                    return;
                }
                if(temp->pow==1)
                {
                    printf("%dx",temp->coef);
                    return;
                }
                else
                {
                    printf("%dx^%d",temp->coef,temp->pow);
                    return;
                }
            }
            else
            if(temp->pow==1)
                printf("%dx+",temp->coef);
            else
            if(temp->pow==0)
                printf("%d+",temp->coef);
            else
                printf("%dx^%d+",temp->coef,temp->pow);
            temp=temp->next;
        }
    }
}
poly *add(poly *head1,poly *head2)
{
    poly *head3=NULL;
    poly *curr1,*curr2,*curr3;
    curr1=head1; curr2=head2; curr3=head3;
    poly *newnode;
    head3=(poly *)malloc(sizeof(poly));
    curr3=head3;
    while(curr1||curr2)
    {
        newnode=(poly *)malloc(sizeof(poly));
        newnode->next=NULL;
        if(curr1->pow>curr2->pow)
        {
            newnode->coef=curr1->coef;
            newnode->pow=curr1->pow;
            curr1=curr1->next;
        }
        else
        if(curr1->pow<curr2->pow)
        {
            newnode->coef=curr2->coef;
            newnode->pow=curr2->pow;
            curr2=curr2->next;
        }
        else
        {
            newnode->coef=curr1->coef+curr2->coef;
            newnode->pow=curr2->pow;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(curr1==NULL&&curr2!=NULL)
        {
            newnode->coef=curr2->coef;
            newnode->pow=curr2->pow;
            curr2=curr2->next;
        }
        if(curr2==NULL&&curr1!=NULL)
        {
            newnode->coef=curr1->coef;
            newnode->pow=curr1->pow;
            curr1=curr1->next;
        }
        curr3->next=newnode;
        curr3=newnode;
        curr3->next=NULL;
    }
    return head3;
}
main()
{
    int ch;
    poly *head1=NULL;
    poly *head2=NULL;
    while((ch=menu())!=0)
    {
        if(ch==1)
            create(&head1);
        else
        if(ch==2)
            create(&head2);
        else
        if(ch==3)
        {
            printf("\n\t1'st Polynomial\t\t");
            display(head1);
            printf("\n");
            printf("\n\t2'nd Polynomial\t\t");
            display(head2);
            getchar();getchar();
        }
        else
        if(ch==4)
        {
            poly *head3=NULL;
            b_sort(head1);
            b_sort(head2);
            head3=add(head1,head2);
            printf("\n\tResult\t\t");
            adddisplay(head3);
            getchar();getchar();
        }
    }
}
