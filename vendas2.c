#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "vendas.h"
#include "ItensCompra.h"
#include "Cliente.h"
#include "Produto.h"



int i,x=0,n=1,codvend=0,quantitens,chaveaux;
int CODIGOproduto;
int QuantidadeProdutos=0;
int numCliente,numProd;

Tvendas infoVendas,printarVendas;
TClientes conferirCpf;
TProdutos conferirCodigoProduto;
TClientes conferirClientes;
int dia,mes,ano;


FILE *arqVendas;
FILE *arqProduto;
FILE *arqCliente;

int cadastroVenda()
{
	//definindo data da venda
	bool achou=false,chave=false;	
	int fimArquivo; 
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    dia = tm.tm_mday;
    mes = tm.tm_mon + 1;
    ano = tm.tm_year + 1900;
    infoVendas.dia = dia;
    infoVendas.mes = mes;
    infoVendas.ano = ano;
	
	
	infoVendas.valortotal=0;
		//FAZENDO UM NOVO CADASTRO DE VENDA
		infoVendas.id_venda=codvend+1;
		printf("Digite seu CPF:\n");
		scanf(" %[^\n]s", infoVendas.cpf);
		//CONFERINDO SE O CPF JA ESTA CADASTRADO	
		arqCliente = fopen("Cliente.dat","rb");
		if ( arqCliente != NULL)
		{
			while ( !achou && fread(&conferirCpf, sizeof(TClientes), 1, arqCliente) != 0) 
    		{		        				
		    	if ( strcmp(infoVendas.cpf, conferirCpf.cpf)  == 0 )
				{
		        	achou = true;
		        	numCliente=x;       
		    	}
				else x++;
			}
	    }
	    fclose(arqCliente);
	    if (!achou )
	    {
	    printf("CPF nao cadastrado.\n");
	    //SE NAO ESTIVER CADASTRADO VIRA PARA ESSE LACO E RETORNARA 1 PARA O MAIN QUE DEVE IDENTIFICAR E MANDAR O USUARIO PARA O MENU DE REGISTRAR NOVO CLIENTE
	    return(1);
		}	
		x=1;
	while(!chave )
	{
		achou=false;
		printf("Digite o codigo do produto desejado:\n");
		scanf(" %d", &CODIGOproduto);
		//CONFERINDO QUAL E O PRODUTO QUE FOI INSERIDO O CODIGO
		while (!achou)
	    {
	    	arqProduto = fopen("Produtos.dat","rb");
			if(arqProduto != NULL)
			{
				fseek(arqProduto, sizeof(TProdutos)*x, SEEK_SET);
	        	fread(&conferirCodigoProduto, sizeof(TProdutos), 1, arqProduto);
		        if ( CODIGOproduto == conferirCodigoProduto.id_prod )
		        {
		            numProd=x;
			        //SE ACHOU O CODIGO, ENTAO O PRODUTO EXISTE, JA VAI CONTAR 1 NO QUANTIDADE DE PRODUTOS INSERIDOS NA VENDA, JA ACABA COM O LACO TORNANDO O ACHOU TRUE E
			        // PRINTA OS 3 VALORES PEDIDOS, NOME, PRECO E QUANTIDADE DE ESTOQUE DESSE PRODUTO E TAMBEM JA CALCULA A SOMA TOTAL DOS VALORES
			        infoVendas.quantprodutos ++;
			        achou = true;
			        printf("Nome do produto: %s\nPreco: %.2lf\nQuantidade em estoque: %d\n",conferirCodigoProduto.nome,conferirCodigoProduto.preco,conferirCodigoProduto.quant);
					printf("Digite a quantidade desejada desse produto: \n");
					scanf(" %d",&quantitens);
					infoVendas.valortotal = infoVendas.valortotal + (conferirCodigoProduto.preco*quantitens);
					//FAZENDO A REDUCAO DA QUANTIDADE EM ESTOQUE, E REGISTRANDO O ITENSCOMPRA
					if(conferirCodigoProduto.quant >= quantitens)
		            {
		            	reduzirEstoque(numProd,quantitens);
		            	registraritem(quantitens,infoVendas.id_venda,numCliente,numProd);
					}
					else
					{
						printf("Nao ha quantidade disponivel do produto.\n");
					}				
		        }
	            fclose(arqProduto);
			}
			else
			{
				printf("Falha na abertura do arquivo");
			}
	        x++;
	    }
	    if (!achou )
	    {
	        printf("Produto nao cadastrado.\n");
		}
	            
			
		printf("Deseja comprar mais algum produto?\n[1]= Sim\n[2]= Nao\n");
		scanf(" %d",&chaveaux);
			if(chaveaux == 2)
			{
				chave = true;	
			}
			
	}
	armazenarVenda();
}



