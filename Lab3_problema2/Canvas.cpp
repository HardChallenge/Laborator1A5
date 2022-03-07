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

 void Canvas::FillCircle(int x, int y, int ray, char ch)
 {
     int i,j;
    for(i=0;i<this->lines;i++)
      for(j=0;j<this->columns;j++) if((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray ) matrix[i][j]=ch;
                                    else matrix[i][j]=' ';

 }

 void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
 {
     int i,j;
    for(i=0;i<this->lines;i++)
      for(j=0;j<this->columns;j++) if(i>=left && i<=right && j>=top && j<=bottom) matrix[i][j]=ch;
                                      else matrix[i][j]=' ';
 }

 void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
 {
    int i,j;
    for(i=left;i<=right;i++) {matrix[i][top]=ch; matrix[i][bottom]=ch;}
    for(j=top+1;j<bottom-1;j++) {matrix[left][j]=ch; matrix[right][j]=ch;}
 }

 void Canvas::SetPoint(int x, int y, char ch)
 {
     matrix[x][y]=ch;
 }

 