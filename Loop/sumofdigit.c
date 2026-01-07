#include <stdio.h>
void main()
{
    int no = 12345;
    int rem,sum=0;
    while(no>0)
    {
       no = no%10;
       sum = sum + rem; 
        no = no/10;
    }
}