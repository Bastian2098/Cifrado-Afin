#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

class Codificacion
{
private:
    int a, b;

public:
    Codificacion(int, int);
    Codificacion();
    ~Codificacion();
    int getA();
    int getB();
    void setA(int);
    void setB(int);
    char cifrar(char);
    char descifrar(char);
    int mcd(int a, int b);
    int inversa(int a);
};

char alf[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',/* 'ñ',*/ 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',' '};

Codificacion::Codificacion(int _a, int _b)
{
    a = _a;
    b = _b;
}

Codificacion::Codificacion()
{
    a = 11;
    b = 4;
}

Codificacion::~Codificacion(){};

int Codificacion::getA()
{
    return a;
}

void Codificacion::setA(int _a)
{
    a = _a;
}

int Codificacion::getB()
{
    return b;
}

void Codificacion::setB(int _b)
{
    b = _b;
}

char Codificacion::cifrar(char c)
{
    int y = 0;
    for (int i = 0; i < 27; i++)
    {
        if (c == alf[i])
        {
            y = ((a * (i)) + b) % 27;
            if (y >= 27)
            {
                y = y % 27;
            }
        }
    }
    return alf[y];
}

char Codificacion::descifrar(char c)
{
    int x = 0;
    for (int i = 0; i < 27; i++)
    {
        if (c == alf[i])
        {
            if (i - b < 0)
            {
                x = ((inversa(a)) * (i - b + 27)) % 27;
            }
            else
            {
                x = ((inversa(a)) * (i - b)) % 27;
            }
        }
    }
    return alf[abs(x)];
}

int Codificacion::mcd(int a, int b)
{ //Maximo comun divisor:
    if (b != 0)
    {
        return mcd(b, a % b);
    }
    return a;
}

int Codificacion::inversa(int x)
{ //Inverso modular
    for (int i = 1; i < 27; i++)
    {
        if (mcd(27, i) == 1)
        {
            if ((x * i) % 27 == 1)
            {
                return i;
            }
        }
    }
    return 0;
}

int main()
{
    Codificacion cod;
    string e;
    string c;
    string d;
    cin.getline(e);
    for (int i = 0; i < e.size(); i++)
    {
        if (cod.mcd(27, cod.getA()) == 1)
        {
            c.append(1,cod.cifrar(e.at(i)));
            d.append(1,cod.descifrar(c.at(i)));
        }
        else
        {
            cout << "El valor a debe ser coprimo de 27";
            break;
        }
    }
    cout<<"Cifrado: "<<c;
    cout<<"\nDescifrado: "<<d<<endl;
    return 0;
}