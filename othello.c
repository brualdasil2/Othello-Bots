/*
PARA COMPILAR, RODAR O SEGUINTE COMANDO:

gcc othello.c .\Libraries\libconio.a
*/

#include <stdio.h>
#include <stdlib.h>
#include "./Libraries/conio2.h"
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <limits.h>
#include <string.h>
#include <locale.h>


#define TAM 8

//unsigned long posicoesAnalisadas;


typedef struct{

    int x;
    int y;

}POSICAO;

void resetarTabuleiro(char tabuleiro[TAM][TAM]){

    int i, j;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){

            tabuleiro[i][j] = ' ';
        }
    }

    tabuleiro[3][3] = 'A';
    tabuleiro[4][4] = 'A';
    tabuleiro[3][4] = 'B';
    tabuleiro[4][3] = 'B';


}

void exibePeca(char peca, int x, int y){

    switch(peca){
        case 'a':
            textbackground(LIGHTBLUE);
            break;
        case 'b':
            textbackground(LIGHTRED);
            break;
        case 'A':
            textbackground(BLUE);
            break;
        case 'B':
            textbackground(RED);
            break;
        case ' ':
            textbackground(BLACK);
            break;
        case 'P':
            textbackground(LIGHTGRAY);
            break;
    }

    putchxy(3 + x*4, 2 + y*2, ' ');

}


void exibeTabuleiro(char tabuleiro[TAM][TAM]){

    int i, j;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){

            //printf("%c", tabuleiro[i][j]);
            exibePeca(tabuleiro[j][i], j, i);
        }
    }
}

void exibeGrade(){

    int i, j;
    gotoxy(0, 0);

    for (j = 0; j < TAM; j++){
        for (i = 0; i < TAM; i++){
            printf(" ---");
        }
        printf("\n|");
        for (i = 0; i < TAM; i++){
            printf("   |");
        }
        printf("\n");
    }
    for (i = 0; i < TAM; i++){
        printf(" ---");
    }
}

void colocarPeca(char tabuleiro[TAM][TAM], char jogador, int x, int y, int exibir){

    tabuleiro[x][y] = jogador;
    if (exibir)
        exibePeca(jogador, x, y);
}

void trocarJogador(char* jogador){

    if (*jogador == 'A')
        *jogador = 'B';
    else
        *jogador = 'A';
}


