#include<iostream>
#include"Header.h"

int main()
{
   vector<int> v;
   v.Push(10);
   v.Push(25); v.Push(43); v.Push(20);
   v.Pop();
   v.Delete(1);
   v.Print();

}