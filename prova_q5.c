#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno Aluno;
struct aluno {
    char nome[81];
    float nota;
};

void ordem_alfabetica (int n, Aluno* v){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
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

Aluno busca (int n, Aluno* v, char* nome){
    Aluno a = {" ",0};
    int i=0;
    int f = n-1;
    while (i<=f){
        int meio = (i+f)/2;
        int teste = strcmp(v[meio].nome,nome);
        if(teste==0){
            return v[meio];
        }else if(teste<0){
            i = meio+1;
        }else{
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