int olharDirecaoPossivel(char tabuleiro[TAM][TAM], char jogador, int dir, int x, int y){

    int encontrouOponente = 0;

    while (1){

            switch(dir){
            case 1:
                if (y > 0){
                    y--;
                }
                else{
                    return 0;
                }
                break;
            case 2:
                if (y > 0 && x < TAM - 1){
                    y--;
                    x++;
                }
                else{
                    return 0;
                }
                break;
            case 3:
                if (x < TAM - 1){
                    x++;
                }
                else{
                    return 0;
                }
                break;
            case 4:
                if (y < TAM - 1 && x < TAM - 1){
                    y++;
                    x++;
                }
                else{
                    return 0;
                }
                break;
            case 5:
                if (y < TAM - 1){
                    y++;
                }
                else{
                    return 0;
                }
                break;
            case 6:
                if (y < TAM - 1 && x > 0){
                    y++;
                    x--;
                }
                else{
                    return 0;
                }
                break;
            case 7:
                if (x > 0){
                    x--;
                }
                else{
                    return 0;
                }
                break;
            case 8:
                if (y > 0 && x > 0){
                    y--;
                    x--;
                }
                else{
                    return 0;
                }
                break;

        }



        if (tabuleiro[x][y] == ' '){
            return 0;
        }
        else{
            if (jogador == 'A'){
                if (tabuleiro[x][y] == 'B'){
                    encontrouOponente = 1;
                }
                else if (tabuleiro[x][y] == 'A'){
                    if (encontrouOponente){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
            }
            else if (jogador == 'B'){
                if (tabuleiro[x][y] == 'A'){
                    encontrouOponente = 1;
                }
                else if (tabuleiro[x][y] == 'B'){
                    if (encontrouOponente){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
}

int capturaEntreDuas(char jogador, int x1, int y1, int x2, int y2, char tabuleiro[TAM][TAM], int dir, int exibir){

    //gotoxy(1, 18);
    //printf("Capturando entre %d, %d e %d, %d.", x1, y1, x2, y2);
    int capturados = 0;

    while(x1 != x2 || y1 != y2){


            switch(dir){
            case 1:
                if (y1 > 0){
                    y1--;
                }
                else{
                    return capturados;
                }
                break;
            case 2:
                if (y1 > 0 && x1 < TAM - 1){
                    y1--;
                    x1++;
                }
                else{
                    return capturados;
                }
                break;
            case 3:
                if (x1 < TAM - 1){
                    x1++;
                }
                else{
                    return capturados;
                }
                break;
            case 4:
                if (y1 < TAM - 1 && x1 < TAM - 1){
                    y1++;
                    x1++;
                }
                else{
                    return capturados;
                }
                break;
            case 5:
                if (y1 < TAM - 1){
                    y1++;
                }
                else{
                    return capturados;
                }
                break;
            case 6:
                if (y1 < TAM - 1 && x1 > 0){
                    y1++;
                    x1--;
                }
                else{
                    return capturados;
                }
                break;
            case 7:
                if (x1 > 0){
                    x1--;
                }
                else{
                    return capturados;
                }
                break;
            case 8:
                if (y1 > 0 && x1 > 0){
                    y1--;
                    x1--;
                }
                else{
                    return capturados;
                }
                break;

        }

        if (tabuleiro[x1][y1] != jogador){
            colocarPeca(tabuleiro, jogador, x1, y1, exibir);
            capturados++;
        }

       // gotoxy(1, 19);
        //printf("Colocando peca  em %d, %d", x1, y1);

    }

    return capturados;
}

int olharDirecaoCaptura(char tabuleiro[TAM][TAM], char jogador, int dir, int x, int y, int exibir){

    int encontrouOponente = 0, capturados = 0;
    int pecaX = x, pecaY = y;

    while (1){

            switch(dir){
            case 1:
                if (y > 0){
                    y--;
                }
                else{
                    return capturados;
                }
                break;
            case 2:
                if (y > 0 && x < TAM - 1){
                    y--;
                    x++;
                }
                else{
                    return capturados;
                }
                break;
            case 3:
                if (x < TAM - 1){
                    x++;
                }
                else{
                    return capturados;
                }
                break;
            case 4:
                if (y < TAM - 1 && x < TAM - 1){
                    y++;
                    x++;
                }
                else{
                    return capturados;
                }
                break;
            case 5:
                if (y < TAM - 1){
                    y++;
                }
                else{
                    return capturados;
                }
                break;
            case 6:
                if (y < TAM - 1 && x > 0){
                    y++;
                    x--;
                }
                else{
                    return capturados;
                }
                break;
            case 7:
                if (x > 0){
                    x--;
                }
                else{
                    return capturados;
                }
                break;
            case 8:
                if (y > 0 && x > 0){
                    y--;
                    x--;
                }
                else{
                    return capturados;
                }
                break;

        }

        if (tabuleiro[x][y] == ' '){
            return capturados;
        }
        else{
            if (jogador == 'A'){
                if (tabuleiro[x][y] == 'B'){
                    encontrouOponente = 1;
                }
                else if (tabuleiro[x][y] == 'A'){
                    if (encontrouOponente){
                        capturados += capturaEntreDuas(jogador, pecaX, pecaY, x, y, tabuleiro, dir, exibir);
                        return capturados;
                    }
                    else{
                        return capturados;
                    }
                }
            }
            else if (jogador == 'B'){
                if (tabuleiro[x][y] == 'A'){
                    encontrouOponente = 1;
                }
                else if (tabuleiro[x][y] == 'B'){
                    if (encontrouOponente){
                        capturados += capturaEntreDuas(jogador, pecaX, pecaY, x, y, tabuleiro, dir, exibir);
                        return capturados;
                    }
                    else{
                        return capturados;
                    }
                }
            }
        }
    }
}

int encontraJogadas(POSICAO jogadasPossiveis[], char tabuleiro[TAM][TAM], char jogador){

    int i, j, dir = 1, possiveis = 0;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){

            if (tabuleiro[j][i] == ' '){

                while (dir <= 8){
                    if (olharDirecaoPossivel(tabuleiro, jogador, dir, j, i)){

                        jogadasPossiveis[possiveis].x = j;
                        jogadasPossiveis[possiveis].y = i;
                        possiveis++;
                        break;
                    }
                    else{

                        dir++;
                    }
                }
                dir = 1;
            }
        }
    }

    return possiveis;
}

void exibeJogadasPossiveis(POSICAO jogadasPossiveis[], int possiveis, char jogador){

    int i;

    for (i = 0; i < possiveis; i++){
        exibePeca('P', jogadasPossiveis[i].x, jogadasPossiveis[i].y);
    }

}

void limparPossiveis(POSICAO jogadasPossiveis[], int possiveis){

    int i;

    for (i = 0; i < possiveis; i++){
        exibePeca(' ', jogadasPossiveis[i].x, jogadasPossiveis[i].y);
    }
}

int capturarPecas(char tabuleiro[TAM][TAM], char jogador, int x, int y, int exibir){

    int dir = 1, capturados = 0;

    while (dir <= 8){

       // getch();
        //gotoxy(1, 18);
        //printf("Testando direcao %d", dir);
        capturados += olharDirecaoCaptura(tabuleiro, jogador, dir, x, y, exibir);
        dir++;
    }

    return capturados;
}

int selecionarJogada(POSICAO jogadasPossiveis[], int possiveis, char jogador){

    int selecao = 0, selecionado = 0, pisca = 0, piscaFrames = 0;


    exibeJogadasPossiveis(jogadasPossiveis, possiveis, jogador);
    while (!selecionado){
        piscaFrames++;
        if (piscaFrames == 15){
            if (pisca){
                exibePeca(jogador + 32, jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y);
                pisca = 0;
            }
            else{
                exibePeca(' ', jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y);
                pisca = 1;
            }
            piscaFrames = 0;
        }
        gotoxy(1, 18);

        if (kbhit()){
            exibeJogadasPossiveis(jogadasPossiveis, possiveis, jogador);
            switch(getch()){
                case 'a':
                    if (selecao > 0)
                        selecao--;
                    else
                        selecao = possiveis - 1;
                    break;
                case 'd':
                    if (selecao < possiveis - 1)
                        selecao++;
                    else
                        selecao = 0;
                    break;
                case '\r':
                    selecionado = 1;
                    break;
            }
        }
        gotoxy(1, 18);
        Sleep(10);
    }

    return selecao;
}


int aleatorioEntre(int min, int max)
{
    int intervalo = max - min + 1;
    int numero = (rand()%intervalo) + min;

    return numero;
}

void copiaTabuleiro(char tabuleiro[TAM][TAM], char copia[TAM][TAM]){

    int i, j;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            copia[i][j] = tabuleiro[i][j];
        }
    }
}

int indiceMaiorDoVetor(int vetor[], int tamanho){

    int i, maior = 0;

    for (i = 1; i < tamanho; i++){
        if (vetor[i] > vetor[maior]){
            maior = i;
        }
    }
    return maior;
}

int contarPecasJogador(char jogador, char tabuleiro[TAM][TAM]){

    int i, j, cont = 0;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if (tabuleiro[i][j] == jogador){
                cont++;
            }
        }
    }

    return cont;
}

int contarTotalPecas(char tabuleiro[TAM][TAM]){

    int i, j, cont = 0;

    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if (tabuleiro[i][j] != ' '){
                cont++;
            }
        }
    }

    return cont;
}

