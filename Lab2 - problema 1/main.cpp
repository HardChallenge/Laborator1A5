#include "NumberList.h"
#include<iostream>

int main()
{
 NumberList object;
 object.Init();
 object.Add(5); object.Add(2); object.Add(53); object.Add(1);
 std::cout<<"Vectorul actual este: ";
 object.Print();
 std::cout<<"\n";
 object.Sort();
 std::cout<<"Acum vectorul sortat este: ";
 object.Print();

}
