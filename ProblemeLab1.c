
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//problema 4
bool isPrime(int n)

{

    for (int tr = 2; tr < n / 2; tr++)

        if ((n % tr ) == 0)

            return false;

    return true;

}

int main()

{

    int n;

    std::cout << "Enter a number:";

    std::cin >> n;

    if (isPrime(n))

        std::cout << n << " is prime !";

    else 

        std::cout << n << " is NOT prime !";

    return 0;

}



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
