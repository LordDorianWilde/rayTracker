#include <iostream>
#include "CImg.h"
#include <math.h>
#include <vector>
#include "vecteur.h"
#include "scene.h"
#include "sphere.h"
#include "string"
#include "rayon.h"

using namespace std;

void createImage()
{
    int W = 1024;
    int H = 1024;
    vector<unsigned char> pixels (W*H*3, 0);
    double alpha = 3.14/2.;
    int nbRayon = 2;

    Vecteur C(0, -20, 55);
    Vecteur L(-10, 20, 30);
    Scene scene(L);

    Sphere s (Vecteur(0,-25,10), 10., "white", false, true, 1.5);
    scene.addSphere(s);
    Sphere murGauche (Vecteur(-1000,0,0), 960, "red", false, false, 0);
    scene.addSphere(murGauche);
    Sphere murDroite (Vecteur(1000,0,0), 960, "blue", false, false, 0.);
    scene.addSphere(murDroite);
    Sphere murFond (Vecteur(0,0,-1000), 960, "green", false, false, 0.);
    scene.addSphere(murFond);
    Sphere murDerriere (Vecteur(0,0,1000), 940, "white", false, false, 0.);
    scene.addSphere(murDerriere);
    Sphere sol (Vecteur(0,-1000,0), 960, "white", false, false, 0.);
    scene.addSphere(sol);

    #pragma omp parallel for schedule(dynamic,1)
    for(int i = 0; i<W; i++)
    {
        for(int j = 0; j<H; j++)
        {
            Vecteur u(j - H/2., W/2. - i, -W/(2.*tan(alpha/2.)));
            u.normalize();
            pixels[i*W + j] = 0;
            pixels[i*W + j + H*W] = 0;
            pixels[i*W + j + 2*H*W] = 0;

            Rayon r(C, u);
            for(int k = 0; k<nbRayon; k++)
            {
                vector<double> inten = scene.lightPixel(r);
                pixels[i*W + j] += inten[0];
                pixels[i*W + j + H*W] += inten[1];
                pixels[i*W + j + 2*H*W] += inten[2];
            }

            pixels[i*W + j] /= 1./nbRayon;
            pixels[i*W + j + H*W] /= 1./nbRayon;
            pixels[i*W + j + 2*H*W] /= 1./nbRayon;

            if(j == 0 && i % 10 == 0)
            {
                cout << (i / 10) << endl;
            }

        }
    }

    cimg_library::CImg<unsigned char> cimg(&pixels[0], W, H, 1, 3);
    cimg.save("fichier.bmp");
}

int main()
{

    createImage();

    return 0;
}

