#include "Sort.h"
#include <time.h>
#include<string.h>
#include<iostream>
#include<stdarg.h>

Sort::Sort(int count, int min, int max)
{
    this->vector=(int*)malloc(count*sizeof(int));
    time_t t;
    srand((unsigned)time(&t));
    int i;
    for(i=0;i<count;i++) this->vector[i]=min + rand() % (min - max + 1);
    this->count=count;
     }

Sort::Sort(int* vector, int count)
{
    this->vector=(int*)malloc(count*sizeof(int));
    for(int i=0;i<count;++i) this->vector[i]=vector[i];
    this->count=count;
}

Sort::Sort(int count, ...)
{
    this->vector=(int*)malloc(count*sizeof(int));
    va_list va;
    va_start(va, count);
    for(int i=0;i<count;i++) vector[i]=va_arg(va, int);
    va_end(va);
    this->count=count;
}

Sort::Sort(char* text)
{
    this->vector=(int*)malloc(10*sizeof(int));
    char* p;
    int i=0,j,z=0;
    p=strtok(text, ",");
    while(p) {
        for(j=0;j<=strlen(p)-1;j++) z=z*10+(int)p[j]-48;
        vector[i]=z;
        ++i;
        vector=(int*)realloc(vector, (i+1)*sizeof(int));
        p=strtok(NULL, ",");
    }
    this->count=i;
}

Sort::Sort(): vector(new int[6] {1,2,3,4,5,6} ) {
	this->count=6;
}


void Sort::BubbleSort(bool ascendent)
{
    int temp;
   for(int i=0; i<(this->count-1); i++)
    {
        for(int j=0; j<(this->count-i-1); j++)
        {
            if(vector[j]>vector[j+1])
            {
                temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
        }
    }
}

void Sort::InsertSort(bool ascendent)
{
    int i, key, j;
    for (i = 1; i < this->count; i++)
    {
        key = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j] < key)
        {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
}

void Sort::QuickSort(int* vector, int st, int dr, bool ascendent)
{
    bool low=false;
	if(st < dr)
	{
		int m = (st + dr) / 2;
		int aux = vector[st];
		vector[st] = vector[m];
		vector[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(vector[i] > vector[j])
			{
				aux = vector[i]; 
				vector[i] = vector[j];
				vector[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(vector, st , i - 1, low);
		QuickSort(vector, i + 1 , dr, low);
	}
}

void Sort::Print()
{
    for(int i=0; i<this->count;i++) std::cout<<vector[i]<<" ";
}

int Sort::GetElementFromIndex(int index)
{
    return vector[index];
}

int Sort::GetElementsCount()
{
    return this->count;
}



