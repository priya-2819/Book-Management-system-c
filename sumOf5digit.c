#include<stdio.h>
void main()
{
    int no=73285;
    int r1,r2,r3,r4,r5,q1,q2,q3;
    int sum;

    r1 = no%10;
    q1 = no/10;
    r2= q1%10;
    q2 =q1/10;
    r3 = q2%10;
    q3 = q2/10;
    r4 = q3%10;
    r5 = q3/10;

    sum = r1 + r2 + r3 + r4 + r5;
    printf("sum is %d",sum);
}