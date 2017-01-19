#include "scene.h"

Scene::Scene(Vecteur a, Vecteur b)
{
    camera = a;
    lumiere = b;
    intensity = 10000;
}

void Scene::addSphere(Vecteur c, double r)
{
    Sphere s(c, r);
    spheres.push_back(s);
}

void Scene::addSphere(Sphere s)
{
    spheres.push_back(s);
}

double Scene::intersecSphere(Sphere s, Vecteur u)
{
    u.normalize();

    double a = 1;
    double b = (u*(camera-s.centre))*2;
    double c = (camera-(s.centre)).squareNorm() - (s.rayon)*(s.rayon);
    double delta = b*b - 4*a*c;
    if(delta >= 0)
    {
        double t1 = (-b - sqrt(delta))/(2.*a);
        double t2 = (-b + sqrt(delta))/(2.*a);
        double t = min(t1,t2);
        return t;
    }
    else
        return 1000000.;
}

double Scene::intensityLight(Sphere s, Vecteur u, double t1)
{
    u.normalize();
    Vecteur P = (camera+(u*t1));
    Vecteur l = lumiere-P;
    double d = sqrt(l*l);
    l.normalize();
    P.normalize();
    double a = (l*P)*intensity/(d);

    return max(0., a);
}

double Scene::lightPixel(Vecteur u)
{
    double d = 10000.;
    double inten = 0.;
    for(int i = 0; i<spheres.size(); i++)
    {
        double a = intersecSphere(spheres[i], u);
        if( a < d )
        {
            d = a;
            inten = intensityLight(spheres[i], u, d);
        }
    }
    return min(255., inten);
}
