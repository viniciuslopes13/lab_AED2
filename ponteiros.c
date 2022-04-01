#include<stdio.h>
#include<stdlib.h>

int main(){

    //Um ponteiro declarado como void é um ponteiro sem tipo! A função de um ponteiro void é simplesmente armazenar um endereço
    void * ponteiro;

    int * pt; //declaração do ponteiro para armazenar o endereço do bloco alocado
    
    pt = (int *) malloc(10*sizeof(int)); //chamada da função malloc para reservar espaço para 10 elementos do tipo int
    
    //verifica se o endereço de retorno é válido
    if(pt != NULL)
    {
    //…operações com o ponteiro
    }
    
    free(pt); //chama a função free para liberar o bloco indicado por pt
    pt = NULL; //atribui NULL para indicar que o ponteiro não tem um endereço válido
}