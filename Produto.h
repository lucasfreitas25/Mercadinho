#ifndef __PRODUTO_H__
#define __PRODUTO_H__

typedef struct TProdutos{
	int id_prod;
	char setor[20];
	char nome[50];
	double preco;
	int quant;
	int dia, mes, ano;
}TProdutos;

//typedef enum TSetores{Higiene = 1, Bebidas = 2, Frios = 3, Padaria = 4, Acougue = 5} TSetores;
//int setores(TSetores);
void produto();//Cadastro do Produto
void alterarP();//Alterar o produto
void estoque();//Produto com Estoque abaixo de 5
void setor();//Procurar itens por setor
void leitura();//Leitura do produto

#endif
