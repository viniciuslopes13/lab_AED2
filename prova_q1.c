/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdio.h>
#include<stdlib.h>

/*Define o tamanho da matriz*/
#define TAM 2

/*Função que retorna um ponteiro para uma matriz alocada dinamicamente*/
int **alocarMatriz(int linhas, int colunas){
	int **matrix = (int **) malloc(linhas*sizeof(int *));
	int i;
	for(i=0;i<linhas;i++){
		matrix[i] = (int *) malloc(colunas*sizeof(int));
	}
	return matrix;
}

/*Função que libera espaço de matriz alocada dinamicamente*/
void desalocarMatriz(int** matriz){
    int i=0;
    for(i=0;i<TAM;i++){
        free(matriz[i]);
    }
    free(matriz);
}

/*Função responsável por exibir matriz em tela, recebendo como parâmetro a matriz em si*/
void exibeMatrizComum(int mat[TAM][TAM]){
    printf("\n");
    int i,j;
	for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/*Função responsável por exibir matriz em tela, recebendo como parâmetro o ponteiro da matriz*/
void exibeMatrizRef(int ** mat){
    printf("\n");
    int i,j;
	for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

/*Realiza a soma dos elementos de duas matrizes*/
int** somaMatrizes(int mat1[TAM][TAM], int mat2[TAM][TAM]){
    int** mat = alocarMatriz(TAM,TAM);
    int i,j;
    for(i=0;i<TAM;i++){
        for (j=0; j<TAM; j++){
            mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat;
}

/*Realiza a subtração dos elementos de duas matrizes*/
int** subtraiMatrizes(int mat1[TAM][TAM], int mat2[TAM][TAM]){
    int** mat = alocarMatriz(TAM,TAM);
    int i,j;
    for(i=0;i<TAM;i++){
        for (j=0; j<TAM; j++){
            mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return mat;
}

/*Realiza a multiplicação dos elementos de duas matrizes*/
int** multiplicaMatrizes(int mat1[TAM][TAM], int mat2[TAM][TAM]){
	int** mat = alocarMatriz(TAM,TAM);
    int lin,col,k,somaprod;
	for(lin=0; lin<TAM; lin++){
	    for(col=0; col<TAM; col++){
	    	somaprod=0;
	    	for(k=0; k<TAM; k++){
				somaprod+=mat1[lin][k]*mat2[k][col];
			}
	    	mat[lin][col]=somaprod;
	    }
	}
	return mat;
}

int main(){
    int mat1[TAM][TAM] = {{2,4},{5,6}};
    int mat2[TAM][TAM] = {{4,3},{1,2}};
    int ** matrix = somaMatrizes(mat1,mat2);
    printf("\nMatriz 1:");
    exibeMatrizComum(mat1);
    printf("\nMatriz 2:");
	exibeMatrizComum(mat2);
    printf("\nSoma:");
    exibeMatrizRef(matrix);
    matrix = subtraiMatrizes(mat1,mat2);
    printf("\nSubtracao:");
    exibeMatrizRef(matrix);
    matrix = multiplicaMatrizes(mat1,mat2);
    printf("\nMultiplicacao:");
    exibeMatrizRef(matrix);
    desalocarMatriz(matrix);
    return 0;
}
