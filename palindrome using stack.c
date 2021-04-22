
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
/* push a character into stack */
void push(char a)
{
top++;
stack[top] = a;
}
/* delete an element in stack */
void pop()
{
top--;
}
int main()
{ int i, cho;
char s[MAX], b;
printf("\tMENU");
printf("\n---------------------------\n");
printf("1.Check string is palindrome.\n2.Exit\n");printf("---------------------------\n");
while (1)
{
printf("Choose operation : ");
scanf("%d", &cho);
switch (cho)
{
case 1:
printf("\nEnter string : ");
scanf("%s", s);
for (i = 0;s[i] != '\0';i++)
{
b = s[i];
push(b);
}
for (i = 0;i < (strlen(s) / 2);i++)
{ if (stack[top] == stack[front])
{
pop();
front++;
}else
{
printf("'%s' is not palindrome.\n\n", s);
break;
}
}
if ((strlen(s) / 2)== front)
printf("'%s' is palindrome.\n\n", s);
front = 0;
top = -1;
break;
case 2:
exit(0);
default: printf("Invalid operation \n");
}
}
return 0;}
