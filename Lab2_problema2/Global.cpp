#include "Global.h"
#include<string.h>

int compareMath(myClass* object1, myClass* object2)
{
    if (object1->getGrade(0) > object2->getGrade(0)) return 1;
      else if (object1->getGrade(0) == object2->getGrade(0)) return 0;
        else return -1;
}

int compareEnglish(myClass* object1, myClass* object2)
{
    if (object1->getGrade(1) > object2->getGrade(1)) return 1;
      else if (object1->getGrade(1) == object2->getGrade(1)) return 0;
        else return -1;
}

int compareHistory(myClass* object1, myClass* object2)
{
    if (object1->getGrade(2) > object2->getGrade(2)) return 1;
      else if (object1->getGrade(2) == object2->getGrade(2)) return 0;
        else return -1;
}

int compareName(myClass* object1, myClass* object2)
{
    if (strcmp(object1->getName(), object2->getName())>0) return 1;
      else if (strcmp(object1->getName(), object2->getName())==0) return 0;
        else return -1;
}

int compareAverage(myClass* object1, myClass* object2)
{
    if(object1->average() > object2->average()) return 1;
      else if(object1->average() == object2->average() ) return 0;
        else return -1;
}