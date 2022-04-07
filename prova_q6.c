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
    /*Cria vetor para armazenar dado temporariamente nas comparações.*/
    char* x = (char*)malloc(50*sizeof(char));
    /*
        A ordenação acontece sempre tentando inserir o elemento a uma posição sua mais a esquerda. Por exemplo,
        quando i=1, o algoritmo vai comparar se o valor da posicao 1 é menor que o da posião 0, se sim, 
        os valores são trocados. Quando i=2, o valor dessa posicao é comparado com os das posições 0 e 1, e assim
        por diante.
    */
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