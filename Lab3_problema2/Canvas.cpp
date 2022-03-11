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
                                           else matrix[i][j]='\0';

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

 void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
 {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int D = 2*dy - dx;
    int y = y1;

    for(int x=x1;x<=x2;x++)
    {
      matrix[x][y]=ch;
      if(D>0) {
        y++;
        D-=2*dx;
        }
        D+=2*dy;
      }
 }

 void Canvas::Print()
 {
   for(int i=0;i<this->lines;i++)
     {
       for(int j=0;j<this->columns;j++) std::cout<<matrix[i][j]<<" ";
       std::cout<<"\n";
     }
 }

 void Canvas::Clear()
 {
   for(int i=0;i<this->lines;i++)
       for(int j=0;j<this->columns;j++) matrix[i][j]='\0';
 }

 void Canvas::Fill(char a)
 {
for(int i=0;i<this->lines;i++)
       for(int j=0;j<this->columns;j++) matrix[i][j]=a;
 }

 