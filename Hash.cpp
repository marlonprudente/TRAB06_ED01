#include "Hash.h"

void Hash::inserir(string in)
{
    if(in.size()<2)
        seed = (int)in.at(1); //Se o tamanho da String for menor que dois, seed ir� receber o valor da string na posi��o 1.
    else seed = (int)in.at(0) + (int)in.at(in.size() - 1); //Caso contr�rio, recebera a soma da posi��o inicial + a posi��o final.
    indice = seed%10; //O indice ser� o resto da divis�o do Seed por 10.
}
