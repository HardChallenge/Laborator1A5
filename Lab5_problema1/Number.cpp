#include<iostream>
#include<string.h>
#include"Number.h"
#include<cmath>

Number::Number(const char * value, int base)
{
    this->base=base;
    this->value=(char*)malloc(strlen(value)+1);
    memset(this->value, 0, strlen(value)+1);
    strcpy(this->value, value);
}

Number::~Number()
{
    this->base=0;
    free(this->value);
    value=nullptr;
}

Number::Number(const Number& object)
{
    this->base=object.base;
    strcpy(this->value, object.value);
}

Number::Number(Number&& object): base(object.base), value(object.value)
{
    object.base=0;
    free(value);
    value=nullptr;
}

Number& operator+(Number &object, Number &object2)
{
   int i=0,p=0, j=0;
     char sir[255];
   if(object.base>object2.base)
   { 
     
     for(int z=strlen(object2.value)-1;z>=0;z--)
   {
       if(object2.value[z]=='A' || object2.value[z]=='B' || object2.value[z]=='C' || object2.value[z]=='D' || object2.value[z]=='E' || object2.value[z]=='F')
          i+=(int)(object2.value[z]-55)*pow(object2.base, p);
        else i+=(int)(object2.value[z]-48)*pow(object2.base, p);
        p++;
   } 
   for(int z=strlen(object.value)-1;z>=0;z--)
   {
       if(object.value[z]=='A' || object.value[z]=='B' || object.value[z]=='C' || object.value[z]=='D' || object.value[z]=='E' || object.value[z]=='F')
          j+=(int)(object.value[z]-55)*pow(object.base, p);
        else j+=(int)(object.value[z]-48)*pow(object.base, p);
        p++;
   } 
    i+=j;
    int d=0;
    while(i)
    {
        if(i%object.base<=9) sir[p]=(char)(i%object.base+48);
          else switch(i%object.base){
              case 10: {sir[p]='A'; break;}
              case 11: {sir[p]='B'; break;}
              case 12: {sir[p]='C'; break;}
              case 13: {sir[p]='D'; break;}
              case 14: {sir[p]='E'; break;}
              case 15: {sir[p]='F'; break;}
              default: break;
          }
        i=i/object.base;
        d++;
        p++;
    } 
    p=0;
    for(i=d-1;i>=0;i--)
    {
        object.value[p]=sir[i];
        p++;
    }
    return object;
   }   
   else {
       for(int z=strlen(object2.value)-1;z>=0;z--)
   {
       if(object2.value[z]=='A' || object2.value[z]=='B' || object2.value[z]=='C' || object2.value[z]=='D' || object2.value[z]=='E' || object2.value[z]=='F')
          i+=(int)(object2.value[z]-55)*pow(object2.base, p);
        else i+=(int)(object2.value[z]-48)*pow(object2.base, p);
        p++;
   } 
   for(int z=strlen(object.value)-1;z>=0;z--)
   {
       if(object.value[z]=='A' || object.value[z]=='B' || object.value[z]=='C' || object.value[z]=='D' || object.value[z]=='E' || object.value[z]=='F')
          j+=(int)(object.value[z]-55)*pow(object.base, p);
        else j+=(int)(object.value[z]-48)*pow(object.base, p);
        p++;
   } 
    i+=j;
    int d=0;
    while(i)
    {
        if(i%object.base<=9) sir[p]=(char)(i%object.base+48);
          else switch(i%object.base){
              case 10: {sir[p]='A'; break;}
              case 11: {sir[p]='B'; break;}
              case 12: {sir[p]='C'; break;}
              case 13: {sir[p]='D'; break;}
              case 14: {sir[p]='E'; break;}
              case 15: {sir[p]='F'; break;}
              default: break;
          }
        i=i/object.base;
        d++;
        p++;
    } 
    p=0;
    for(i=d-1;i>=0;i--)
    {
        object.value[p]=sir[i];
        p++;
    }
    return object;

   }

}


