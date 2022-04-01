#include<stdio.h>
#include<stdlib.h>

#define TAM 2

void exibeMatriz(int mat[TAM][TAM]){
    printf("\n");
    int i,j;
	for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

int * somaMatrizes(int mat1[TAM][TAM], int mat2[TAM][TAM]){
    int mat[TAM][TAM];
    int i;
    for(i=0;i<TAM;i++){
        mat[i] = mat1[i]+mat2[i];
    }
    return *mat;

}

int main(){
    int mat1[TAM][TAM] = {{2,4},{5,6}};
    int mat2[TAM][TAM] = {{3,3},{1,2}}

    exibeMatriz(somaMatrizes(mat1,mat2));

    return 0;
}