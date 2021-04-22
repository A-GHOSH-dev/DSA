//Sum of Digits Till Single Digit :

#include<stdio.h>
int main(void)
{
    long num;
    int dig,sum;
    printf("Enter any number : ");
    scanf("%ld",&num);
    printf("%ld-> ",num);
    do
    {
        sum = 0;
        while(num!=0)
        {
            dig=num%10;
            sum+=dig;
            num/=10;
        }
        printf("%d-> ",sum);
        num=sum;
    }while(num/10!=0);
    return 0;
}
//Output:

//Terminal
//Enter any number : 586596
//586596-> 39-> 12-> 3
