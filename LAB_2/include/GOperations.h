#ifndef GOPERATIONS_H
#define GOPERATIONS_H

#include "GSeries.h"

// a1 = 1

ciag InicjalizujCiagGeometryczny(rozmiarCiagu, float);
double Suma(ciag, rozmiarCiagu);
double Srednia(ciag, rozmiarCiagu);
double Wykonaj(operacja, ciag, rozmiarCiagu);
void Wypisz(ciag, rozmiarCiagu);
void UsunCiagi();

#endif