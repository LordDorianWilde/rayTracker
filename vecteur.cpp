#include "vecteur.h"
#include "math.h"

Vecteur::Vecteur(double a, double b, double c)
{
    xyz[0] = a;
    xyz[1] = b;
    xyz[2] = c;
}

Vecteur::Vecteur()
{
    xyz[0] = 0;
    xyz[1] = 0;
    xyz[2] = 0;
}

void Vecteur::normalize()
{
    double n = sqrt(xyz[0]*xyz[0] + xyz[1]*xyz[1] + xyz[2]*xyz[2]);
    xyz[0] /= n;
    xyz[1] /= n;
    xyz[2] /= n;
}

double Vecteur::squareNorm()
{
    return (xyz[0]*xyz[0] + xyz[1]*xyz[1] + xyz[2]*xyz[2]);
}

double & Vecteur::operator[] (const int i)
{
    return xyz[i];
}

Vecteur Vecteur::operator+(Vecteur b)
{
    Vecteur c(xyz[0]+b[0], xyz[1]+b[1], xyz[2]+b[2]);
    return c;
}

double Vecteur::operator* (Vecteur b)
{
    double c = xyz[0]*b[0] + xyz[1]*b[1] + xyz[2]*b[2];
    return c;
}

Vecteur Vecteur::operator* (double a)
{
    Vecteur c(xyz[0]*a, xyz[1]*a, xyz[2]*a);
    return c;
}

Vecteur Vecteur::operator- (Vecteur b)
{
    Vecteur c(xyz[0]-b[0], xyz[1]-b[1], xyz[2]-b[2]);
    return c;
}
