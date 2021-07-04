#ifndef TRIANGULORETANGULO_H
#define TRIANGULORETANGULO_H

//declaração da estrutura
struct tTriangulo { 
  //menbros publicos
    public:
    //atributos
        double catetoOposto;
        double catetoAdjacente;
        double hipotenusa = 0;
//metodos
        double Perimetro();
        double Area();
        double Hipotenusa();
};

#endif