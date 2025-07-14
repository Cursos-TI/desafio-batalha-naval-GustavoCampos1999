    #include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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

void imprimir_tabuleiro(int tabuleiro[10][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("%d ", tabuleiro[x][y]);}
        printf("\n");
    }
}

int main() {
int agua = 0;
int navio = 3;
int area_habilidade = 5;

int navio_tamanho = 3;
int navio1_x = 2;
int navio1_y = 2;
int navio2_x = 5;
int navio2_y = 5;
int navio3_x = 6; 
int navio3_y = 0;
int navio4_x = 4;
int navio4_y = 7;

int tabuleiro[10][10] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
//navio 1
printf("Posição navio 1:\n");
for (int i = 0; i < navio_tamanho; i++) {
tabuleiro[navio1_x][navio1_y + i] = navio;
printf("Parte %d em: x %d, y %d\n", i + 1, navio1_x, navio1_y + i);
}

//navio 2
printf("Posição navio 2:\n");
for (int i = 0; i < navio_tamanho; i++) {
tabuleiro[navio2_x + i][navio2_y] = navio;
printf("Parte %d em: x %d, y %d\n", i + 1, navio2_x, navio2_y + i);
} 

//navio 3
printf("Posição navio 3:\n");
for (int i = 0; i < navio_tamanho; i++) {
tabuleiro[navio3_x + i][navio3_y + i] = navio;
printf("Parte %d em: x %d, y %d\n", i + 1, navio3_x + i, navio3_y + i);
} 

//navio 4
printf("Posição navio 4:\n");
for (int i = 0; i < navio_tamanho; i++) {
tabuleiro[navio4_x + i][navio4_y + i] = navio;
printf("Parte %d em: x %d, y %d\n", i + 1, navio4_x + i, navio4_y + i);
} 


printf("Tabuleiro (0 = Água / 3 = Navio)\n");
imprimir_tabuleiro(tabuleiro);

//Habilidades
printf("--- HABILIDADES (Área afetada = 5) ---\n");
int tabuleiro_temp[10][10];
int molde_tamanho = 5; 
int centro_molde = molde_tamanho / 2;

printf("Habilidade: Cruz\n");
int matriz_cruz[molde_tamanho][molde_tamanho];
    
for (int i = 0; i < molde_tamanho; i++) for (int j = 0; j < molde_tamanho; j++) matriz_cruz[i][j] = 0;
for (int i = 0; i < molde_tamanho; i++){
        matriz_cruz[centro_molde][i] = 1;
        matriz_cruz[i][centro_molde] = 1;
    }
    
int cruz_origem_x = 4, cruz_origem_y = 4;
for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) tabuleiro_temp[i][j] = tabuleiro[i][j];
for (int i = 0; i < molde_tamanho; i++) {
    for (int j = 0; j < molde_tamanho; j++) {
        if (matriz_cruz[i][j] == 1) {
            int alvo_x = cruz_origem_x + (i - centro_molde);
            int alvo_y = cruz_origem_y + (j - centro_molde);
            if (alvo_x >= 0 && alvo_x < 10 && alvo_y >= 0 && alvo_y < 10) {
                    tabuleiro_temp[alvo_x][alvo_y] = area_habilidade;
                }
            }
        }
    }
    imprimir_tabuleiro(tabuleiro_temp);

    printf("Habilidade: Cone\n");
    int matriz_cone[molde_tamanho][molde_tamanho];
    for (int i = 0; i < molde_tamanho; i++) for (int j = 0; j < molde_tamanho; j++) matriz_cone[i][j] = 0;
    int ponta_cone_y = centro_molde;
    for (int i = 0; i < 3; i++){
        for (int j = -i; j <= i; j++){
             if (ponta_cone_y + j >= 0 && ponta_cone_y + j < molde_tamanho)
                matriz_cone[i][ponta_cone_y + j] = 1;
        }
    }
    
    int cone_origem_x = 1, cone_origem_y = 4;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) tabuleiro_temp[i][j] = tabuleiro[i][j];
    for (int i = 0; i < molde_tamanho; i++) {
        for (int j = 0; j < molde_tamanho; j++) {
            if (matriz_cone[i][j] == 1) {
                int alvo_x = cone_origem_x + i;
                int alvo_y = cone_origem_y + (j - ponta_cone_y);
                if (alvo_x >= 0 && alvo_x < 10 && alvo_y >= 0 && alvo_y < 10) {
                    tabuleiro_temp[alvo_x][alvo_y] = area_habilidade;
                }
            }
        }
    }
    imprimir_tabuleiro(tabuleiro_temp);

    printf("Habilidade: Octaedro\n");
    int matriz_octaedro[molde_tamanho][molde_tamanho];
    for (int i = 0; i < molde_tamanho; i++) for (int j = 0; j < molde_tamanho; j++) matriz_octaedro[i][j] = 0; 

    int raio_octaedro = centro_molde;
    for (int i = 0; i < molde_tamanho; i++){
        for (int j = 0; j < molde_tamanho; j++){
            int dist_i = i - centro_molde;
            if (dist_i < 0) { dist_i = dist_i * -1; }
            int dist_j = j - centro_molde;
            if (dist_j < 0) { dist_j = dist_j * -1; }
            
            if(dist_i + dist_j <= raio_octaedro){
                matriz_octaedro[i][j] = 1;
            }
        }
    }
    
    int octaedro_origem_x = 6, octaedro_origem_y = 5;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) tabuleiro_temp[i][j] = tabuleiro[i][j];
    for (int i = 0; i < molde_tamanho; i++) {
        for (int j = 0; j < molde_tamanho; j++) {
            if (matriz_octaedro[i][j] == 1) {
                int alvo_x = octaedro_origem_x + (i - centro_molde);
                int alvo_y = octaedro_origem_y + (j - centro_molde);
                if (alvo_x >= 0 && alvo_x < 10 && alvo_y >= 0 && alvo_y < 10) {
                    tabuleiro_temp[alvo_x][alvo_y] = area_habilidade;
                }
            }
        }
    }
    imprimir_tabuleiro(tabuleiro_temp);

    return 0;
}
