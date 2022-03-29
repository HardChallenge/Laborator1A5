#pragma once
#include"Cars.h"
class Circuit
{
   public:
   unsigned int lenght;
   int carCount;
   weather circuitWeather;
   Car** vector;
   float *positions;

   Circuit(){
       vector=(Car**)malloc(sizeof(Car*)*100);
       positions=(float*)malloc(carCount*sizeof(float));
       carCount=0;
   }

   int getID(Car *car);
   bool Finish(Car* car);
   float FinishTime(Car* car);
   void SetLength(int number);
   void SetWeather(weather x);
   void AddCar(Car* car);
   void Race();
   void ShowFinalRanks();
   void ShowWhoDidNotFinis();
};