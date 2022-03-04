#include "Class.h"
#include<string.h>

void myClass::setName(char* name)
{
    strcpy(this->name, name);
}

char* myClass::getName()
{
    return this->name;
}

void myClass::setGrade(float grade, int type)
{
    if(type==0) this->math=grade;
       else if(type==1) this->eng=grade;
         else this->history=grade;
}

float myClass::getGrade(int type)
{
   if(type==0) return this->math;
     else if(type==1) return this->eng;
        else return this->history;
}

float myClass::average()
{
    return (this->math+this->eng+this->history)/3.0;
}

myClass::myClass()
{
    this->math=this->history=this->eng=1;
    memset(name, 0, 20);
}

myClass::~myClass()
{
    this->math=this->history=this->eng=0;
    memset(name, 0, 20);
}