#pragma once 
class Sort

{

    int count;
    int *vector;

public:

    Sort(int count, int min, int max);
    Sort(int* vector, int count);
    Sort(int count, ...);
    Sort(char* text);
    Sort();

    void InsertSort(bool ascendent=false);
    void QuickSort(int* vector, int st, int dr, bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

};