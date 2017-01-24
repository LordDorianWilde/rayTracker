#include "sphere.h"

Sphere::Sphere(Vecteur c, double r, double red , double green, double blue)
{
    centre = c;
    rayon = r;
    color[0] = red;
    color[1] = green;
    color[2] = blue;
}

Sphere::Sphere(Vecteur c, double r, string couleur)
{
    centre = c;
    rayon = r;

    if(couleur == "blue")
    {
        color[0] = 0.;
        color[1] = 0.;
        color[2] = 1.;
    }
    else if(couleur == "green")
    {
        color[0] = 0.;
        color[1] = 1.;
        color[2] = 0.;
    }
    else if(couleur == "red")
    {
        color[0] = 1.;
        color[1] = 0.;
        color[2] = 0.;
    }
    else
    {
        color[0] = 1.;
        color[1] = 1.;
        color[2] = 1.;
    }
}

