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
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            fscanf(arq,"%d", &mat[i][j]);
        }
    }
}

void analiseOpcao(char op){
    switch (op){
    case 'S':
        printf("Programa Finalizado!");
        exit(0);
    case 'L': ;
        char nome[50];
        int lin,col;
        int **mat = alocarMatriz(3,3);
        printf("\nInforme o nome do arquivo (nome e extensao): ");
        scanf("%s",nome);
        printf("Informe o numerdo de linhas e colunas: ");
        scanf("%d %d",&lin,&col);
        FILE *arq = fopen(nome,"r");
        if (arq == NULL)
        {
            printf("Erro ao tentar abrir o arquivo!\n");
            exit(0);
        }
        lerArquivo(arq,mat,lin,col);
        exibeMatriz(mat,lin,col);
        desalocarMatriz(mat,lin);
        fclose(arq);
        break;
    case 'G':
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
