#include<iostream>
#include "Class.h"
#include "Global.h"

int main()
{
    myClass object1, object2, object3;

    object1.setName((char*)"Student1");
    object2.setName((char*)"Student2");
    object3.setName((char*)"Student3");

    object1.setGrade(7.2, 0); object2.setGrade(8.5,0); object3.setGrade(8, 0);
    object1.setGrade(5.6, 1); object2.setGrade(9.5,1); object3.setGrade(6.5, 1);
    object1.setGrade(3.2, 2); object2.setGrade(10,2); object3.setGrade(10, 2);

    std::cout<<object1.average()<<"\n";
    std::cout<<object2.average()<<"\n";

    std::cout<<compareAverage(&object1, &object2)<<"\n";

    std::cout<<compareName(&object3, &object2);


    return 0;

}
