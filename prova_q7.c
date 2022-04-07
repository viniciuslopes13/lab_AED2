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
    /*
        A estratégia é dividir o vetor v ao meio em dois vetores menores, por isso é calculado n1 e n2,
        que são respectivamente a quantidade de elementos do inicio ao meio (n1) e do meio ao fim (n2).

    */
    int n1 = (m-e)+1;
    int n2 = (d-m);
    int k = e;
    char **E = alocaNomes(n1);
    char **D = alocaNomes(n2);
    int i,j;
    /*
        Esse primeiro for pega os elementos da primeira metade de v e insere no vetor E.
    */   
    for(i=0;i<n1;i++){
        strcpy(E[i],v[e+i]);
    }
    /*
        Esse segundo for pega os elementos da segunda metade de v e insere no vetor D.
    */   
    for(j=0;j<n2;j++){
        strcpy(D[j],v[m+1+j]);
    }
    i=0;
    j=0;
    /*
        Esse while vai executar até o vetor D ou E ter sido totalmente percorrido.
        A cada iteração é verificado qual elemento é menor nas posições indicadas por i e j nos vetore E e D,
        e aí o menor da comparação é copiado para o vetor v.
        No inicio k,i e j são iguais a 0(zero); ou seja, na primeira comparação é comparado E[0] com D[0], o menor
        dos dois é copiado para V[0], dependendo da comparação i ou j são incrementados em uma unidade e k é de
        certeza incrementado. Agora tem-se k=1, i=i(supondo que i incrementou) e j=0, na proxima comparação temos
        E[1] com D[0], o menor dos dois é inserido em V[1], e assim por diante até um dos verores (E ou D) serem
        totalmente percorridos. 
    */
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
    /*
        Quando um dos dois vetor é totalmente percorrido ainda sobrará elementos no outro. Esses whiles abaixo
        servem justamente para inserir em V o restante dos elemento do vetor (E ou D) que ainda tenha elementos.
    */
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
    /*
        Quando o i<f significa que tem-se mais de um elemento no vetor para ordenar, daí faz-se a chamada
        recursiva para ir quebrando o problema em problemas menores. Por fim é chamada a função intercala 
        para ordenar o vetor globalmete.
    */
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