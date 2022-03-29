#include"Car.h"
class Dacia: public Car
{ 
    public:
    Dacia(){
       avgRain=60; avgSnow=50; avgSunny=100;
       fuelCapacity=20;
       fuelConsumption=10;
       name="Dacia";
       ID=0;
       std::cout<<"Constructor Dacia\n"; 
    };
 
};

class Toyota: public Car
{
    public:
    Toyota(){
       avgRain=80; avgSnow=50; avgSunny=110;
       fuelCapacity=30;
       fuelConsumption=8;
        name="Toyota";
        ID=1;
        std::cout<<"Constructor Toyota\n"; 
    };
    
};

class Mazda: public Car
{
    public:
    Mazda(){
       avgRain=85; avgSnow=70; avgSunny=115;
       fuelCapacity=15;
       fuelConsumption=5;
       name="Mazda";
       ID=2; 
       std::cout<<"Constructor Mazda\n"; 
    };
    
};

class Ford: public Car
{
    public:
    Ford(){
       avgRain=90; avgSnow=65; avgSunny=120;
       fuelCapacity=40;
       fuelConsumption=10;
       name="Ford";
       ID=3;
       std::cout<<"Constructor Ford\n";  
    };
    
};

class Mercedes: public Car
{
    public:
    Mercedes(){
       avgRain=80; avgSnow=50; avgSunny=110;
       fuelCapacity=30;
       fuelConsumption=8;
       name="Mercedes";
       ID=4;
       std::cout<<"Constructor Mercedes\n";  
    };
    
};

