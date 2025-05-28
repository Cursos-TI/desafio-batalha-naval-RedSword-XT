#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() { 

        // Nível Novato - Posicionamento dos Navios

    int tabuleiro[10][10]; // Tabuleiro de batalha naval
    int navio_horizontal[3] = {3, 3, 3}; // Representa um navio de 3 partes na horizontal
    int navio_vertical[3] = {3, 3, 3}; // Representa um navio de 3 partes na vertical

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Verifica se cabe no tabuleiro
    if (coluna_h + 3 <= 10) {
        // Verifica sobreposição
        int pode_colocar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        // Posiciona
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: sobreposição ao posicionar navio horizontal.\n");
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
    }

    // Coordenadas do navio vertical
    int linha_v = 5;
    int coluna_v = 7;

    // Verifica se cabe no tabuleiro
    if (linha_v + 3 <= 10) {
        // Verifica sobreposição
        int pode_colocar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        // Posiciona
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        } else {
            printf("Erro: sobreposição ao posicionar navio vertical.\n");
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro.\n");
    }

    // Exibe o tabuleiro
    printf("\n== BATALHA NAVAL ==\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

