#include <iostream>
#include "CImg.h"
#include <math.h>
#include <vector>
#include "vecteur.h"
#include "scene.h"
#include "sphere.h"

using namespace std;



int main()
{
    int W = 1024;
    int H = 1024;
    vector<unsigned char> pixels (W*H*3, 0);
    double alpha = 3.14/2.;

    Vecteur C(0, 0, 55);
    Vecteur L(-23, 20, -15);
    Scene scene(C, L);

    Sphere s (Vecteur(5,0,0), 8.);
    scene.addSphere(s);
    Sphere r (Vecteur(-5,0,0), 8.);
    scene.addSphere(r);
    Sphere mur (Vecteur(-1000,0,0), 975);
    scene.addSphere(mur);
    Sphere murFond (Vecteur(0,0,-1000), 980);
    scene.addSphere(murFond);


    for(int i = 0; i<W; i++)
    {
        for(int j = 0; j<H; j++)
        {
            Vecteur u(j - H/2., W/2. - i, -W/(2.*tan(alpha/2.)));
            u.normalize();

            double inten = scene.lightPixel(u);
            pixels[i*W + j] = inten;
            pixels[i*W + j + H*W] = inten;
            pixels[i*W + j + 2*H*W] = inten;

        }
    }

    cimg_library::CImg<unsigned char> cimg(&pixels[0], W, H, 1, 3);
    cimg.save("fichier.bmp");


    return 0;
}

