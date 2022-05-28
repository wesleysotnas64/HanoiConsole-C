#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 4 //Tamanho de cada torre
#define QTD 3 //Quantidade de torres
#define TIME_SLEEP 3

//Struct para definr a estrutura básica da torre
typedef struct torre TORRE;
struct torre{
    int tam;
    int vet[TAM];
};

TORRE hanoi[QTD]; //Tabuleiro. Hanoi básico com 3 torres
int   jogadas;

//Assinaturas
void inicializa_hanoi();
void imprime_hanoi();
void de_para(int origem, int destino);
void move(int origem, int destino, int mao);
void verifica_hanoi();
void menu();

int main(){

    inicializa_hanoi();
    menu();

    //de_para(1, 3);
    //imprime_hanoi();

    return 0;
}

void inicializa_hanoi(){

    int c = TAM;
    jogadas = 0;
    
    for(int i = 0; i < TAM; i++){
        hanoi[0].vet[i] = c--;
        hanoi[1].vet[i] = 0;
        hanoi[2].vet[i] = 0;
    }

    hanoi[0].tam = TAM;
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
    printf("Jogadas: %d\n", jogadas);
}

void de_para(int origem, int destino){

    origem--;
    destino--;

    //verificar se o movimento é válido
    int lim_origem   = (origem  < 0) || (origem  > QTD);
    int lim_destino  = (destino < 0) || (destino > QTD);
    int iguais       = (origem == destino);
    int origem_vazia = (hanoi[origem].tam == 0);

    if(lim_origem || lim_destino || iguais || origem_vazia){
        //Movimento inválido
        printf("Movimento inválido!\n");
        sleep(3);
    } else{

        int mao_aux = hanoi[origem].vet[hanoi[origem].tam-1];

        int inicial_maior_que_destino = mao_aux > hanoi[destino].vet[hanoi[destino].tam-1];
        int destino_eh_zero           = hanoi[destino].vet[hanoi[destino].tam-1] == 0;

        if(inicial_maior_que_destino){

            if(destino_eh_zero){
                move(origem, destino, mao_aux);

                printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
                sleep(TIME_SLEEP);
            } else{
                printf("Movimento inválido! Peça inicial maior que destino\n");
                sleep(TIME_SLEEP);
            }

            
        } else{
            move(origem, destino, mao_aux);

            printf("Moveu [%d]: de %d | para %d\n", mao_aux, origem+1, destino+1);
            sleep(TIME_SLEEP);
        }
    }
    menu();
}

void move(int origem, int destino, int mao){

    hanoi[origem].vet[hanoi[origem].tam-1] = 0;
    hanoi[origem].tam--;

    hanoi[destino].vet[hanoi[destino].tam] = mao;
    hanoi[destino].tam++;

    jogadas++;

    verifica_hanoi();
}

void verifica_hanoi(){
    if(hanoi[QTD-1].tam == TAM){
        imprime_hanoi();
        printf("\nFIM DE JOGO! PARABÉNS!\n");
        sleep(TIME_SLEEP*2);
        inicializa_hanoi();
    }

    menu();
}

void menu(){
    system("clear");
    printf("--------------\n");
    printf("TORRE DE HANOI\n");
    printf("--------------\n");

    imprime_hanoi();

    int origem;
    int destino;

    printf("---------\n");
    printf("Origem : ");
    scanf("%d", &origem);
    printf("Destino: ");
    scanf("%d", &destino);

    de_para(origem, destino);
}