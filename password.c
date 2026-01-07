#include<stdio.h>
#include<string.h>
void main()
{
    char str[] ="fbs@Pass123";
    int res = isvalidPassword(str);
    if (res==1)
        printf("Valid Password");
    else
        printf("Invalid Password");    
}

int isvalidPassword(char* str)
{
    int hasUpper=0, hasDigit=0, hasSpecial=0;
    int length = strlen(str);

    if (length<=5)
        return 0;

    for(int i=0; i< length; i++) 
    {
        if(str[i]>='A' && str[i]<='Z')
            hasUpper = 1;

        else if(str[i]>='0' && str[i]<='9')
            hasDigit= 1;     

        else if ((str[i]< 'A' || str[i] > 'Z') &&  (str[i]< 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
            hasSpecial = 1;    
    }   

    if(hasUpper && hasDigit && hasSpecial)
        return 1;
    else
        return 0;    
}