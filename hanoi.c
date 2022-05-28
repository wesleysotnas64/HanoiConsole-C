#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 5 //Tamanho de cada torre
#define QTD 3 //Quantidade de torres
#define TIME_SLEEP 3

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
void de_para(int origem, int destino);

int main(){

    inicializa_hanoi();
    imprime_hanoi();

    de_para(1, 2);

    return 0;
}

void inicializa_hanoi(){

    for(int i = 0; i <= TAM; i++) hanoi[0].vet[i] = i+1;
    hanoi[0].tam = 5;

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
    for(int i = 0; i < QTD; i++) printf("-%d-", i+1);
    printf("\n");
    for(int i = 0; i < (QTD-1)*3; i++) printf(" ");
    printf(" hanoi\n");
}

void de_para(int origem, int destino){

    origem--;
    destino--;

    //verificar se o movimento é válido
    int lim_origem  = (origem  < 0) || (origem  > QTD);
    int lim_destino = (destino < 0) || (destino > QTD);
    int iguais      = (origem == destino);

    

    if(lim_origem || lim_destino || iguais){
        //Movimento inválido
        printf("Movimento inválido!\n");
        printf("Passei aqui!\n");
        sleep(3);
    } else{
        int tam_origem  = hanoi[origem].tam-1;
        int tam_destino = hanoi[destino].tam-1;

        int mao_aux = hanoi[origem].vet[tam_origem];

        if(mao_aux > hanoi[destino].vet[tam_destino]){
            printf("Movimento inválido!\n");
            sleep(TIME_SLEEP);
        } else{
            hanoi[origem].vet[tam_origem] = 0;
            hanoi[origem].tam--;

            hanoi[destino].vet[tam_destino+1] = mao_aux;
            hanoi[destino].tam++;

            printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
            sleep(TIME_SLEEP);
        }
    }
}