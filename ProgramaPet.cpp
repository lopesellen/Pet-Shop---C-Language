
#include <stdio.h> //bibliotecas
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h> 
#define TAM 100
#define GATO 10.0
#define CACHORRO 12.5
#define REMEDIO 30.0
#define VACINA 70.0

int codigocadastro=1;
//structs
typedef struct{
	int codigo;
	char raca[100],nome[100];
	float conta;
}animal;

//protótipos
void cadastrarAnimal(int *posicao, animal ficha[TAM]); //parametro
void exibirCadastros(int posicao, animal ficha[TAM]);
int procurarAnimal(int posicao, animal ficha[TAM]);
void excluirAnimal(int *posicao, animal ficha[TAM]); //parametro
void produtos(int posicao, animal ficha[TAM]);
void totalCaixa(int posicao, animal ficha[TAM]);

main(){
	setlocale(LC_ALL,"");
	int menu,posicao=0;
	animal ficha[TAM]={};
	float total=0;
	
	
	do{
		printf("\n\t1 - Cadastrar Animal");
		printf("\n\t2 - Exibir Cadastros");
		printf("\n\t3 - Excluir Animal");
		printf("\n\t4 - Solicitar Produtos");
		printf("\n\t5 - Caixa");
		printf("\n\t6 - Sair\n");
		scanf("%i",&menu);
		switch(menu){
			case 1:
				cadastrarAnimal(&posicao,ficha);
			
			break;
			
			case 2:
				exibirCadastros(posicao,ficha);
			break;
			
			case 3:
				excluirAnimal(&posicao,ficha);
			break;
			
			case 4:
				produtos(posicao,ficha);
			break;
			
			case 5:
				totalCaixa(posicao,ficha);
			break;
			
			case 6:
			break;
			
			default: printf("\n\tOpção Inválida!");
		}
	}while(menu!=6);
}

void cadastrarAnimal(int *posicao, animal ficha[TAM]){  //No cadastro deve conter código, nome e raça
	if(*posicao==TAM){
		printf("\n\tEspaço insuficiente!\n");
	}else{
		if(posicao>0){
			printf("\n\tNome do animal:\n");
			fflush(stdin);
			gets(ficha[*posicao].nome);
			ficha[*posicao].codigo=codigocadastro;
			codigocadastro++;
			printf("\n\tRaça do animal:\n");
			fflush(stdin);
			gets(ficha[*posicao].raca);
			ficha[*posicao].conta=0.00;
			(*posicao)++;
			printf("\n\tAnimal cadastrado!\n\n");
		}else{
			printf("\n\tAnimal já cadastrado!");
		}
		system("pause");
		system("cls");
}
}

void exibirCadastros(int posicao, animal ficha[TAM]){
	if(posicao==0){
		printf("\n\tSem cadastros para exibir!");
	}else{
		printf("\n\tCADASTRO DE ANIMAIS:\n");
		for(int x=0;x<posicao;x++){
			printf("\n\tNome do animal: %s",ficha[x].nome);
			printf("\n\tCódigo: %04i",ficha[x].codigo);
			printf("\n\tRaça: %s",ficha[x].raca);
			printf("\n\tConta: R$ %.2f",ficha[x].conta);
			printf("\n===============================================\n");
		}
	}
}

int procurarAnimal(int posicao, animal ficha[TAM]){
	int codigo,retorno=-1;
	if(posicao==0){
		printf("\n\tSem cadastros para exibir!\n");
	}else{
		printf("\n\tInforme o código do animal:\n");
		scanf("%i",&codigo);
		for(int x=0;x<posicao;x++){
			if(codigo==ficha[x].codigo){
				retorno=x;
			printf("\n\tNome do animal: %s",ficha[x].nome);
			printf("\n\tCódigo: %i",ficha[x].codigo);
			printf("\n\tRaça: %s",ficha[x].raca);
			printf("\n\tConta: R$ %.2f",ficha[x].conta);
			printf("\n===============================================\n");
			break;	
			}
		}
		return retorno;
	}
}