int avaliarPosicao(char tabuleiro[TAM][TAM]){

    int i, j, avaliacao = 0, totalPecas;

    totalPecas = contarTotalPecas(tabuleiro);
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if (tabuleiro[i][j] == 'B'){

                //come�o do jogo
                if (totalPecas < 16){
                    if (i >= 2 && i <= 5 && j >= 2 && j <= 5){
                        avaliacao += 10; //pe�as do meiao valem 10
                    }
                    else if (i == 0 || i == 7 || j == 0 || j == 7){
                        if ((i >= 1 && i <= 6) || (j >= 1 && j <= 6)){
                            avaliacao += 100; //pe�as da borda valem 100
                        }
                        else{
                            avaliacao += 150; //pe�as da quina valem 150
                        }
                    }
                    else{
                        avaliacao -= 50; //pe�as da camada intermedi�ria s�o ruins
                    }
                }
                else if (totalPecas < 56){

                    if ((i == 1 && j == 1) || (i == 6 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 6)){
                        avaliacao -= 50; //pe�as que dao diagonal pra quina s�o ruins
                    }
                    else if (i >= 1 && i <= 6 && j >= 1 && j <= 6){
                        avaliacao += 10; //pe�as do meio valem 10
                    }
                    else {
                        if ((i >= 1 && i <= 6) || (j >= 1 && j <= 6)){
                            if ((i >= 2 && i <= 5) || (j >= 2 && j <= 5)){
                                avaliacao += 50; //pe�as da borda valem 50
                            }
                            else{
                                avaliacao -= 20; //pe�as que dao acesso � quina s�o ruins
                            }
                        }
                        else{
                            avaliacao += 150; //pe�as da quina valem 100
                        }
                    }
                }
                else{
                    avaliacao += 10;
                }
            }
            else if (tabuleiro[i][j] == 'A'){

                //come�o do jogo
                if (totalPecas < 16){
                    if (i >= 2 && i <= 5 && j >= 2 && j <= 5){
                        avaliacao -= 10; //pe�as do meiao valem 10
                    }
                    else if (i == 0 || i == 7 || j == 0 || j == 7){
                        if ((i >= 1 && i <= 6) || (j >= 1 && j <= 6)){
                            avaliacao -= 100; //pe�as da borda valem 100
                        }
                        else{
                            avaliacao -= 150; //pe�as da quina valem 150
                        }
                    }
                    else{
                        avaliacao += 50; //pe�as da camada intermedi�ria s�o ruins
                    }
                }
                else if (totalPecas < 56){

                    if ((i == 1 && j == 1) || (i == 6 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 6)){
                        avaliacao += 50; //pe�as que dao diagonal pra quina s�o ruins
                    }
                    else if (i >= 1 && i <= 6 && j >= 1 && j <= 6){
                        avaliacao -= 10; //pe�as do meio valem 10
                    }
                    else {
                        if ((i >= 1 && i <= 6) || (j >= 1 && j <= 6)){
                            if ((i >= 2 && i <= 5) || (j >= 2 && j <= 5)){
                                avaliacao -= 50; //pe�as da borda valem 50
                            }
                            else{
                                avaliacao += 20; //pe�as que dao acesso � quina s�o ruins
                            }
                        }
                        else{
                            avaliacao -= 150; //pe�as da quina valem 100
                        }
                    }
                }
                else{
                    avaliacao -= 10;
                }
            }
        }
    }

    return avaliacao;
}

