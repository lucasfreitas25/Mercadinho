#ifndef __CLIENTE_H__
#define __CLIENTE_H__

typedef struct TClientes{
	char cpf[13];
	char nomepessoa[50];
	int dia, mes, ano;
	int idade;
	char endereco[50];
	char cidade[50];
	char estado[2];
	float pontos;
}TClientes;

void cliente();
void alterarCliente();
void alterarPontos();
int listarIdade();
void listarPontos();
void leitura2();

#endif
