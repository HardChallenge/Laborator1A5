#include<iostream>
#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
    this->columns=width;
    this->lines=height;
    char** matrix=(char**)malloc(height*sizeof(char*));
    for(int i=0;i<height;i++) matrix[i]=(char*)malloc(width*sizeof(char));
}

 void Canvas::DrawCircle(int x, int y, int ray, char ch)
 {
    int i,j;
    for(i=0;i<this->lines;i++)
      for(j=0;j<this->columns;j++) if((i-x)^2+(j-y)^2>=ray*(ray-1)&&(i-x)^2+(j-y)^2<=ray*(ray+1)) matrix[i][j]=ch;
                                           else matrix[i][j]=' ';

 }

 