void simularJogada(char tabuleiro[TAM][TAM], char jogador, POSICAO jogadasPossiveis[], int jogada){

    int capturados;

    tabuleiro[jogadasPossiveis[jogada].x][jogadasPossiveis[jogada].y] = jogador;
    capturados = capturarPecas(tabuleiro, jogador, jogadasPossiveis[jogada].x, jogadasPossiveis[jogada].y, 0);
}

char oponente(char jogador){

    if (jogador == 'A')
        return 'B';
    else
        return 'A';

}

int botRandom(int possiveis){

    return aleatorioEntre(0, possiveis - 1);
}

int botMaisCapturas(char tabuleiro[TAM][TAM], char jogador, POSICAO jogadasPossiveis[], int possiveis){

    int i;
    char copia[TAM][TAM];
    int avaliacoes[30];



    for (i = 0; i < possiveis; i++){
        copiaTabuleiro(tabuleiro, copia);
        simularJogada(copia, jogador, jogadasPossiveis, i);
        avaliacoes[i] = contarPecasJogador(jogador, copia);
    }

    return indiceMaiorDoVetor(avaliacoes, possiveis);

}

int botMelhorPosicao(char tabuleiro[TAM][TAM], char jogador, POSICAO jogadasPossiveis[], int possiveis){

    int i;
    char copia[TAM][TAM];
    int avaliacoes[30];



    for (i = 0; i < possiveis; i++){
        copiaTabuleiro(tabuleiro, copia);
        simularJogada(copia, jogador, jogadasPossiveis, i);
        avaliacoes[i] = avaliarPosicao(copia);
    }

    return indiceMaiorDoVetor(avaliacoes, possiveis);

}

