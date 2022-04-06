/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Função que retorna um ponteiro para uma matriz alocada dinamicamente*/
char **alocaNomes(int n){
	char **nomes = (char **) malloc(n*sizeof(char *));
	int i;
	for(i=0;i<n;i++){
		nomes[i] = (char *) malloc(50*sizeof(char));
	}
	return nomes;
}

/*ordena o vero de nomer em ordem alfabética*/
void ordenarInsercao(char** nomes, int n){
    int i,j;
    char* x = (char*)malloc(50*sizeof(char));
    for(i=1;i<n;i++){
        strcpy(x,nomes[i]);
        for(j=i-1;j>=0 && strcmp(x,nomes[j])<0;j--){
            strcpy(nomes[j+1],nomes[j]);
        }
        strcpy(nomes[j+1],x);
    }
}

/*Exibe vetor de nomes*/
void exibeVetor(char** nomes, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s\n",nomes[i]);
    }
}

int main(){
    int n,i;
    printf("Quantidade de alunos: ");
    scanf("%d",&n);
    char **nomes = alocaNomes(n);
    printf("Insira os nomes dos alunos: \n");
    for(i=0;i<n;i++){
        scanf("%s",nomes[i]);
    }
    ordenarInsercao(nomes,n);
    printf("\n##### Vetor em ordem #####\n");
    exibeVetor(nomes,n);
    return 0;
}