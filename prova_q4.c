#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int **alocarMatriz(int linhas, int colunas){
	int **matrix = (int **) malloc(linhas*sizeof(int *));
	int i;
	for(i=0;i<linhas;i++){
		matrix[i] = (int *) malloc(colunas*sizeof(int));
	}
	return matrix;
}

void desalocarMatriz(int** matriz, int lin){
    int i=0;
    for(i=0;i<lin;i++){
        free(matriz[i]);
    }
    free(matriz);
}

void escolhaMenu(){
    char opcao;
    printf("\nEscolha uma opcao (S,L,G): ");
    scanf("%s",&opcao);
    analiseOpcao(opcao);
}

void exibeMatriz(int **mat, int lin, int col){
	int i,j;
	for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void lerArquivo(FILE *arq, int **mat,int lin, int col){
    int i,j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            fscanf(arq,"%d", &mat[i][j]);
        }
    }
}

void escreveArquivo(FILE *arq, int **mat, int lin, int col){
    int i,j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            fprintf(arq,"%d ", mat[i][j]);
        }
        fprintf(arq,"\n");
    }
}

void analiseOpcao(char op){
    
    char nome[50];
    int lin,col,i,j;
    FILE *arq;
    int **mat;
    
    switch (op){
    case 'S':
        printf("Programa Finalizado!");
        exit(0);
    case 'L':
        printf("\nInforme o nome do arquivo (nome e extensao): ");
        scanf("%s",nome);
        printf("Informe o numerdo de linhas e colunas: ");
        scanf("%d %d",&lin,&col);
        mat = alocarMatriz(lin,col);
        arq = fopen(nome,"r");
        if (arq == NULL)
        {
            printf("Erro ao tentar abrir o arquivo!\n");
            escolhaMenu();
        }
        lerArquivo(arq,mat,lin,col);
        exibeMatriz(mat,lin,col);
        desalocarMatriz(mat,lin);
        fclose(arq);
        system("pause");
        system("cls");
        escolhaMenu();
    case 'G':
        printf("\nInforme o nome do arquivo (nome e extensao): ");
        scanf("%s",nome);
        printf("Informe o numerdo de linhas e colunas: ");
        scanf("%d %d",&lin,&col);
        mat = alocarMatriz(lin,col);
        arq = fopen(nome,"w");
        if (arq==NULL) {
            printf("Falha ao criar o arquivo.");
            escolhaMenu();
	    }
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        escreveArquivo(arq,mat,lin,col);
        fclose(arq);
        desalocarMatriz(mat,lin);
        system("pause");
        system("cls");
        escolhaMenu();
        break;
    default:
        printf("\nOPCAO INVALIDA! ESCOLHA NOVAMENTE UMA OPCAO VALIDA.\n");
        escolhaMenu();
    }
}

int main(){
    escolhaMenu();
    return 0;
}
