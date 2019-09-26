#include <math.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>

# define M_PI           3.14159265358979323846  /* pi */

//=====================================1========================================

class IShape{
public:
    virtual ~IShape() = 0;
    virtual double Area() = 0;
};

class Sqare : public IShape
{
private:
    double x1;
    double x2;
    double y1;
    double y2;
public:
    virtual double Area()
    {
        return (x2-x1)*(y2-y1);
    }
};

class Rectangle : public IShape
{
private:
    double x1;
    double x2;
    double y1;
    double y2;
public:
    virtual double Area()
    {
        return (x2-x1)*(y2-y1);
    }
};

class Triangle : public IShape
{
private:
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;
public:
    virtual double Area()
    {
        pow(x1,2);
        double a = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
        double b = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
        double c = sqrt(pow(x3-x1,2) + pow(y3-y1,2));
        double p = 0.5*(a+b+c);
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};
class Circle : public IShape
{
private:
    double x;
    double y;
    double radius;
public:
    virtual double Area()
    {
        return M_PI * pow(radius,2);
    }
};

using namespace std;

//=====================================2========================================

void somefunction()
{
    string name = "";
    FILE *f = fopen(name.c_str(), "w");
    if(f==NULL)
        printf("Can't open file");
    //выйти из программы или что-нибудь ещё сделать :)
    if(f!=NULL) //не закрывать не открытый файл
        fclose(f);
}

//=====================================3========================================

//quicksort + удаление повторяющихся) сложность O(n log n)

void deleteDublucate(vector<int> arr)
{

    std::sort(arr.begin(),arr.end());
    for(int i = 1, currentElement = 0; i < arr.size(); i++)
    {
        if(arr[currentElement] == arr[i])
            continue;
        currentElement++;
        arr[currentElement] = arr[i];
    }
}

//=====================================4========================================

//log 2 (N) / log n (N)?
