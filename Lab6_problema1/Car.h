#include"Weather.h"
#include<iostream>
class Car
{
public:
   
   unsigned int avgRain, avgSunny, avgSnow;
   int fuelCapacity, fuelConsumption;
   const char* name;
   bool finish;
   float time;
   int ID;  
   Car(){std::cout<<"Constructor car\n";}
};