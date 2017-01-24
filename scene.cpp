#include "scene.h"

Scene::Scene(Vecteur a, Vecteur b)
{
    camera = a;
    lumiere = b;
    intensity = 500000;
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
        if(t > 0)
            return t;
        else
            return 1000000.;
    }
    else
        return 1000000.;
}

double Scene::intensityLight(Sphere s, Vecteur u, double t1)
{
    Vecteur P = (camera+(u*t1));
    Vecteur l = lumiere-P;
    double d = l.squareNorm();
    l.normalize();
    P = P - s.centre;
    P.normalize();
    double a = (l*P)*intensity/(d);

    return max(0., a);
}

double* Scene::lightPixel(Vecteur u)
{
    double d = 10000.;
    double inten[3] = {0.,0.,0.};
    for(int i = 0; i<spheres.size(); i++)
    {
        double a = intersecSphere(spheres[i], u);
        if( a < d )
        {
            d = a;
            double aux = intensityLight(spheres[i], u, d);
            for(int j = 0; j<3; j++)
            {
                inten[j] = min(255., aux*spheres[i].color[j]);
            }
        }
    }
    return inten;
}