void excluirAnimal(int *posicao, animal ficha[TAM]){
	int retorno;
	char resposta;
	if(*posicao==0){
		printf("\n\tSem cadastros para exibir!\n");
	}else{
		retorno=procurarAnimal(*posicao,ficha);
		if(retorno==-1){
			printf("\n\tCadastro não encontrado!\n");
			printf("\n\tRetorno: %i\n",retorno);
		}else{
			printf("Tem certeza que deseja excluir permanentemente este cadastro do sistema? S/N\t");
			fflush(stdin);
			scanf("%c",&resposta);
			if(toupper(resposta)=='S'){
				for(int x=retorno;x<*posicao;x++){
					strcpy(ficha[x].nome,ficha[x+1].nome);
					ficha[x].codigo=ficha[x+1].codigo;
					strcpy(ficha[x].raca,ficha[x+1].raca);
				}
				(*posicao)--;
				printf("\n\tCadastro excluído com sucesso!\n");
			}
		}
	}	
}


void produtos(int posicao, animal ficha[TAM]){
	int retorno,menuprodutos,qtdProduto=0,Q1=0,Q2=0,Q3=0,Q4=0;
	if(posicao==0){
		printf("\n\tSem cadastros para exibir!\n");
	}else{
		retorno=procurarAnimal(posicao,ficha);
		if(retorno==-1){
			printf("\n\tCadastro não encontrado!\n");
		}else{
			do{
				printf("\n\tInforme o código dos produtos que deseja:\n");
				printf("\n\t1 - Ração para gatos - R$ 10,00\n");
				printf("\n\t2 - Ração para cães  - R$ 12,50\n");
				printf("\n\t3 - Remédio A23      - R$ 30,10\n");
				printf("\n\t4 - Vacina B87       - R$ 70,00\n");
				scanf("%i",&menuprodutos);
				if(menuprodutos<1 || menuprodutos>4){
					printf("Produto inválido! Digite novamente:\n");
				}
			}while(menuprodutos<1 || menuprodutos>4);
			do{
				printf("\n\tInforme a quantidade:\n");
				scanf("%i",&qtdProduto);
				if(qtdProduto<1){
					printf("\n\tQuantidade Inválida. Informe novamente:\n");
				}
			}while(qtdProduto<1);
			system("cls");
			switch(menuprodutos){
					case 1:
					printf("\n%i Ração para gatos: R$ %.2f\n\n",qtdProduto,qtdProduto*GATO);
					Q1+=qtdProduto;
					ficha[retorno].conta+=qtdProduto*GATO;
					(retorno)++;
					break;
					case 2:
					printf("\n%i Ração para cães: R$ %.2f\n\n",qtdProduto,qtdProduto*CACHORRO);	
					Q2+=qtdProduto;
					ficha[retorno].conta+=qtdProduto*CACHORRO;
					(retorno)++;
					break;
					case 3:
					printf("\n%i Remédio: R$ %.2f\n\n",qtdProduto,qtdProduto*REMEDIO);	
					Q3+=qtdProduto;
					ficha[retorno].conta+=qtdProduto*REMEDIO;
					(retorno)++;
					break;
					case 4:
					printf("\n%i Vacina: R$ %.2f\n\n",qtdProduto,qtdProduto*VACINA);	
					Q4+=qtdProduto;
					ficha[retorno].conta+=qtdProduto*VACINA;
					(retorno)++;
					break;
		}
		}
	}
	system("pause");
	system("cls");
}

void totalCaixa(int posicao, animal ficha[TAM]){
	float soma=0;
	if(posicao==0){
		printf("\n\tSem cadastros para exibir!\n");
	}else{
		exibirCadastros(posicao, ficha);
		printf("\n\t|====================  CAIXA  =========================|\n");
		for(int x=0;x<posicao;x++){
			if(ficha[x].conta>0){
				soma+=ficha[x].conta;			
			}
		}
	}
	printf("\n\tTOTAL DO CAIXA:|| R$ %.2f ||\n\n\n",soma);
	system("pause");
	system("cls");
}


