#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no No;
struct no{
    char caracter;
    No* prox;
};

typedef struct{
    No* topo;
} Pilha;

int main(){
    int tam;
    char palavra[100];
    printf("Digite uma palavra: ");
    gets(palavra);
    tam = strlen(palavra);
    printf("Tamanho = %d",tam);
    int k=0;
    int i=0;
    while(i<(int)(tam/2)){
        push(palavra[i]);
        i++;
    }
    int temp = tam;
    while(i<tam){
        if(pop(pilha)!=palavra[temp-1]) k=1;
        temp--;
        i++;
    }
    return 0;
}