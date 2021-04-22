#include<stdio.h>

int main()
{
    int a[20],i,x,n;
    printf("Number of elements: \n");
    scanf("%d",&n);

    printf("Enter array elements: \n");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);

    printf("x= ");
    scanf("%d",&x);

    for(i=0;i<n;++i)
        if(a[i]==x)
            break;

    if(i<n)
        printf("%d Element x is present at index %d",x,i);
    else
        printf("%d Element x is not present",x);

    return 0;
}
