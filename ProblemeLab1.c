
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//problema 4
//raspunsuri: n / 2, if (n%2==0), false, n

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

    //problema 3
    char string[1000], words[25][200], aux[200];
    int i=0;
    scanf("%s", string);
    char* token=strtok(string, " ");
    while (token!=NULL){
        words[i][200]=token;
        token=strtok(NULL, " ");
        i++;
    }
    for(int k=0;k<i;k++)
      for(int j=k+1;j<i;j++) if(strlen(words[k][200])<strlen(words[j][200])) {strcpy(aux, words[k][200]);
         strcpy(words[k][200], words[j][200]);
         strcpy(words[j][200], aux);
         }
           else if(strlen(words[k][200])==strlen(words[j][200]))  if(strcmp(words[k][200],words[j][200])>0) {strcpy(aux, words[k][200]);
         strcpy(words[k][200], words[j][200]);
         strcpy(words[j][200], aux);
         }

     for(int k=0;k<=i;k++) printf("%s/n", words[k][200]);

    
    return 0;
}
