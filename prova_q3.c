/*
Aluno: Francisco Vinícius Lopes Costa
Matrícula: 2021022958
*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*Cria estrutura ponto*/
typedef struct {
    int x;
    int y;
} ponto;

/*Cria estrutura retangulo*/
typedef struct {
    ponto pie;
    ponto psd;
} retangulo;

/*Calcula a area de um retangulo*/
float areaRetangulo(retangulo ret){
    ponto pse = {ret.pie.x, ret.psd.y};
    ponto pid = {ret.psd.x, ret.pie.y};
    float area = (pse.y - ret.pie.y) * (ret.psd.x - pse.x);
    return area;
}

/*Verifica se um ponto está contido num retânguo*/
int interiroRetangulo(retangulo r, ponto p){
    if((p.x>=r.pie.x) && (p.x<=r.psd.x) && (p.y>=r.pie.y) && (p.y<=r.psd.y)) return 1;
    return 0;
}

/*Verifica se um retângulo está contido noutro retânguo*/
int retanguloContido(retangulo r1, retangulo r2){
    if((interiroRetangulo(r2,r1.pie)) && (interiroRetangulo(r2,r1.psd))) return 1;
    return 0;
}

int main()
{
    ponto p1 = {1,1};
    ponto p2 = {4,4};
    retangulo ret = {p1, p2};
    ponto p3 = {-1,3};

    ponto p4 = {-1,2};
    ponto p5 = {3,4};
    retangulo ret1 = {p4,p5};

    printf("\nA area do retangulo eh: %.2f\n", areaRetangulo(ret));
    if(interiroRetangulo(ret,p3)){
        printf("\nO ponto (%d,%d) esta contido no retangulo definido por (%d %d) e (%d %d).\n",p3.x,p3.y,p1.x,p1.y,p2.x,p2.y);
    }else{
        printf("\nO ponto (%d,%d) NAO esta contido no retangulo definido por (%d %d) e (%d %d).\n",p3.x,p3.y,p1.x,p1.y,p2.x,p2.y);
    }

    if(retanguloContido(ret1,ret)){
        printf("\nO ret. def. por (%d %d) e (%d %d) esta cont. no ret. def. por (%d %d) e (%d %d)\n",ret1.pie.x,ret1.pie.y,ret1.psd.x,ret1.psd.y,ret.pie.x,ret.pie.y,ret.psd.x,ret.psd.y);
    }else{
        printf("\nO ret. def. por (%d %d) e (%d %d) NAO esta cont. no ret. def. por (%d %d) e (%d %d)\n",ret1.pie.x,ret1.pie.y,ret1.psd.x,ret1.psd.y,ret.pie.x,ret.pie.y,ret.psd.x,ret.psd.y);
    }
    
    return 0;
}
