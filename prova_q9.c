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
    /*
        Cria um novo nó, faz o dado do nó receber o parâmetro d, faz o novo nó apontar para o topo da fila
        e o nó do topo recebe o novo nó.
    */
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
    /*Pega o tamanho da palavra*/
    int tam = strlen(palavra);
    int k=0; 
	int i=0;
    /*
        Empilha cada letra da palavra na pilha, até o metade da palavra.
    */
    while(i<(tam/2)){
        push(&p,palavra[i]);
        i++;
    }
    /*
        Se a palavra for de tamanho par, o while que desempilha pode continuar a contagem a partir de onde o i
        estava, se for ímpar é necessário fazer um incremento em i.
    */
    if(tam%2!=0){
    	i++;
	}
    /*
        Esse segundo while é percorrido até o tamanho final da palavra. Aqui a pilha vai sendo desempilhada
        e cada letra desempilhada vai sendo comparada com a letra do vetor palavra.
    */
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
