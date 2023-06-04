#include "Programa.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void limpaTela()
{
    system("cls");
}

void enfeite()
{
	printf("---------------------------------------- \n");
	printf("----------- MENU - MERCADO----------- \n");
	printf("---------------------------------------- \n");
}

int menuprincipal()
{
	int op;
	
	printf("1 - Vendas\n");
	printf("2 - Cliente\n");
	printf("3 - Produto\n");
	printf("9 - Sair\n");
	scanf(" %d", &op);
	
	return op;
}


int menuVenda()
{
	int opcao;
	
	printf("1 - Nova venda\n");
    printf("2 - Para Listar venda do cliente \n");
    printf("9 - Sair \n");
    scanf(" %d", &opcao);
    
    return opcao;
}

int menuCliente()
{
	int opcao;
	
	printf("1 - Cadastrar cliente \n");
    printf("2 - Atualizar pontuacao \n");
    printf("3 - Atualizar cliente \n");
    printf("4 - Listar clientes entre 18 e 25 anos \n");
    printf("5 - Listar clientes acima de 1000 pontos \n");
    printf("9 - Sair \n");
    scanf(" %d", &opcao);
    
    return opcao;
}

int menuProduto()
{
	int opcao;
	
	printf("1 - Cadastrar novo produto \n");
    printf("2 - Atualizar informacoes \n");
    printf("3 - Listar produtos por setor \n");
    printf("4 - Produtos com estoque a baixo de 5 \n");
    printf("9 - Sair \n");
    scanf(" %d", &opcao);
    
    return opcao;
}
int menuSair()
{
	int opcao;
	
	printf(" 1 - Confirmar saida - Continuar\n");
	scanf(" %d", &opcao);
	
	return opcao;
}

