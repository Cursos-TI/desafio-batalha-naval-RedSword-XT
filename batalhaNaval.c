#include <stdio.h>


// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal


#define TAM 10 // Define o tamanho do tabuleiro (10x10)
#define NAVIO 3 // Valor usado para representar um navio na matriz
#define TAMANHO_NAVIO 3 // Tamanho fixo de cada navio (3 posições)


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
        // Verifica se está dentro do tabuleiro
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0;

        // Verifica se a posição já está ocupada
        if (tabuleiro[linha[i]][coluna[i]] != 0)
            return 0;
    }
    return 1;  // Tudo ok para posicionar o navio
}

// Marca as posições do navio na matriz do tabuleiro
void posicionar_navio(int linha[], int coluna[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Exibe o tabuleiro no console com os valores de cada posição
void exibir_tabuleiro() {
    printf("\n === TABULEIRO ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime cada célula
        }
        printf("\n");  // Nova linha a cada linha do tabuleiro
    }
}

int main() {
    // Inicializa todo o tabuleiro com 0 (água)
    inicializar_tabuleiro();

    // === POSICIONA NAVIO HORIZONTAL ===
    int l1 = 1, c1 = 2;  // Posição inicial (linha, coluna)
    int linhas_h[] = {l1, l1, l1};              // Linha constante (horizontal)
    int colunas_h[] = {c1, c1 + 1, c1 + 2};     // Colunas crescentes

    if (pode_colocar(linhas_h, colunas_h)) {
        posicionar_navio(linhas_h, colunas_h);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // === POSICIONA NAVIO VERTICAL ===
    int l2 = 5, c2 = 6;  // Posição inicial
    int linhas_v[] = {l2, l2 + 1, l2 + 2};      // Linhas crescentes
    int colunas_v[] = {c2, c2, c2};             // Coluna constante (vertical)

    if (pode_colocar(linhas_v, colunas_v)) {
        posicionar_navio(linhas_v, colunas_v);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // === POSICIONA NAVIO DIAGONAL 1 ===
    int l3 = 0, c3 = 0;  // Posição inicial
    int linhas_d1[] = {l3, l3 + 1, l3 + 2};     // Linhas crescentes
    int colunas_d1[] = {c3, c3 + 1, c3 + 2};    // Colunas crescentes

    if (pode_colocar(linhas_d1, colunas_d1)) {
        posicionar_navio(linhas_d1, colunas_d1);
    } else {
        printf("Erro ao posicionar navio diagonal ↘.\n");
    }

    // === POSICIONA NAVIO DIAGONAL 2 ===
    int l4 = 0, c4 = 9;  // Posição inicial
    int linhas_d2[] = {l4, l4 + 1, l4 + 2};     // Linhas crescentes
    int colunas_d2[] = {c4, c4 - 1, c4 - 2};    // Colunas decrescentes

    if (pode_colocar(linhas_d2, colunas_d2)) {
        posicionar_navio(linhas_d2, colunas_d2);
    } else {
        printf("Erro ao posicionar navio diagonal ↙.\n");
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibir_tabuleiro();

    return 0;
}