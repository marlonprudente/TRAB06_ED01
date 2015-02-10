#include "Hash.h"

void Hash::inserir(string in)
{
    if(in.size()<2)
        seed = (int)in.at(1); //Se o tamanho da String for menor que dois, seed irá receber o valor da string na posição 1.
    else seed = (int)in.at(0) + (int)in.at(in.size() - 1); //Caso contrário, recebera a soma da posição inicial + a posição final.
    indice = seed%10; //O indice será o resto da divisão do Seed por 10.
}