int minimax(char tabuleiro[TAM][TAM], char jogador, int profundeza, int max_prof, int alfa, int beta){

    int i, possiveis, aval, maxAval = -10000, minAval = 10000, melhorJogada;
    char copia[TAM][TAM];
    POSICAO jogadasPossiveis[30];

    if (profundeza == 0){ //condi��o de parada
        return avaliarPosicao(tabuleiro);
    }
    else{

        possiveis = encontraJogadas(jogadasPossiveis, tabuleiro, jogador);
        if (possiveis == 0){
            trocarJogador(&jogador);
            possiveis = encontraJogadas(jogadasPossiveis, tabuleiro, jogador);
            if (possiveis == 0){
                return avaliarPosicao(tabuleiro);
            }
        }
        for (i = 0; i < possiveis; i++){
            copiaTabuleiro(tabuleiro, copia);
            simularJogada(copia, jogador, jogadasPossiveis, i);
            aval = minimax(copia, oponente(jogador), profundeza - 1, max_prof, alfa, beta);
            if (jogador == 'B'){ //max
                if (aval > maxAval){
                    maxAval = aval;
                    melhorJogada = i;
                    if (aval > alfa) {
                        alfa = aval;
                    }
                    if (beta <= alfa) {
                        break;
                    }
                }
            }
            else{ //min
                if (aval < minAval){
                    minAval = aval;
                    melhorJogada = i;
                    if (aval < beta) {
                        beta = aval;
                    }
                    if (beta <= alfa) {
                        break;
                    }
                }
            }
        }

        if (profundeza == max_prof){
            return melhorJogada;
        }
        else{
            if (jogador == 'B')
                return maxAval;
            else
                return minAval;
        }

    }


}

int jogadaDeQuem(int tipoJogador, char tabuleiro[TAM][TAM], char jogador, POSICAO jogadasPossiveis[], int possiveis){

    int selecao;

    Sleep(500);
    switch(tipoJogador){
        case 0:
            selecao = selecionarJogada(jogadasPossiveis, possiveis, jogador);
            limparPossiveis(jogadasPossiveis, possiveis);
            break;
        case 1:
            selecao = botRandom(possiveis);
            break;
        case 2:
            selecao = botMaisCapturas(tabuleiro, jogador, jogadasPossiveis, possiveis);
            break;
        case 3:
            selecao = minimax(tabuleiro, jogador, 1, 1, -10000, 10000);
            break;
        case 4:
            selecao = minimax(tabuleiro, jogador, 3, 3, -10000, 10000);
            break;
        case 5:
            selecao = minimax(tabuleiro, jogador, 5, 5, -10000, 10000);
            break;
        case 6:
            gotoxy(1, 23);
            printf("Bot esta pensando...");
            selecao = minimax(tabuleiro, jogador, 7, 7, -10000, 10000);
            gotoxy(1, 23);
            printf("                    ");
            break;
    }

    exibePeca(jogador + 32, jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y);
    gotoxy(1, 25);
    Sleep(1000);
    return selecao;
}

