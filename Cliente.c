#include "Cliente.h"
#include "vendas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "ItensCompra.h"


//Teste de Leitura
void leitura2()
{
	FILE *arqCliente;
	arqCliente = fopen("Cliente.dat","rb");
	TClientes listaCliente;
	if(arqCliente != NULL)
	{
		fseek(arqCliente, sizeof(TClientes)*0, SEEK_SET);
		fread(&listaCliente, sizeof(TClientes), 1, arqCliente);
		printf("CPF: %s\n", listaCliente.cpf); 
		printf("Nome: %s\n", listaCliente.nomepessoa);
    	printf("Data de Nascimento: %d/%d/%d\n", listaCliente.dia, listaCliente.mes, listaCliente.ano);
    	printf("Idade: %d\n", listaCliente.idade);
    	printf("Endereco: %s\n", listaCliente.endereco);
    	printf("Cidade: %s\n", listaCliente.cidade);
    	printf("Estado: %s\n", listaCliente.estado);
    	printf("Pontos: %d\n", listaCliente.pontos);
    	fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

//CADASTRO DO CLIENTE
void cliente()
{
	FILE *arqCliente;
	TClientes listaCliente;
	arqCliente = fopen("Cliente.dat","ab");
	if(arqCliente != NULL)
	{
        printf("Digite o CPF:");
        scanf(" %s", &listaCliente.cpf);
        printf("Digite o nome da Pessoa:");
        scanf(" %[^\n]s", listaCliente.nomepessoa);
        printf("Digite a data de nascimento:");
        scanf(" %d %d %d", &listaCliente.dia, &listaCliente.mes, &listaCliente.ano);
        printf("Digite a idade:");
        scanf(" %d", &listaCliente.idade);
        printf("Digite o endereco:");
        scanf(" %[^\n]s", listaCliente.endereco);
        printf("Digite a cidade:");
        scanf(" %[^\n]s", listaCliente.cidade);
        printf("Digite o estado[abreviado em 2 letras]:");
        scanf(" %[^\n]s", listaCliente.estado);
        listaCliente.pontos = 0;
        fwrite(&listaCliente,sizeof(TClientes), 1, arqCliente);
        fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura do arquivo");
	}
}


void alterarPontos()
{
	FILE *arqCliente;
	FILE  *arqVendas;
	TClientes listaCliente;
	Tvendas infoVendas;
	arqCliente = fopen("Cliente.dat", "r+wb");
	arqVendas = fopen("Vendas.dat", "rb");
	if(arqCliente != NULL)
	{
		if(arqVendas != NULL)
		{
			while(fread(&listaCliente, sizeof(TClientes), 1, arqCliente) != 0)
			{
				while(fread(&infoVendas, sizeof(Tvendas), 1, arqVendas) != 0)
				{
					if(strcmp(listaCliente.cpf,infoVendas.cpf) == 0)
					{
						if(infoVendas.valortotal > 0)
						{
							listaCliente.pontos = infoVendas.valortotal;
						}
					}
			
				}
			}
		leitura2();
		fclose(arqVendas);
		}
		else
		{
			printf("Falha na abertura no arquivo de Vendas");
		}
		fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura no arquivo de Cliente");
	}
	
}	


//ALTERAR O DDADOS DO CLIENTE
void alterarCliente()
{
	FILE *arqCliente;
	TClientes listaClientenovo;
	int id;
	arqCliente = fopen("Cliente.dat","rb+");
	if(arqCliente != NULL)
	{
		printf("Qual indice voce deseja alterar?");
		scanf(" %d", &id);
		fseek(arqCliente, sizeof(TClientes)*id, SEEK_SET);
        fread(&listaClientenovo, sizeof(TClientes), 1, arqCliente);
		printf("Digite o CPF:");
        scanf(" %s", &listaClientenovo.cpf);
        printf("Digite o nome da Pessoa:");
        scanf(" %[^\n]s", listaClientenovo.nomepessoa);
        printf("Digite a data de nascimento:");
        scanf(" %d %d %d", &listaClientenovo.dia, &listaClientenovo.mes, &listaClientenovo.ano);
        printf("Digite a idade:");
        scanf(" %d", &listaClientenovo.idade);
        printf("Digite o endereco:");
        scanf(" %[^\n]s", listaClientenovo.endereco);
        printf("Digite a cidade:");
        scanf(" %[^\n]s", listaClientenovo.cidade);
        printf("Digite o estado[abreviado em 2 letras]:");
        scanf(" %[^\n]s", listaClientenovo.estado);
        fseek(arqCliente, sizeof(TClientes)*id, SEEK_SET);
        fwrite(&listaClientenovo, sizeof(TClientes), 1, arqCliente);
        fflush(arqCliente);
        leitura2();
		fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura do arquivo");	
	}	
}

//LISTAR CLIENTE NA FAIXA DE 18 A 25 ANOS
int listarIdade()
{
	FILE *arqCliente;
	arqCliente = fopen("Cliente.dat","rb");
	TClientes listaCliente;
	int conta = 0;
	if(arqCliente != NULL)
	{
		while(fread(&listaCliente, sizeof(TClientes), 1, arqCliente) != 0)
		{
			if((listaCliente.idade >= 18) && (listaCliente.idade <= 25))
			{
				conta++;
			}
		}
		return conta;
		fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

//Listar Clientes acima de 1000 pontos
void listarPontos()
{
	FILE *arqCliente;
	arqCliente = fopen("Cliente.dat","rb");
	TClientes listaCliente;
	if(arqCliente != NULL)
	{
		while(fread(&listaCliente, sizeof(TClientes), 1, arqCliente) != 0)
		{
			if(listaCliente.pontos > 1000)
			{
				printf(" %s\n", listaCliente.nomepessoa);
			}
		}
		fclose(arqCliente);
	}
	else
	{
		printf("Falha na abertura do arquivo");
	}
}


