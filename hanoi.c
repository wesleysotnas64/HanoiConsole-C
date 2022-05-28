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

    de_para(1, 3);
    imprime_hanoi();

    return 0;
}

void inicializa_hanoi(){

    int c = 5;
    
    for(int i = 0; i < TAM; i++){
        hanoi[0].vet[i] = c--;
        hanoi[1].vet[i] = 0;
        hanoi[2].vet[i] = 0;
    }

    hanoi[0].tam = 5;
    hanoi[1].tam = 0;
    hanoi[2].tam = 0;

}

void imprime_hanoi(){
    //torres
    for(int i = TAM-1; i >= 0; i--){
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

        int mao_aux = hanoi[origem].vet[hanoi[origem].tam-1];

        int inicial_maior_que_destino = mao_aux > hanoi[destino].vet[hanoi[destino].tam-1];
        int destino_eh_zero = hanoi[destino].vet[hanoi[destino].tam-1] == 0;

        printf("Mão: %d\n", mao_aux);
        if(inicial_maior_que_destino){

            if(destino_eh_zero){
                hanoi[origem].vet[hanoi[origem].tam-1] = 0;
                hanoi[origem].tam--;

                hanoi[destino].vet[hanoi[destino].tam] = mao_aux;
                hanoi[destino].tam++;

                printf("Topo da torre destino: %d\n", hanoi[destino].vet[hanoi[destino].tam-1]);

                printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
                sleep(TIME_SLEEP);
            } else{
                printf("Movimento inválido! Peça inicial maior que destino\n");
                sleep(TIME_SLEEP);
            }

            
        } else{
            hanoi[origem].vet[hanoi[origem].tam-1] = 0;
            hanoi[origem].tam--;

            hanoi[destino].vet[hanoi[destino].tam] = mao_aux;
            hanoi[destino].tam++;

            printf("Topo da torre destino: %d\n", hanoi[destino].vet[hanoi[destino].tam-1]);

            printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
            sleep(TIME_SLEEP);
        }
    }
}

