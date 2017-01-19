#ifndef SPHERE_H
#define SPHERE_H
#include "vecteur.h"

class Sphere
{
public:
    Sphere(Vecteur, double);
    Vecteur centre;
    double rayon;
};

#endif // SPHERE_H
