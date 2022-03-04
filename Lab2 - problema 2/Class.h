#pragma once
class myClass
{
    char name[20];
    float math, eng, history;

    public:

    myClass();
    ~myClass();
    void setName(char* name);
    char* getName();
    void setGrade(float grade, int type); // 0 = math, 1 = english, 2=history
    float getGrade(int type);
    float average();

};