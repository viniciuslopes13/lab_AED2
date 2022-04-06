/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>

/*Cria estrutura ponto*/
struct ponto {
    int x;
    int y;
};

/*Calcula distância entre dois pontos*/
float calculaDistancia(int x1, int y1, int x2, int y2) {
    return sqrt( pow(x2-x1,2) + pow(y2-y1, 2) );
}

/*Recebe um vetor de pontos e informa os pontos mais distantes do vetor.*/
void pontosDistantes(struct ponto *pts, int n){
    float distMax = 0;
    float dist;
    struct ponto p1 = pts[0];
    struct ponto p2 = pts[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist = calculaDistancia(pts[i].x,pts[i].y,pts[j].x,pts[j].y);
            if(dist>distMax){
                p1 = pts[i];
                p2 = pts[j];
                distMax = dist;
            }
        }
    }
    printf("Os pontos mais distantes entre si sao: (%d, %d) e (%d, %d)",p1.x,p1.y,p2.x,p2.y);
}

int main()
{
    int n,x,y;
    printf("Informe a quantidade de pontos: ");
    scanf("%d",&n);
    struct ponto *pts = (struct ponto *) malloc(n*sizeof(struct ponto));
    for(int i=0;i<n;i++){
        printf("Informe as coordenadas x e y do ponto %d: ",i);
        scanf("%d %d",&pts[i].x,&pts[i].y);
    }
    pontosDistantes(pts,n);
    return 0;
}
