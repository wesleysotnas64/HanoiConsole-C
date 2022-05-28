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

    //de_para(1, 3);

    //imprime_hanoi();

    return 0;
}

void inicializa_hanoi(){

    int c = 5;
    for(int i = 0; i < TAM; i++){
        torre1.vet[i] = c--;
        torre2.vet[i] = 0;
        torre3.vet[i] = 0;
    }

    torre1.tam = 5;
    torre2.tam = 0;
    torre3.tam = 0;
}

void imprime_hanoi(){
    //torres
    for(int i = 0; i < TAM; i++){
        int valor = hanoi[i].vet[i];
        if(valor == 0) printf(" | ");
        else printf("[%d]", valor);
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

    printf("Origem: %d\n", origem);
    printf("Destino: %d\n", destino);

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

        int mao_aux = hanoi[origem].vet[hanoi[origem].tam];
        printf("Mão: %d", mao_aux);
        if(mao_aux > hanoi[destino].vet[hanoi[destino].tam]){
            printf("Movimento inválido! Peça inicial maior que destino\n");
            sleep(TIME_SLEEP);
        } else{
            hanoi[origem].vet[hanoi[origem].tam] = 0;
            hanoi[origem].tam--;

            hanoi[destino].vet[hanoi[destino].tam] = mao_aux;
            hanoi[destino].tam++;

            printf("Topo da torre destino: %d", hanoi[destino].vet[hanoi[destino].tam-1]);

            printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
            sleep(TIME_SLEEP);
        }
    }
}