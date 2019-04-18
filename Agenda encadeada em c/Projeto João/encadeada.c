/*Trabalho listas em C(nota 1)
	Entrega dia 22/04/19(até 3 pessoas)
	
	Elaborar um programa em c ,utilizando listas encadeadas para implementar uma agenda eletronica de entereços.
	-Serão armazenados os seguintes dados para cada pessoa:
		-nome
		-endereço
		-telefone
		-email
		
	A agenda eletrônica deverá conter os passos passados
	pelo programa em sala,ou seja, adaptar o que for preciso. OBS: Lembre que uma pessoa pode ter mais de um telefone e email.
	
	-O projeto será apresentado no dia 22/04/19 em computador próprio pela equipe.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
  char nome[30];
  char email[30];
  char endereco[50];
  char telefone[15];
  struct Node *prox;
}node;
int tam;
void inicia(node *LISTA)
{
  LISTA->prox = NULL;
  tam=0;
}
int vazia(node *LISTA)
{
  if(LISTA->prox == NULL)
    return 1;
  else
    return 0;
}
void cadastraEmail(node *LISTA){
  node *novo=(node *) malloc(sizeof(node));
  printf("Email:");
  getchar();
  fgets(novo->email, 30, stdin);
  novo->prox = NULL;
  if(vazia(LISTA))
    LISTA->prox=novo;
  else{
    node *tmp = LISTA->prox;
    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
}
void cadastraNome(node *LISTA){
  node *novo=(node *) malloc(sizeof(node));
  printf("Nome:"); 
  getchar();
  fgets(novo->nome,sizeof(novo->nome), stdin);
  novo->prox = NULL;
  if(vazia(LISTA))
    LISTA->prox=novo;
  else{
    node *tmp = LISTA->prox;
    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
}
void cadastraTel(node *LISTA){
  node *novo=(node *) malloc(sizeof(node));
  printf("Telefone:");
  scanf("%s", novo->telefone);
  novo->prox = NULL;
    if(vazia(LISTA))
    LISTA->prox=novo;
  else{
    node *tmp = LISTA->prox;
    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
}
void cadastraEndereco(node *LISTA){
  node *novo=(node *) malloc(sizeof(node));
  printf("Endereco:");
  scanf("%s", novo->endereco);
  novo->prox = NULL;
    if(vazia(LISTA))
    LISTA->prox=novo;
  else{
    node *tmp = LISTA->prox;
    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
}
void insereFim(node *LISTA)
{
  node *novo=(node *) malloc(sizeof(node));
  if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    cadastraNome(LISTA);
    cadastraEmail(LISTA);
    char resp[2];
    do{
      printf("Deseja cadastrar mais um email?(s ou n)\n");
      scanf("%s", resp);
      if(tolower(resp[0]) == 115){
        cadastraEmail(LISTA);
      }
    }while(tolower(resp[0]) == 115);
    cadastraTel(LISTA);
    do{
      printf("Deseja cadastrar mais um telefone?(s ou n)\n");
      scanf("%s", resp);
      if(tolower(resp[0]) == 115){
        cadastraTel(LISTA);
      }
    }while(tolower(resp[0]) == 115);
    cadastraEndereco(LISTA);
  tam++;
  }
}
void exibe(node *LISTA)
{
  if(vazia(LISTA)){
    printf("Lista vazia!\n\n");
  }
  node *tmp;
  tmp = LISTA->prox;
  int count = 1;
  int counTel = 1;
  printf("\nCadastros:\n\n");
  while( tmp != NULL){
    if(strlen(tmp->nome) && strlen(tmp->email) && strlen(tmp->endereco))
      printf("\tNome > %5s\n\n\tEmail(s) %d > %5s\n\nEndereço: %5s\n\n", tmp->nome,count,tmp->email,tmp->endereco);
    else if(strlen(tmp->nome))
      printf("\tNome:%5s\n\n", tmp->nome);
    else if(strlen(tmp->email)){
      printf("\tEmail(s) %d > %5s\n\n", count,tmp->email);
      count++;
    }
    else if(strlen(tmp->telefone)){
      printf("\tTelefone(s) %d > %5s\n\n", counTel,tmp->telefone);
      counTel++;
    }
    else if(strlen(tmp->endereco)){
      printf("\tEndereço: > %5s\n\n", tmp->endereco);
    }
    tmp = tmp->prox;
    
  }
  printf("\n");
}
int main(void){
  node *LISTA = (node *) malloc(sizeof(node));
  if(!LISTA){
      printf("Sem memoria disponivel!\n");
      exit(1);
  }else{
      inicia(LISTA);
  }
  insereFim(LISTA);
  insereFim(LISTA);
  exibe(LISTA);
}