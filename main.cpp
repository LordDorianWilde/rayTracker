#include <iostream>
#include "CImg.h"
#include <math.h>
#include <vector>
#include "vecteur.h"
#include "scene.h"
#include "sphere.h"
#include "string"

using namespace std;



int main()
{
    int W = 1024;
    int H = 1024;
    vector<unsigned char> pixels (W*H*3, 0);
    double alpha = 3.14/2.;

    Vecteur C(0, 0, 55);
    Vecteur L(-10, 20, 40);
    Scene scene(C, L);

    Sphere s (Vecteur(0,0,0), 10., "white");
    scene.addSphere(s);
    Sphere murGauche (Vecteur(-1000,0,0), 940, "red");
    scene.addSphere(murGauche);
    Sphere murDroite (Vecteur(1000,0,0), 940, "blue");
    scene.addSphere(murDroite);
    Sphere murFond (Vecteur(0,0,-1000), 940, "green");
    scene.addSphere(murFond);
    Sphere sol (Vecteur(0,-1000,0), 940, "white");
    scene.addSphere(sol);


    for(int i = 0; i<W; i++)
    {
        for(int j = 0; j<H; j++)
        {
            Vecteur u(j - H/2., W/2. - i, -W/(2.*tan(alpha/2.)));
            u.normalize();

            double* inten = scene.lightPixel(u);
            pixels[i*W + j] = inten[0];
            pixels[i*W + j + H*W] = inten[1];
            pixels[i*W + j + 2*H*W] = inten[2];

        }
    }

    cimg_library::CImg<unsigned char> cimg(&pixels[0], W, H, 1, 3);
    cimg.save("fichier.bmp");


    return 0;
}

