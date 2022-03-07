#include "Math.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<cstddef>

int Math::Add(int a,int b)
{
   return a+b;
}

int Math::Add(int a,int b,int c)
{
   return a+b+c;
}

int Math::Add(double a,double b)
{
    return (int)a+b;
}
    
int Math::Add(double a,double b,double c)
{
    return (int)a+b+c;
}


int Math::Mul(int a,int b,int c)
{
    return a*b*c;
}

int Math::Mul(double a,double b)
{
    return (int)a*b;
}

int Math::Mul(double a,double b,double c)
{
  return (int)a*b*c;
}

int Math::Add(int count,...)
{
   int i, sum=0;
   va_list vl;
   va_start(vl, count);
   for(i=0;i<count;i++) sum+=va_arg(vl, int);
   return sum;
} // sums up a list of integers

char* Math::Add(const char * sir1, const char * sir2)
{
    if(sir1==nullptr or sir2==nullptr) return nullptr;
    int size;
    size=strlen(sir1)+strlen(sir2)+1;
    char* name;
    name=(char*)malloc(size);
    memset(name, 0, size);
    memcpy(name, sir1, strlen(sir1));
    memcpy(name+strlen(sir1), sir2, strlen(sir2));
    return name;
}