void reduzirEstoque(int a,int b)
{
	arqProduto = fopen("Produtos.dat" , "wb");
		if(arqProduto != NULL)
		{
			fseek(arqProduto, sizeof(TProdutos)*a, SEEK_SET);
			fread(&conferirCodigoProduto, sizeof(TProdutos), 1, arqProduto);
			conferirCodigoProduto.quant = conferirCodigoProduto.quant - b;
			fseek(arqProduto, sizeof(TProdutos)*a, SEEK_SET);
			fwrite(&conferirCodigoProduto, sizeof(TProdutos), 1 , arqProduto);
				
			fclose(arqProduto);
		}
		else{
			printf("Falha na abertura do arquivo estoque\n");
		}
}



void armazenarVenda()
{
	arqVendas = fopen("Vendas.dat","ab");
		if(arqVendas != NULL){
		fwrite(&infoVendas, sizeof(Tvendas), 1, arqVendas);	
		fclose(arqVendas);
		}
		else
		{
			printf("Falha na abertura do arquivo\n");
		}
}


void listarVenda()
{
	int aux;
	char nome1[13],cpf1[13];
	bool achou=false,x=false;
	while(!x)
	{
		printf("Deseja procurar atraves de qual informacao?\n[1]- CPF\n[2]- Nome\n");
		scanf(" %d",&aux);
		if(aux == 1)
		{
			printf("Digite seu CPF:\n");
			scanf(" %[^\n]s", cpf1);
			x=true;
		}
		else if(aux == 2)
		{
			printf("Digite seu nome completo:\n");
			scanf(" %[^\n]s", nome1);
			x=true;
		}
		else
		{
			printf("Escolha invalida.\n");
		}
	}
	while ( !achou )
	{
		arqCliente = fopen("Cliente.dat","rb");
	    if(arqCliente != NULL)
		{
	        while(fread(&conferirClientes, sizeof(TClientes), 1, arqCliente) != 0)
			{  
		        if ((strcmp(cpf1, conferirClientes.cpf)  == 0) || (strcmp(nome1, conferirClientes.nomepessoa) == 0))
		        {
		            achou = true;
		            arqVendas = fopen("Vendas.dat","rb");
					if(arqVendas != NULL)
					{	
						while(fread(&printarVendas, sizeof(Tvendas), 1, arqVendas) != 0)
						{
							printf("Data da compra: %d/%d/%d\n",printarVendas.dia,printarVendas.mes,printarVendas.ano);
							printf("Valor da compra: %.2f\n",printarVendas.valortotal);
							printf("Quantidade de produtos: %d",printarVendas.quantprodutos);
							fclose(arqVendas);
						}
					}
					else
					{
						printf("Falha na abertura do arquivo vendas\n");
					}
		        }
				else
				{
					printf("Informacoes nao encontradas.\n");
					achou = true;
		        }
		    }
		    x++;
		    fclose(arqCliente);
	    } 
	    else
		{
			printf("Falha na abertura do arquivo clientes\n");
		}		
	}
			
}
