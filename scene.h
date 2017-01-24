#ifndef SCENE_H
#define SCENE_H
#include "vecteur.h"
#include <vector>
#include "sphere.h"
#include <math.h>

using namespace std;

class Scene
{
public:
    Vecteur camera;
    Vecteur lumiere;
    double intensity;
    std::vector<Sphere> spheres;
    Scene(Vecteur, Vecteur);
    void addSphere(Vecteur, double);
    void addSphere(Sphere);
    double intersecSphere(Sphere, Vecteur);
    double intensityLight(Sphere, Vecteur, double);
    double* lightPixel(Vecteur);
};

#endif // SCENE_H
