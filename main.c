#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


#define PEDRA 1
#define PAPEL 2
#define TESOURA 3


typedef struct
{
    int jogador1;
    int jogador2;
} Jogadas;


typedef struct
{
    int pontosJogador1;
    int pontosJogador2;
    int empates;
} Placar;


void iniciarPartida(Jogadas *partidas, int numeroPartidas, Placar *pontuacao);
void verificaVitoria(Jogadas *partidas, int numeroPartidas, Placar *pontuacao);
int sorteiaMaquina();


int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "Portuguese");

    Placar pontuacao;

    int numeroPartidas, tipoJogo;

    printf("\nPEDRA, PAPEL E TESOURA\n");
    printf("\nQuantas partidas você quer jogar? ");
    fflush(stdin);
    scanf("%d", &numeroPartidas);


    Jogadas partidas[numeroPartidas];


    do
    {
        printf("\nMenu: \n\n 1 - Jogador x Jogador \n 2 - Jogador x Computador\n");
        scanf("%d", &tipoJogo);

        switch(tipoJogo)
        {
        case 1:
            iniciarPartida(&partidas, numeroPartidas, &pontuacao);
            break;
        case 2:
            iniciarPartidaMaquina(&partidas, numeroPartidas, &pontuacao);
            break;
        default:
            break;
        }
    }
    while(tipoJogo != 2);

    return 0;
}


void iniciarPartida(Jogadas *partidas, int numeroPartidas, Placar *pontuacao)
{

    for(int i = 0; i < numeroPartidas; i++)
    {
        printf("\nVamos Jogar? ");
        printf("\nPartida #%d", i+1);
        printf("\nEscolha uma Opção: ");
        printf("\nPedra   [1]");
        printf("\nPapel   [2]");
        printf("\nTesoura [3]\n");
        printf("\nJogador 1: ");
        scanf("%d", &partidas[i].jogador1);
        printf("\nJogador 2: ");
        scanf("%d", &partidas[i].jogador2);
        if(partidas[i].jogador1 < 1 ||partidas[i].jogador1 > 3|| partidas[i].jogador2 < 1 || partidas[i].jogador2 > 3)
        {
            printf("\nEntrada inválida!");
        }
        system("cls");
    }
    system("cls");

    printf("\nResultados: \n");

    verificaVitoria(partidas, numeroPartidas, pontuacao);

    printf("\nTotal de Partidas: %d\n", (pontuacao->pontosJogador1 + pontuacao->pontosJogador2 + pontuacao->empates));
    printf("\nPontos Jogador 1: %d", pontuacao->pontosJogador1);
    printf("\nPontos Jogador 2: %d", pontuacao->pontosJogador2);
    printf("\nEmpates: %d\n", pontuacao->empates);


}


void verificaVitoria(Jogadas *partidas, int numeroPartidas, Placar *pontuacao)
{

    int jogador1, jogador2, contadorJogador1 = 0, contadorJogador2 = 0, contadorEmpate = 0;

    for(int i =0; i < numeroPartidas; i++)
    {
        jogador1 = partidas[i].jogador1;
        jogador2 = partidas[i].jogador2;

        if(jogador1 == jogador2)
        {
            printf("\nEmpatou! Os dois escolheram igual");
            contadorEmpate++;
        }
        else if(jogador1 == PEDRA && jogador2 == TESOURA)
        {
            printf("\nJogador 1 venceu! TESOURA quebra PEDRA");
            contadorJogador1++;
        }
        else if(jogador1 == PEDRA && jogador2 == PAPEL)
        {
            printf("\nJogador 2 venceu! PAPEL embrulha PEDRA");
            contadorJogador2++;
        }
        else if(jogador1 == TESOURA && jogador2 == PAPEL)
        {
            printf("\nJogador 1 venceu! TESOURA corta PAPEL");
            contadorJogador1++;
        }
        else if(jogador1 == TESOURA && jogador2 == PEDRA)
        {
            printf("\nJogador 2 venceu! PEDRA quebra TESOURA");
            contadorJogador2++;
        }
        else if(jogador1 == PAPEL && jogador2 == TESOURA)
        {
            printf("\nJogador 2 venceu! TESOURA corta PAPEL");
            contadorJogador2++;
        }
        else if(jogador1 == PAPEL && jogador2 == PEDRA)
        {
            printf("\nJogador 1 venceu! PAPEL embrulha PEDRA");
            contadorJogador1++;
        }

    }
    pontuacao->pontosJogador1 = contadorJogador1;
    pontuacao->pontosJogador2 = contadorJogador2;
    pontuacao->empates = contadorEmpate;
}


int sorteiaMaquina()
{

    int numeroMaquina = rand () % 3+1;
    return numeroMaquina;
}

void iniciarPartidaMaquina(Jogadas *partidas, int numeroPartidas, Placar *pontuacao)
{

    int numeroComputador = sorteiaMaquina();

    for(int i = 0; i < numeroPartidas; i++)
    {
        printf("\nVamos Jogar? ");
        printf("\nPartida #%d", i+1);
        printf("\nEscolha uma Opção: ");
        printf("\nPedra   [1]");
        printf("\nPapel   [2]");
        printf("\nTesoura [3]\n");
        printf("\nJogador 1: ");
        scanf("%d", &partidas[i].jogador1);
        printf("\nComputador: ");
        partidas[i].jogador2 = numeroComputador;
        if(partidas[i].jogador1 < 1 ||partidas[i].jogador1 > 3|| partidas[i].jogador2 < 1 || partidas[i].jogador2 > 3)
        {
            printf("\nEntrada inválida!");
        }
        system("cls");
    }
    system("cls");

    printf("\nResultados: \n");

    verificaVitoria(partidas, numeroPartidas, pontuacao);

    printf("\nTotal de Partidas: %d\n", (pontuacao->pontosJogador1 + pontuacao->pontosJogador2 + pontuacao->empates));
    printf("\nPontos Jogador 1: %d", pontuacao->pontosJogador1);
    printf("\nPontos Computador: %d", pontuacao->pontosJogador2);
    printf("\nEmpates: %d\n", pontuacao->empates);

}
