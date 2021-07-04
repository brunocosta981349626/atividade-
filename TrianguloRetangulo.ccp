#include "TrianguloRetangulo.h"//incluir nossa biblioteca
#include <cmath>//funções matematicas
//implementação do perimetro
double tTriangulo::Perimetro() {
    if (hipotenusa <= 0) hipotenusa = Hipotenusa();
    return catetoOposto + catetoAdjacente + hipotenusa;
}
//implementação da area
double tTriangulo::Area() {
    return (catetoOposto * catetoAdjacente) / 2;
}
//implementação da hipotenusa
double tTriangulo::Hipotenusa() {
    return sqrt( (catetoOposto * catetoOposto) + (catetoAdjacente * catetoAdjacente) );
}