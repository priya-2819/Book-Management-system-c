#include<stdio.h>
#include<string.h>

void main()
{
    char str[10];
    printf("Enter the string:");
    scanf("%s",str);
    int res = mystrlen(str);
}
int mystrlen(char* str)
{
    int i =0, count =0;
    while(str[i]!='\0')
    {
        count++;

    }
    i++;

    printf("length of string %d",count);
}