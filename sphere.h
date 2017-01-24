#ifndef SPHERE_H
#define SPHERE_H
#include "vecteur.h"
#include "string"

using namespace std;

class Sphere
{
public:
    Sphere(Vecteur, double, double, double, double);
    Sphere(Vecteur c, double r, string couleur);
    Vecteur centre;
    double rayon;
    double color[3];
};

#endif // SPHERE_H