void limparBuffer(){
    while(kbhit()){
        getch();
    }
}

int jogarPeca(char tabuleiro[TAM][TAM], char jogador, int* capturados, int saveJogo[TAM][TAM], int* ordemJogada, int tipoJogadorA, int tipoJogadorB){

    int possiveis, selecao, selecionado = 0, k;
    POSICAO jogadasPossiveis[30];

    possiveis = encontraJogadas(jogadasPossiveis, tabuleiro, jogador);

    if (possiveis > 0){

        if (jogador == 'A'){
            if (tipoJogadorA == 0)
                limparBuffer();

            selecao = jogadaDeQuem(tipoJogadorA, tabuleiro, jogador, jogadasPossiveis, possiveis);
            //selecao = minimax(tabuleiro, jogador, PROF);
        }
        else{
            if (tipoJogadorB == 0)
                limparBuffer();
            selecao = jogadaDeQuem(tipoJogadorB, tabuleiro, jogador, jogadasPossiveis, possiveis);
            //selecao = selecionarJogada(jogadasPossiveis, possiveis, jogador);

        }

        //gotoxy(1, 21);
        //printf("Jogada %d: %d, %d", *ordemJogada, jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y);
        colocarPeca(tabuleiro, jogador, jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y, 1);
        *capturados = capturarPecas(tabuleiro, jogador, jogadasPossiveis[selecao].x, jogadasPossiveis[selecao].y, 1);
        saveJogo[jogadasPossiveis[selecao].x][jogadasPossiveis[selecao].y] = *ordemJogada;
        (*ordemJogada)++;
        return 1;
    }
    else{
        return 0;
    }
}






void exibePontuacoes(int a, int b){

    gotoxy(1, 19);
        textbackground(BLUE);
        printf(" ");
        textbackground(BLACK);
        printf(" %d  ", a);
        gotoxy(1, 20);
        textbackground(RED);
        printf(" ");
        textbackground(BLACK);
        printf(" %d  ", b);
}

void salvarJogo(int saveJogo[TAM][TAM], int pontuacaoA, int pontuacaoB){

    int i, j, k;
    FILE* arq;
    char nomeArq[50];

    gotoxy(1, 25);
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    strcat(nomeArq, ".txt");

    if (!(arq = fopen(nomeArq, "w"))){
        printf("Erro na criacao do arquivo!");
    }
    else{

        for (i = 0; i < TAM; i++){
            for (k = 0; k < TAM; k++){
                fprintf(arq, " ---");
            }
            fprintf(arq, "\n");
            for (j = 0; j < TAM; j++){
                fprintf(arq, "|");
                if (saveJogo[j][i] != 0)
                    fprintf(arq, "%2d", saveJogo[j][i]);
                else{
                    fprintf(arq, "  ");
                }
                fprintf(arq, " ");
            }
            fprintf(arq, "|\n");
        }
        for (k = 0; k < TAM; k++){
                fprintf(arq, " ---");
        }
        fprintf(arq, "\n\nPlacar final: %d x %d", pontuacaoA, pontuacaoB);
        fclose(arq);
    }

}

