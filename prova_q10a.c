#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct fila Fila;
struct fila{
    float dados[N];
    int fim;
};

void inicializaFila(Fila *f){
    int i;
    for(i=0;i<N;i++){
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void fila_insere(Fila *f, float v){
    if(f->fim == N){
        printf("Fila esta cheia.\n");
        return;
    }else{
        f->dados[f->fim] = v;
        f->fim++;
    }
}

float fila_retira(Fila *f){
    int i;
    float dado;
    if(fila_vazia(f)==0){
        dado = f->dados[0];
        for(i=0;i<f->fim;i++){
            f->dados[i] = f->dados[i+1];
        }
        f->fim--;
        return dado;
    }
    printf("\nFila vazia!\n");
    return;
}

int fila_vazia(Fila *f){
   if(f->fim==0) return 1;
   return 0;
}

void fila_imprime(Fila *f){
    int i;
    printf("\nImprimindo a fila:\n");
    for(i=0;i<f->fim;i++){
        printf("%.2f	",f->dados[i]);
    }
}

int main(){
    Fila fila;
    
    inicializaFila(&fila);
    
	fila_insere(&fila,10.2);
    fila_insere(&fila,2);
    fila_insere(&fila,32.4);
    
	fila_imprime(&fila);
    
	fila_retira(&fila);
    
	fila_imprime(&fila);
    
	fila_retira(&fila);
    fila_retira(&fila);
    fila_retira(&fila);
    
	fila_imprime(&fila);
    
    return 0;
}
