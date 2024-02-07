#include "GOperations.h"

ciag *ptr_dyn = nullptr;
rozmiarCiagu n_stat = 0;

ciag InicjalizujCiagGeometryczny(rozmiarCiagu n, float q) {
    if(n<=0)
        return nullptr;

    ciag temp = new double[n];
    ciag *temp_ptr_dyn = new ciag[++n_stat];

    temp[0] = 1;
    for(int i=1; i<n;i++)
        temp[i] = temp[i-1]*q;
    
    for(int i=0; i<n_stat-1; i++)
        temp_ptr_dyn[i] = ptr_dyn[i];
    if(ptr_dyn)
        delete [] ptr_dyn;
    
    temp_ptr_dyn[n_stat-1] = temp;
    ptr_dyn = temp_ptr_dyn;

    return temp;
}

double Suma(ciag cgeo, rozmiarCiagu n) {
    double sum = 0;
    for(int i=0; i<n; i++)
        sum+=cgeo[i];
    return sum;
}

double Srednia(ciag cgeo, rozmiarCiagu n) {
    return Suma(cgeo, n) / n;
}

double Wykonaj(operacja ptr, ciag cgeo, rozmiarCiagu n) {
    return ptr(cgeo, n);
}

void Wypisz(ciag cgeo, rozmiarCiagu n) {
    std::cout<<"(";
    for(int i=0; i<n; i++) {
        std::cout<<cgeo[i];
        if(i != n-1)
            std::cout<<" ,";
    }
    std::cout<<")"<<std::endl;
}

void UsunCiagi() {
    for(int i=0; i<n_stat; i++)
        delete [] ptr_dyn[i];
    delete [] ptr_dyn;
    ptr_dyn = nullptr;
}