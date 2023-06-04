#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ItensCompra.h"
#include "vendas.h"
#include "Cliente.h"
#include "Produto.h"


TClientes consultarclientes;
TProdutos consultarproduto;
Tvendas consultarvendas;
Titenscompra infoItens;
FILE *arqItenscompra;


void registraritem(int x, int y,int nc,int np)
{	
	FILE *arq1 = NULL;
	FILE *arq2 = NULL;
	//adiquirindo informacoes enviadas pelo venda
	infoItens.quantidade = x;
	infoItens.id_venda = y;
	arq1 = fopen("Produtos.dat","rb");
	//adiquirindo informacoes consultando arquivo clientes
	arq2 = fopen("Cliente.dat","rb" );
	fseek(arq2, sizeof(TClientes)*nc, SEEK_SET);		
		fread(&consultarclientes, sizeof(TClientes), 1, arq2);
		
		strcpy(infoItens.cpf,consultarclientes.cpf);

	//adiquirindo informacoes consultando arquivo produto
		fseek(arq1, sizeof(TProdutos)*np, SEEK_SET);			
		fread(&consultarproduto, sizeof(TProdutos), 1, arq1);
		
		infoItens.id_prod = consultarproduto.id_prod;
		infoItens.precounitario = consultarproduto.preco;
	//calculando o preco total de acordo com a informacao do produto
		infoItens.precototal = 	infoItens.quantidade * 	infoItens.precounitario;
	armazenaritem();

}

void armazenaritem()
{
	arqItenscompra = fopen("ItensCompra.dat","ab");
		if(arqItenscompra != NULL)
		{
			fwrite(&infoItens, sizeof(Titenscompra), 1, arqItenscompra);	
		}
		else
		{
			printf("Falha na abertura do arquivo\n");
		}
	fclose(arqItenscompra);
		 
		 
}
