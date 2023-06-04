#include <stdio.h>
#include <stdbool.h>
#include "Programa.h"
#include "Produto.h"
#include "Cliente.h"
#include "vendas.h"
#include "itensCompra.h"

int main(int argc, char const *argv[])
{
    int resp,escolha,x,y,z,id,t;
    bool Fim = false;
    while (!Fim)
    {
    	limpaTela();
    	enfeite();
    	resp = menuprincipal();
        printf(" \n");
        switch(resp)
        {
        
        case 1://VENDA
        	limpaTela();
        	escolha = menuVenda();
        	if(escolha == 1)
        	{
        		//CADASTRAR A VENDA
        		t = cadastroVenda();
        		if(t == 1)
        		{
        			cliente();
				}
			}
    		else if(escolha == 2)
    		{
    			//LISTAR VENDA DO CLIENTE
    			listarVenda();
			}
			else if(escolha == 9)
    		{
    			printf("Voce voltou ao menu principal \n");
			}
			printf(" \n");
        	break;
       
		case 2://CLIENTE
			limpaTela();
			x = menuCliente();
			if(x == 1)
        	{
        		//CADASTRAR CLIENTE
        		cliente();
        		
			}
    		else if(x == 2)
    		{
    			//ATUALIZAR PONTUACAO
    			alterarPontos();
			}
			else if(x == 3)
    		{
    			//ATUALIZAR CLIENTE
    			alterarCliente();
    
			}
			else if(x == 4)
    		{
    			//lISTAR CLIENTES ENTRE 18 A 25 ANOS
    			id = listarIdade();
    			printf("A quantidade de clientes entre 18 a 25 anos e de: %d\n", id);
    			
			}
			else if(x == 5)
    		{
    			//CLIENTES ACIMA DE 1000 PONTOS
    			listarPontos();
			}
			else if(x == 9)
    		{
    			printf("Voce voltou ao menu principal \n");
			}
			printf(" \n");
        	break;
        	
		case 3://PRODUTO
			limpaTela();
			y = menuProduto();
			if(y == 1)
        	{
        		//CADASTRAR O PRODUTO
        		produto();
			}
    		else if(y == 2)
    		{
    			//ALTERAR O PRODUTO
    			alterarP();
			}
			else if(y == 3)
    		{
    			//VERIFICAR O ITENS QUE TEM NO SETOR
    			setor();
    			
			}
			else if(y == 4)
    		{
    			//PRODUTOS COM ESTOQUE A BAIXO DE 5
    			estoque();
			}
			else if(y == 9)
    		{
    			printf("Voce voltou ao menu principal \n");
			}
			printf(" \n");
        	break;
			
        case 9:
        	limpaTela();
            z = menuSair();
           	if(z == 1)
            {
               Fim = true;
        	}
        	break;
   		}
    }

    return 0;
}
