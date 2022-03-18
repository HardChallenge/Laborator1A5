#include "Sort.h"
#include<iostream>
using namespace std;

int main()
{
    int val, *vector;
    char text[20]="10,20,30,40,50";
    Sort object(text);
    Sort object2={10,50,100};
    Sort object3(vector, 15);
    object2.InsertSort();
    val=object2.GetElementFromIndex(5);
    object.Print();
    object2.Print();
    object3.Print();
    cout<<val;
    return 0;

}