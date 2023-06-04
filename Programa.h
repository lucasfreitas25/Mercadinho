#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__


typedef enum Tescolha {Vendas = 1, Cliente = 2, Produto = 3, Sair = 9} Tescolha;

int menuprincipal();
int menuVenda();
int menuProduto();
int menuCliente();
int menuSair();
void enfeite();
void limpaTela();

#endif
