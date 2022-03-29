#include"Circuit.h"
#include<string.h>
void Circuit::SetLength(int number)
{
   lenght=number;
}
   
   
void Circuit::SetWeather(weather x)
{
   circuitWeather=x;
}

void Circuit::AddCar(Car *car)
{
    if(carCount<=100) {
        vector[carCount++]=car;
    }
}

bool Circuit::Finish(Car* car)
{
    int average;
    switch(this->circuitWeather)
    {
        case Rain: {average=car->avgRain; break;}
        case Snow: {average=car->avgSnow; break;}
        case Sunny: {average=car->avgSunny; break;}
        default: break;
    }

   int max=0, capacity=car->fuelCapacity, consumption=car->fuelConsumption;
   while(capacity>consumption) {
                max+=average;
                capacity-=consumption; 
               }
   float distanceRemain=0;
   average/=consumption;  //restul din rezervor per 1 litru
   distanceRemain=average*capacity;
   max+=distanceRemain;
   if(max>=lenght) return 1;
     else return 0;
}

float Circuit::FinishTime(Car* car)
{
  
           float time=0, average;
           switch(this->circuitWeather)
    {
        case Rain: {average=car->avgRain; break;}
        case Snow: {average=car->avgSnow; break;}
        case Sunny: {average=car->avgSunny; break;}
        default: break;
    }
           time=float(this->lenght/average);
           return time;
}

void Circuit::Race()
{
      for(int i=0;i<carCount;i++) {
          positions[i]=FinishTime(vector[i]);
        }
        
}


void Circuit::ShowFinalRanks()
{
    int i,j;
    float aux;
    char* t;
    
    for(i=0;i<carCount-1;i++)
       for (j=i+1;j<carCount;j++) 
         if(positions[i]>positions[j]) {
          aux=positions[i];
          positions[i]=positions[j];
          positions[j]=aux;
       }
    for(i=0;i<carCount;i++)
    {
        j=0;
        while(positions[i]!=FinishTime(vector[j])) j++;
        std::cout<<"Locul "<<i+1<<": "<<vector[j]->name<<" cu timpul "<<positions[i]<<" minute\n";
    }
}

void Circuit::ShowWhoDidNotFinis()
{
    std::cout<<"Masinile care nu au terminat sunt urmatoarele:\n";
    for(int i=0;i<carCount;i++) if(Finish(vector[i])==0) std::cout<<vector[i]->name<<"\n";
}



