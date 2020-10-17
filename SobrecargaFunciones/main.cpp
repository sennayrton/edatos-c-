#include <iostream>
using namespace std;

float cuadrado(int k)
{
    return k * k;
}

float cuadrado(float x)
{
    return x * x;
}

void main()
{
    int a = 7;
    float b = 1.2;
    cout << "El cuadrado del entero 7 es " << cuadrado(a) << endl;
    cout << "El cuadrado del real 1.2 es " << cuadrado(b) << endl;

}