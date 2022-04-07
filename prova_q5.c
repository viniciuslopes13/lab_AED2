/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Cria estrutura Aluno*/
typedef struct aluno Aluno;
struct aluno {
    char nome[81];
    float nota;
};

/*Recebe um ponteiro para um vetor de alunos e a quantidade de alunos, e exibe em ordem alfabética*/
void ordem_alfabetica (int n, Aluno* v){
    int i,j;
    /*
        O laço mais interno permite que cada elemento seja comparado com todos os outros do vetor
        até encontrar um elemento que seja igual ou maior.
    */
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            /*A funcão strcmp(string1,string2) compara duas strings; 
             - caso a primeira seja menor (alfabeticamente) que a segunda, a função restorna -1; 
             - se as strings são iguais o retorno é 0; e 
             - se a primeira é maior que a segunda o retorno é 1*/
            if(strcmp(v[j].nome, v[j+1].nome)>0){
                Aluno temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    printf("\n##### ALUNOS EM ORDEM ALFABETICA #####\n");
    for(i=0;i<n;i++){
        printf("%s   Nota: %.2f\n",v[i].nome,v[i].nota);
    }
}

/*
    Função que retorna um aluno buscado pelo nome, caso esteja presente no vetor de alunos
    passado como parâmetro.
*/
Aluno busca (int n, Aluno* v, char* nome){
    Aluno a = {" ",0};
    int i=0;
    int f = n-1;
    while (i<=f){
        int meio = (i+f)/2;
        /*Verifica se o aluno do nome do vetor é igual, maior ou menor que a palavra buscada.*/
        int teste = strcmp(v[meio].nome,nome);
        if(teste==0){
            /*
                Se o resultado do teste for igual zero, significa que a palavra buscada é o nome
                do aluno que está no meio do vetor.
            */
            return v[meio];
        }else if(teste<0){
            /*
                Se o resultado do teste for -1, significa que a palavra buscada está entre o meio do
                vetor e o final, pois a palavra é maior (alfabeticamente) do que a nome do aluno que está no meio
                do vetor.
            */
            i = meio+1;
        }else{
            /*
                Se teste=1, significa que o nome do aluno que está no meio do vetor é maior que a palavra buscada,
                logo a palavra buscada está entre o inicio e o meio do vetor.
            */
            f = meio-1;
        }
    }
    return a;
}

int main(){
    int n,i;
    printf("Quantidade de alunos: ");
    scanf("%d",&n);
    Aluno* v = (Aluno*) malloc(n*sizeof(Aluno));
    printf("Informe o nome e a nota dos alunos: \n");
    for(i=0;i<n;i++){
        scanf("%s %f",v[i].nome,&v[i].nota);
    }
    ordem_alfabetica(n,v);
    system("pause");
    char* nomeBusca = (char*) malloc(81*sizeof(char));
    printf("Informe o nome que deseja buscar: ");
    scanf("%s",nomeBusca);
    Aluno alunoBuscado = busca(n,v,nomeBusca);
    if(strcmp(alunoBuscado.nome," ")==0){
        printf("\n################\n");
        printf("ALUNO NAO ENCONTRADO!\n");
        printf("################\n");
    }else{
        printf("\n################\n");
        printf("%s %.2f\n", alunoBuscado.nome, alunoBuscado.nota);
        printf("################\n");
    }
    return 0;
}