void jogarPartida(int tipoJogadorA, int tipoJogadorB){

    char tabuleiro[TAM][TAM];
    char jogador = 'A';
    int pontuacaoA = 2, pontuacaoB = 2, capturados, semTurno = 0, ordemJogada = 1;
    int saveJogo[TAM][TAM] = {0};
    resetarTabuleiro(tabuleiro);
    exibeGrade();
    exibeTabuleiro(tabuleiro);

    while(1){

        pontuacaoA = contarPecasJogador('A', tabuleiro);
        pontuacaoB = contarPecasJogador('B', tabuleiro);
        exibePontuacoes(pontuacaoA, pontuacaoB);
        if(jogarPeca(tabuleiro, jogador, &capturados, saveJogo, &ordemJogada, tipoJogadorA, tipoJogadorB)){

            semTurno = 0;
        }
        else{
            semTurno++;
        }

        trocarJogador(&jogador);

        if (semTurno == 2){

            break;
        }

    }

    gotoxy(1, 21);
    printf("FIM DE JOGO!\n");
    if (pontuacaoA > pontuacaoB){
        printf("Vencedor: ");
        textbackground(BLUE);
        printf(" ");
    }
    else if (pontuacaoB > pontuacaoA){
        printf("Vencedor: ");
        textbackground(RED);
        printf(" ");
    }
    else{
        printf("Empate.");
    }

    textbackground(BLACK);
    salvarJogo(saveJogo, pontuacaoA, pontuacaoB);
}

int pertenceAsPosicoes(int x, int y, POSICAO posicoes[], int tam){

    int pertence = 0, i;

    for (i = 0; i < tam; i++){
        if (x == posicoes[i].x && y == posicoes[i].y){
            pertence = 1;
        }
    }
    return pertence;
}

void desenhaLetra(int x, int y, int cor, POSICAO posicoes[], int tam){

    int i, j;

    for (i = 0; i < 5; i++){
        gotoxy(x, y + i);
        for (j = 0; j < 3; j++){
            if (pertenceAsPosicoes(j, i, posicoes, tam)){
                textbackground(cor);
            }
            else{
                textbackground(BLACK);
            }
            printf("  ");
        }
        textbackground(BLACK);
        printf("\n");
    }
}

POSICAO novaPos(int x, int y){

    POSICAO pos;
    pos.x = x;
    pos.y = y;

    return pos;
}

void desenhaTitulo(){

    POSICAO posicoesO[12] = {novaPos(0, 0), novaPos(1, 0), novaPos(2, 0), novaPos(0, 1), novaPos(2, 1), novaPos(0, 2), novaPos(2, 2), novaPos(0, 3), novaPos(2, 3), novaPos(0, 4), novaPos(1, 4), novaPos(2, 4)};
    POSICAO posicoesT[7] = {novaPos(0, 0), novaPos(1, 0), novaPos(2, 0), novaPos(1, 1), novaPos(1, 2), novaPos(1, 3), novaPos(1, 4)};
    POSICAO posicoesH[11] = {novaPos(0, 0), novaPos(0, 1), novaPos(0, 2), novaPos(0, 3), novaPos(0, 4), novaPos(1, 2), novaPos(2, 0), novaPos(2, 1), novaPos(2, 2), novaPos(2, 3), novaPos(2, 4)};
    POSICAO posicoesE[11] = {novaPos(0, 0), novaPos(0, 1), novaPos(0, 2), novaPos(0, 3), novaPos(0, 4), novaPos(1, 0), novaPos(2, 0), novaPos(1, 2), novaPos(2, 2), novaPos(1, 4), novaPos(2, 4)};
    POSICAO posicoesL[7] = {novaPos(0, 0), novaPos(0, 1), novaPos(0, 2), novaPos(0, 3), novaPos(0, 4), novaPos(1, 4), novaPos(2, 4)};

    desenhaLetra(10, 3, BLUE, posicoesO, 12);
    desenhaLetra(18, 3, RED, posicoesT, 7);
    desenhaLetra(26, 3, BLUE, posicoesH, 11);
    desenhaLetra(34, 3, RED, posicoesE, 11);
    desenhaLetra(42, 3, BLUE, posicoesL, 7);
    desenhaLetra(50, 3, RED, posicoesL, 7);
    desenhaLetra(58, 3, BLUE, posicoesO, 12);

}

