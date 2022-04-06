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

void intercala(int e, int m, int d, char** v){
    int n1 = (m-e)+1;
    int n2 = (d-m);
    int k = e;
    char **E = alocaNomes(n1);
    char **D = alocaNomes(n2);
    int i,j;
    for(i=0;i<n1;i++){
        strcpy(E[i],v[e+i]);
    }
    for(j=0;j<n2;j++){
        strcpy(D[j],v[m+1+j]);
    }
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(strcmp(E[i],D[j])<0){
            strcpy(v[k],E[i]);
            i++;
        }else{
            strcpy(v[k],D[j]);
            j++;
        }
        k++;
    }
    while(i<n1){
        strcpy(v[k],E[i]);
        i++;
        k++;
    }
    while(j<n2){
        strcpy(v[k],D[j]);
        j++;
        k++;
    }
}

void mergeSort(int i, int f, char **v){
    if(i<f){
        int m = (i+f)/2;
        mergeSort(i,m,v);
        mergeSort(m+1,f,v);
        intercala(i,m,f,v);
    }
}

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

    mergeSort(0,n-1,nomes);
    
    printf("\n##### Vetor em ordem #####\n");
    exibeVetor(nomes,n);
    return 0;
}