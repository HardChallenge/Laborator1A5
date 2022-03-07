#include<iostream>
#include"Math.h"
using namespace std;
int main()
{
   Math object;
   int a=10, b=15, c=20;
   double x=50.5, y=75.25, z=85.35;
   cout<<"Suma a 2 double-uri transformata in int: "<<object.Add(x,y)<<"\n";
   cout<<"Suma a 3 int-uri este: "<<object.Add(a,b,c)<<"\n";
   cout<<"Inmultirea a 3 double-uri transformata in int: "<<object.Mul(x,y,z)<<"\n";
   cout<<"Suma a mai multor numere prin functia variadica: "<<object.Add(5, 10, 10, 10, 10, 10)<<"\n";
   cout<<"Concatenarea a 2 siruri prin alocare dinamica: "<<object.Add("Laborator 3 ", "OOP");
   
    return 0;

}