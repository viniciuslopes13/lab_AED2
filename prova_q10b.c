/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdio.h>
#include<stdlib.h>

/*Cria estrutura do tipo No*/
typedef struct no No;
struct no{
    float numero;
    No* prox;
};

/*Cria estrutura do tipo Fila*/
typedef struct fila Fila;
struct fila{
    No* inicio;
    No* fim;
};

/*Exibe Menu Principal em tela*/
void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - inserir\n");
    printf("2 - retira\n");
    printf("3 - imprime fila\n");
    printf("4 - liberar fila\n");
    printf("5 - sair\n");
    printf("=========================\n");
}

/*Cria fila e retorna o ponteiro*/
Fila* fila_cria(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

/*Insere elemento na fila*/
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

/*Retira elemento da fila*/
float fila_retira(Fila *f){
    No *novo = (No*) malloc(sizeof(float));
    novo = f->inicio;
    float valor = novo->numero;
    f->inicio = f->inicio->prox;
    free(novo);
    return valor;
}

/*Verifica se a fila é vazia*/
int fila_vazia(Fila *f){
    if(f->inicio==NULL){
        return 1;
    }
    return 0;
}

/*Imprime os elementos da fila*/
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

/*Libera todos os elementos da fila*/
void fila_libera(Fila *f){
    while(fila_vazia(f)==0){
        fila_retira(f);
    }
}

int main(){
    int op;
    Fila *fila = fila_cria();
    menu();
    scanf("%d",&op);
    while (op!=5){
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
        if(op==4){
            fila_libera(fila);
            printf("\nFila liberada\n\n");
        }
        menu();
        scanf("%d",&op);
    }
    return 0;
}