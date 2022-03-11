#include"Canvas.h"
#include<iostream>

int main()
{
    Canvas object(5, 5);
    object.DrawCircle(1, 1, 4, 4);
    object.Print();
    object.Clear();
    object.DrawRect(1, 1, 4, 4, 'z');
    object.FillRect(1, 1, 4, 4, 'a');
    object.Print();

}