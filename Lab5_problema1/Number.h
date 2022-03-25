#pragma once
class Number

{

   int base;
   char* value;

public:

   Number(const char * value, int base); // where base is between 2 and 16
   ~Number();
   Number(const Number& object);
   Number(Number &&object);
   friend Number& operator+(Number &object, Number &object2);
   friend Number& operator-(Number &object, Number &object2);
   void transform(Number &object, int &i, int &j);
   int operator[](int index);
   void operator=(Number& object);
   int operator>(Number &object);
   int operator<(Number &object);
   int operator>=(Number &object);
   int operator<=(Number &object);
   int operator==(Number &object);
   int operator--();
   int operator--(int a);
   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base

};