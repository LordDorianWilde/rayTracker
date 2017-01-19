#ifndef VECTEUR_H
#define VECTEUR_H


class Vecteur
{
public:
    double xyz[3];
    Vecteur(double, double, double);
    Vecteur();
    void normalize();
    double squareNorm();
    double &operator[](int);
    Vecteur operator+ (Vecteur);
    double operator* (Vecteur);
    Vecteur operator* (double);
    Vecteur operator- (Vecteur);
};

#endif // VECTEUR_H
