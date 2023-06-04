#include "Produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


//TESTE DE LEITURA
void leitura(int a)
{
	FILE *arqProduto;  
	arqProduto = fopen("Produtos.dat","rb");
	TProdutos listaP;
	if(arqProduto != NULL)
	{
		fseek(arqProduto, sizeof(TProdutos)*a, SEEK_SET);
		fread(&listaP, sizeof(TProdutos), 1, arqProduto);
		printf("Identificador do produto: %d\n", listaP.id_prod); 
		printf("Setor: %s\n", listaP.setor);
    	printf("Nome do Produto: %s\n", listaP.nome);
    	printf("Preco: %.2lf\n", listaP.preco);
    	printf("Data: %d/%d/%d\n", listaP.dia, listaP.mes, listaP.ano);
    	printf("Quantidade de estoque do produto: %d\n", listaP.quant);
    	fclose(arqProduto);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}


//CADASTRO DO PRODUTO
void produto()
{
	FILE *arqProduto;
	TProdutos listaP;
	arqProduto = fopen("Produtos.dat","ab");
	if(arqProduto != NULL)
	{
		printf("Digite o Identificador do produto:");
        scanf(" %d", &listaP.id_prod);    
        printf("Digite o setor do produto:");
        scanf(" %[^\n]s", listaP.setor); 
        printf("Digite o nome do produto:");
        scanf(" %[^\n]s", listaP.nome);
        printf("Digite o preco do produto:");
        scanf(" %lf", &listaP.preco);
        printf("Digite a data de validade:");
        scanf(" %d %d %d", &listaP.dia, &listaP.mes, &listaP.ano);
        printf("Quantidade em estoque:");
        scanf(" %d", &listaP.quant);
        fwrite(&listaP, sizeof(TProdutos), 1, arqProduto);
        //fflush(arqProduto);
        fclose(arqProduto);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

//ALTERAR PRODUTO
void alterarP()
{
	FILE *arqProduto;
	TProdutos listaPnovo;
	int id;
	arqProduto = fopen("Produtos.dat","rb+");
	if(arqProduto != NULL)
	{
		printf("Qual indice voce deseja alterar?");
		scanf(" %d", &id);
		fseek(arqProduto, sizeof(TProdutos)*id, SEEK_SET);
		fread(&listaPnovo, sizeof(TProdutos), 1, arqProduto);
		printf("Digite o Identificador do produto:");
        scanf(" %d", &listaPnovo.id_prod);
        printf("Digite o setor do produto:");
        scanf(" %[^\n]s", listaPnovo.setor);
        printf("Digite o nome do produto:");
        scanf(" %[^\n]s", listaPnovo.nome);
        printf("Digite o preco do produto:");
        scanf(" %lf", &listaPnovo.preco);
        printf("Digite a data de validade:");
        scanf(" %d %d %d", &listaPnovo.dia, &listaPnovo.mes, &listaPnovo.ano);
        printf("Quantidade em estoque:");
        scanf(" %d", &listaPnovo.quant);
        fseek(arqProduto, sizeof(TProdutos)*id, SEEK_SET);
        fwrite(&listaPnovo, sizeof(TProdutos), 1, arqProduto);
        fflush(arqProduto);
        printf(" \n");
        //leitura(id);
		fclose(arqProduto);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");	
	}	
}	

//vERIFICAR OS PRODUTOS POR SETOR	
void setor()
{
	FILE *arqProduto;
	TProdutos listaP;
	char procura[20];
	arqProduto = fopen("Produtos.dat","rb");
	printf("Qual setor deseja procurar?:");
	scanf(" %[^\n]s", procura);
    if(arqProduto != NULL)
    {
        while(fread(&listaP, sizeof(TProdutos), 1, arqProduto) != 0)
        {
            if(strcmp(procura,listaP.setor) == 0 )
            {
                printf(" %s\n", listaP.nome);
            }
        }
        fclose(arqProduto);
    }
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

//PRODUTOS QUE ESTAO ABAIXO DE 5 DE ESTOQUE
void estoque()
{
	FILE *arqProduto;
	TProdutos listaP;
	int x = 1;
	int cont = 0;
	arqProduto = fopen("Produtos.dat","rb");
	if(arqProduto != NULL)
	{
		while(fread(&listaP, sizeof(TProdutos), 1 , arqProduto) != 0)
		{
			if(listaP.quant < 5)
			{
				printf(" %s \n", listaP.nome);
				cont++;
			}
		}
		printf("A quantidade de produtos com estoque abaixo de 5: %d\n", cont);
		fclose(arqProduto);
	}
	else
	{
		printf("Falha na abertura do arquivo");
	}
}


