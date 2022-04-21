#include<iostream>
#include<cstdio>

float operator""_Kelvin(unsigned long long x)
{
     return x-273;
}

float operator"" _Fahrenheit(unsigned long long x)
{
   return (x-32)*1.8;
   
}

int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    return 0;

}