Number& operator-(Number &object, Number &object2)
{
   int i=0,p=0, j=0;
     char sir[255];
   if(object.base>object2.base)
   { 
     
     for(int z=strlen(object2.value)-1;z>=0;z--)
   {
       if(object2.value[z]=='A' || object2.value[z]=='B' || object2.value[z]=='C' || object2.value[z]=='D' || object2.value[z]=='E' || object2.value[z]=='F')
          i+=(int)(object2.value[z]-55)*pow(object2.base, p);
        else i+=(int)(object2.value[z]-48)*pow(object2.base, p);
        p++;
   } 
   for(int z=strlen(object.value)-1;z>=0;z--)
   {
       if(object.value[z]=='A' || object.value[z]=='B' || object.value[z]=='C' || object.value[z]=='D' || object.value[z]=='E' || object.value[z]=='F')
          j+=(int)(object.value[z]-55)*pow(object.base, p);
        else j+=(int)(object.value[z]-48)*pow(object.base, p);
        p++;
   } 
    i-=j;
    int d=0;
    while(i)
    {
        if(i%object.base<=9) sir[p]=(char)(i%object.base+48);
          else switch(i%object.base){
              case 10: {sir[p]='A'; break;}
              case 11: {sir[p]='B'; break;}
              case 12: {sir[p]='C'; break;}
              case 13: {sir[p]='D'; break;}
              case 14: {sir[p]='E'; break;}
              case 15: {sir[p]='F'; break;}
              default: break;
          }
        i=i/object.base;
        d++;
        p++;
    } 
    p=0;
    for(i=d-1;i>=0;i--)
    {
        object.value[p]=sir[i];
        p++;
    }
    return object;
   }   
   else {
       for(int z=strlen(object2.value)-1;z>=0;z--)
   {
       if(object2.value[z]=='A' || object2.value[z]=='B' || object2.value[z]=='C' || object2.value[z]=='D' || object2.value[z]=='E' || object2.value[z]=='F')
          i+=(int)(object2.value[z]-55)*pow(object2.base, p);
        else i+=(int)(object2.value[z]-48)*pow(object2.base, p);
        p++;
   } 
   for(int z=strlen(object.value)-1;z>=0;z--)
   {
       if(object.value[z]=='A' || object.value[z]=='B' || object.value[z]=='C' || object.value[z]=='D' || object.value[z]=='E' || object.value[z]=='F')
          j+=(int)(object.value[z]-55)*pow(object.base, p);
        else j+=(int)(object.value[z]-48)*pow(object.base, p);
        p++;
   } 
    i-=j;
    int d=0;
    while(i)
    {
        if(i%object.base<=9) sir[p]=(char)(i%object.base+48);
          else switch(i%object.base){
              case 10: {sir[p]='A'; break;}
              case 11: {sir[p]='B'; break;}
              case 12: {sir[p]='C'; break;}
              case 13: {sir[p]='D'; break;}
              case 14: {sir[p]='E'; break;}
              case 15: {sir[p]='F'; break;}
              default: break;
          }
        i=i/object.base;
        d++;
        p++;
    } 
    p=0;
    for(i=d-1;i>=0;i--)
    {
        object.value[p]=sir[i];
        p++;
    }
    return object;

   }

   
 
}

int Number::GetDigitsCount()
{
   char* x=value;
   int digits=0;
   while(x[digits]!=NULL) digits++;
   return digits;
}

int Number::GetBase()
{
    return this->base;
}

int Number::operator--() //pentru prefix, apelare --n1;
{
    strcpy(value, value+1);
}

int Number::operator--(int a) //pentru sufix, apelare n1--;
{
   value[strlen(value)-1]=NULL;
}

void Number::transform(Number&  object, int &i, int &j)
{
    int z=strlen(this->value)-1;
    i=j=0;
    double p=0;
    while(z>=0){
       i+=((int)this->value[z]-48)*pow(this->base, p);
       p++;
       z--;
   }
   z=strlen(object.value)-1;
   p=0;
   while(z>=0)
   {
       j+=((int)object.value[z]-48)*pow(object.base, p);
       p++;
       z--;
   }
}

int Number::operator>(Number &object)
{
   int i=0,j=0,z=strlen(this->value)-1;
   double p=0;
   transform(object,i,j);
    if(i>j) return true;
      else return false;

}

int Number::operator<(Number &object)
{
   int i=0,j=0,z=strlen(this->value)-1;
   double p=0;
   transform(object,i,j);
   if(i<j) return true;
      else return false;

}

int Number::operator<=(Number &object)
{
   int i=0,j=0,z=strlen(this->value)-1;
   double p=0;
   transform(object,i,j);
   if(i<=j) return true;
      else return false;

}

int Number::operator>=(Number &object)
{
   int i=0,j=0,z=strlen(this->value)-1;
   double p=0;
   transform(object,i,j);
   if(i>=j) return true;
      else return false;

}

int Number::operator==(Number &object)
{
   int i=0,j=0,z=strlen(this->value)-1;
   double p=0;
   transform(object,i,j);
   if(i==j) return true;
      else return false;

}

void Number::Print()
{
    std::cout<<"Numarul este "<<value<<", iar baza este "<<this->base<<"\n";
}

void Number::SwitchBase(int newBase)
{
   int i=0,p=0;
   char sir[255];
   for(int z=strlen(this->value)-1;z>=0;z--)
   {
       if(value[z]=='A' || value[z]=='B' || value[z]=='C' || value[z]=='D' || value[z]=='E' || value[z]=='F')
          i+=(int)(value[z]-55)*pow(base, p);
        else i+=(int)(value[z]-48)*pow(base, p);
        p++;
   } 
    p=0;
    int d=0;
    while(i)
    {
        if(i%newBase<=9) sir[p]=(char)(i%newBase+48);
          else switch(i%newBase){
              case 10: {sir[p]='A'; break;}
              case 11: {sir[p]='B'; break;}
              case 12: {sir[p]='C'; break;}
              case 13: {sir[p]='D'; break;}
              case 14: {sir[p]='E'; break;}
              case 15: {sir[p]='F'; break;}
          }
        i=i/newBase;
        d++;
        p++;
    } 
    p=0;
    for(i=d-1;i>=0;i--)
    {
        value[p]=sir[i];
        p++;
    }

   this->base=newBase;

}

int Number::operator[](int index)
{
    return value[index];
}

void Number::operator=(Number& object)
{
    strcpy(this->value, object.value);
    this->base=object.base;
}