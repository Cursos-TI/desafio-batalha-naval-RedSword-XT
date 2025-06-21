#include <stdio.h>
#include <stdlib.h>

#define TAM 10 // Define o tamanho do tabuleiro (10x10)
#define NAVIO 3 // Valor usado para representar um navio na matriz
#define HABILIDADE 5 // Valor usado para representar uma habilidade na matriz
#define TAMANHO_NAVIO 3 // Tamanho do navio a ser posicionado (3 células)
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)

int tabuleiro[TAM][TAM]; // Matriz que representa o tabuleiro de batalha naval

// Função que inicializa o tabuleiro com 0 (água)
void inicializar_tabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Verifica se as coordenadas fornecidas estão dentro dos limites
// e se as posições estão livres (sem outro navio)
int pode_colocar(int linha[], int coluna[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0;
        if (tabuleiro[linha[i]][coluna[i]] != 0)
            return 0;
    }
    return 1;
}

// Marca as posições do navio na matriz do tabuleiro
void posicionar_navio(int linha[], int coluna[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// ====== NOVAS FUNÇÕES PARA HABILIDADES ====== //

// Cria a matriz Cone
void criar_cone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 0) {
                matriz[i][j] = (j == TAM_HABILIDADE / 2) ? 1 : 0;
            } else if (i == 1) {
                matriz[i][j] = (j >= TAM_HABILIDADE / 2 - 1 && j <= TAM_HABILIDADE / 2 + 1) ? 1 : 0;
            } else if (i == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0; // linhas 3 e 4 são 0 (não usadas neste exemplo)
            }
        }
    }
}

// Cria a matriz Cruz
void criar_cruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2) {
                // Linha do meio cheia de 1
                matriz[i][j] = 1;
            } else if (i == TAM_HABILIDADE / 2 - 1 || i == TAM_HABILIDADE / 2 + 1) {
                // Linhas acima e abaixo: só o elemento central (coluna do meio) é 1
                matriz[i][j] = (j == TAM_HABILIDADE / 2) ? 1 : 0;
            } else {
                // Outras linhas 0
                matriz[i][j] = 0;
            }
        }
    }
}

// Cria a matriz Octaedro (losango)
void criar_octaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if ((i == 0 || i == 2) && j == TAM_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else if (i == 1 && (j == TAM_HABILIDADE / 2 - 1 || j == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2 + 1)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro, com ponto de origem
void aplicar_habilidade(int origem_linha, int origem_coluna, int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = origem_linha - TAM_HABILIDADE / 2 + i;
            int col = origem_coluna - TAM_HABILIDADE / 2 + j;
            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[lin][col] == 0) {
                    tabuleiro[lin][col] = HABILIDADE;
                }
            }
        }
    }
}



// Exibe o tabuleiro no console com os valores de cada posição
void exibir_tabuleiro() {
    printf("\n === TABULEIRO ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 "); // 0 representa água
            else if (tabuleiro[i][j] == NAVIO)
                printf("3 "); // 3 representa um navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 "); // 5 representa uma habilidade
        }
        printf("\n");
    }
}

int main() {
    // Inicializa todo o tabuleiro com 0 (água)
    inicializar_tabuleiro();

    // === POSICIONA NAVIO HORIZONTAL ===
    int l1 = 1, c1 = 1;  // Posição inicial (linha, coluna)
    int linhas_h[] = {l1, l1, l1};              // Linha constante (horizontal)
    int colunas_h[] = {c1, c1 + 1, c1 + 2};     // Colunas crescentes

    if (pode_colocar(linhas_h, colunas_h)) {
        posicionar_navio(linhas_h, colunas_h);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // === POSICIONA NAVIO VERTICAL ===
    int l2 = 5, c2 = 7;  // Posição inicial
    int linhas_v[] = {l2, l2 + 1, l2 + 2};      // Linhas crescentes
    int colunas_v[] = {c2, c2, c2};             // Coluna constante (vertical)

    if (pode_colocar(linhas_v, colunas_v)) {
        posicionar_navio(linhas_v, colunas_v);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // === POSICIONA NAVIO DIAGONAL 1 ===
    int l3 = 3, c3 = 3;  // Posição inicial
    int linhas_d1[] = {l3, l3 + 1, l3 + 2};     // Linhas crescentes
    int colunas_d1[] = {c3, c3 + 1, c3 + 2};    // Colunas crescentes

    if (pode_colocar(linhas_d1, colunas_d1)) {
        posicionar_navio(linhas_d1, colunas_d1);
    } else {
        printf("Erro ao posicionar navio diagonal ↘.\n");
    }

    // === POSICIONA NAVIO DIAGONAL 2 ===
    int l4 = 3, c4 = 8;  // Posição inicial
    int linhas_d2[] = {l4, l4 + 1, l4 + 2};     // Linhas crescentes
    int colunas_d2[] = {c4, c4 - 1, c4 - 2};    // Colunas decrescentes

    if (pode_colocar(linhas_d2, colunas_d2)) {
        posicionar_navio(linhas_d2, colunas_d2);
    } else {
        printf("Erro ao posicionar navio diagonal ↙.\n");
    }

// === CRIA MATRIZES DE HABILIDADE ===
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criar_cone(cone);         // Cria a matriz cone
    criar_cruz(cruz);         // Cria a matriz cruz
    criar_octaedro(octaedro); // Cria a matriz octaedro

    // === APLICA AS HABILIDADES EM POSIÇÕES FIXAS ===
    aplicar_habilidade(2, 7, cone);       // Aplica cone em (2,7)
    aplicar_habilidade(6, 4, cruz);       // Aplica cruz em (6,4)
    aplicar_habilidade(8, 2, octaedro);   // Aplica octaedro em (8,2)

    // Exibe o tabuleiro final com os navios posicionados
    exibir_tabuleiro();

    return 0;
}