/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*cria estrutura do tipo No*/
typedef struct no No;
struct no{
    char caracter;
    No* prox;
};

/*cria estrutura do tipo Pilha*/
typedef struct{
    No* topo;
} Pilha;

/*função para empilhar*/
void push(Pilha *pilha, char d){
    No * novo = (No*) malloc(sizeof(No));
    novo->caracter = d;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/*funcao para remover da pilha*/
char pop(Pilha *pilha){
    char c = pilha->topo->caracter;
    //No * pi = pilha->topo;
    pilha->topo = pilha->topo->prox;
    //free(pi);
    return c;
}

int main(){
    char palavra[100];
    Pilha p;
    p.topo = NULL;
    printf("Digite uma palavra: ");
    gets(palavra);
    int tam = strlen(palavra);
    int k=0; 
	int i=0;
    while(i<(tam/2)){
        push(&p,palavra[i]);
        i++;
    }
    if(tam%2!=0){
    	i++;
	}
    while(i<tam){
        if(pop(&p)!=palavra[i]){
        	k=1;
        	break;
		};
        i++;
    }
    if(k==1){
        printf("\nNao eh palindromo!\n");
    }else{
        printf("\nEh palindromo!\n");
    }
    return 0;
}
