#ifndef __VENDAS_H__
#define __VENDAS_H__

#include <stdio.h>

typedef struct Tvendas{
int id_venda;
char cpf[13];
int dia, mes, ano;
float valortotal;
int quantprodutos;
}Tvendas;
///////////////


int cadastroVenda();
void armazenarVenda();
void reduzirEstoque();
void listarVenda();



#endif
