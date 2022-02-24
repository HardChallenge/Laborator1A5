
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{ //problema 2
    FILE* fisier;
    if(fopen_s(&fisier, "laborator1", "r") != 0)
    {
        printf("Acest fisier nu s-a deschis");
    }
    else {
        printf("Am deschis fisierul");
        int number, sum=0, i;
        char theString[100];
        while(fgets(theString, 100, fisier))
        {
            number=0;
            for(i=0;i<strlen(theString)-1;i++) number=number*10+(int)theString[i]-'0';
            sum+=number;
        }

    }
    
    return 0;
}