void menuInicial(int* tipoJogadorA, int* tipoJogadorB){

    int selecao = 0, selecionando = 1, jogadorPessoa = 0;

    desenhaTitulo();
    gotoxy(15, 10);
    printf("   vs Jogador          vs Bot");

    while(selecionando){
        gotoxy(15 + 20*selecao, 10);
        printf("-> ");
        gotoxy(1, 12);

        switch(getch()){
            case 'a':
            case 'A':
                gotoxy(15 + 20*selecao, 10);
                printf("   ");
                selecao--;
                if (selecao < 0)
                    selecao = 0;
                break;
            case 'd':
            case 'D':
                gotoxy(15 + 20*selecao, 10);
                printf("   ");
                selecao++;
                if (selecao > 1)
                    selecao = 1;
                break;
            case '\r':
                selecionando = 0;
                break;
        }

    }

    selecionando = 1;
    switch(selecao){
        case 0:
            *tipoJogadorA = 0;
            *tipoJogadorB = 0;
            return;
        case 1:
            selecao = 0;
            gotoxy(1, 10);
            clreol();
            gotoxy(5, 10);
            printf("   N�vel 1     N�vel 2     N�vel 3     N�vel 4     N�vel 5     N�vel 6");
            while (selecionando){
                gotoxy(5 + 12*selecao, 10);
                printf("-> ");
                gotoxy(1, 12);
                switch(getch()){
                    case 'a':
                    case 'A':
                        gotoxy(5 + 12*selecao, 10);
                        printf("   ");
                        selecao--;
                        if (selecao < 0)
                            selecao = 0;
                        break;
                    case 'd':
                    case 'D':
                        gotoxy(5 + 12*selecao, 10);
                        printf("   ");
                        selecao++;
                        if (selecao > 5)
                            selecao = 5;
                        break;
                    case '\r':
                        selecionando = 0;
                        break;
                }
            }
            selecionando = 1;
            selecao++;
            gotoxy(1, 10);
            clreol();
            gotoxy(15, 10);
            printf("   Jogador 1     Jogador 2");
            while(selecionando){
                gotoxy(15 + 14*jogadorPessoa, 10);
                printf("-> ");
                gotoxy(1, 12);
                switch(getch()){
                    case 'a':
                    case 'A':
                        gotoxy(15 + 14*jogadorPessoa, 10);
                        printf("   ");
                        jogadorPessoa--;
                        if (jogadorPessoa < 0)
                            jogadorPessoa = 0;
                        break;
                    case 'd':
                    case 'D':
                        gotoxy(15 + 14*jogadorPessoa, 10);
                        printf("   ");
                        jogadorPessoa++;
                        if (jogadorPessoa > 1)
                            jogadorPessoa = 1;
                        break;
                    case '\r':
                        selecionando = 0;
                        break;
                }
            }
           // printf("\n\njogador bot: %d", selecao);
            //getch();
            switch(jogadorPessoa){
                case 0:
                    *tipoJogadorA = 0;
                    *tipoJogadorB = selecao;
                    break;
                case 1:
                    *tipoJogadorA = selecao;
                    *tipoJogadorB = 0;
                    break;
            }

    }



}


int main()
{

    int tipoJogadorA, tipoJogadorB;

    setlocale(LC_ALL, "");
    srand(time(NULL));
    _setcursortype(_NORMALCURSOR);

    menuInicial(&tipoJogadorA, &tipoJogadorB);

    clrscr();
    jogarPartida(tipoJogadorA, tipoJogadorB);
    /*
    0 = jogador
    1 = bot n�vel 1 (aleat�rio)
    2 = bot n�vel 2 (+ capturas)
    3 = bot n�vel 3 (minimax prof 1)
    4 = bot n�vel 4 (minimax prof 3)
    5 = bot n�vel 5 (minimax prof 5)
    6 = bot n�vel 6 (minimax prof 7)
    */

    getchar();
    printf("\n\n\n");





    return 0;
}
