#include<stdio.h>
#include<stdlib.h>

typedef struct no No;
struct no{
    float numero;
    No* prox;
};

typedef struct fila Fila;
struct fila{
    No* inicio;
    No* fim;
};

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - inserir\n");
    printf("2 - retira\n");
    printf("3 - imprime fila\n");
    printf("4 - sair\n");
    printf("=========================\n");
}

Fila* fila_cria(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void fila_insere(Fila *f, float v){
    No *novo = (No*) malloc(sizeof(float));
    novo->numero = v;
    novo->prox = NULL;
    if(f->inicio==NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

float fila_retira(Fila *f){
    No *novo = (No*) malloc(sizeof(float));
    novo = f->inicio;
    float valor = novo->numero;
    f->inicio = f->inicio->prox;
    free(novo);
    return valor;
}

int fila_vazia(Fila *f){
    if(f->inicio==NULL){
        return 1;
    }
    return 0;
}

void fila_imprime(Fila *f){
    No* no = (No*) malloc(sizeof(No));
    no = f->inicio;
    printf("\n### IMPRIMINDO FILA ###\n");
    if(fila_vazia(f)==0){
        while(no->prox!=NULL){
            printf("%.2f\n",no->numero);
            no = no->prox;
        }
        printf("%.2f\n",no->numero); 
    }
    printf("### FIM FILA ###\n\n");
}

int main(){
    int op;
    Fila *fila = fila_cria();
    menu();
    scanf("%d",&op);
    while (op!=4){
        if(op==1){
            float valor;
            printf("Informe um numero: ");
            scanf("%f",&valor);
            fila_insere(fila,valor);
        }
        if(op==2){
            if(fila_vazia(fila)){
                printf("\nFila Vazia\n\n");
            }else{
                printf("\nValor retirado da fila: %.2f\n\n",fila_retira(fila));   
            }
        }
        if(op==3){
            fila_imprime(fila);
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}