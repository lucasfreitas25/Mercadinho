#ifndef __ITENSCOMPRA_H__
#define __ITENSCOMPRA_H__

#include <stdio.h>


typedef struct Titenscompra{
int id_venda;
char cpf[13];
int id_prod;
int quantidade;
float precounitario;
float precototal;
}Titenscompra;



void registraritem();
void armazenaritem();





#endif
