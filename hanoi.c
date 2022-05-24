#include <stdio.h>
#include <stdlib.h>

#define TAM 5 //Tamanho de cada torre
#define QTD 3 //Quantidade de torres

//Struct para definr a estrutura básica da torre
typedef struct torre TORRE;
struct torre{
    int tam;
    int vet[TAM];
};

TORRE hanoi[QTD]; //Tabuleiro. Hanoi básico com 3 torres

//Assinaturas
void inicializa_hanoi();
void imprime_hanoi();

int main(){

    inicializa_hanoi();
    imprime_hanoi();

    return 0;
}

void inicializa_hanoi(){

    for(int i = 0; i <= TAM; i++) hanoi[0].vet[i] = i+1;

    for(int i = 1; i < QTD; i++){
        hanoi[i].tam = 0;
        for(int j = 0; j < TAM; j++)
            hanoi[i].vet[j] = 0;
    }
}

void imprime_hanoi(){
    //torres
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < QTD; j++){
            int valor = hanoi[j].vet[i];
            if(valor == 0) printf(" | ");
            else printf("[%d]", valor);
        }
        printf("\n");
    }

    //base
    for(int i = 0; i < QTD*3; i++) printf("-");
    printf("\n");
    for(int i = 0; i < (QTD-1)*3; i++) printf(" ");
    printf(" hanoi\n");
}