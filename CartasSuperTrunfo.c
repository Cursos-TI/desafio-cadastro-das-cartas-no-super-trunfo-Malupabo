#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCartas(Carta cartas[NUM_ESTADOS][NUM_CIDADES]) {
    char estados[] = "ABCDEFGH";
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            snprintf(cartas[i][j].codigo, sizeof(cartas[i][j].codigo), "%c%02d", estados[i], j + 1);
            printf("Cadastro da cidade %s:\n", cartas[i][j].codigo);
            printf("Digite a população: ");
            scanf("%d", &cartas[i][j].populacao);
            printf("Digite a área (em km²): ");
            scanf("%f", &cartas[i][j].area);
            printf("Digite o PIB (em bilhões): ");
            scanf("%f", &cartas[i][j].pib);
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);
            printf("\n");
        }
    }
}

void exibirCartas(Carta cartas[NUM_ESTADOS][NUM_CIDADES]) {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            Carta carta = cartas[i][j];
            printf("Código: %s\n", carta.codigo);
            printf("População: %d\n", carta.populacao);
            printf("Área: %.2f km²\n", carta.area);
            printf("PIB: %.2f bilhões\n", carta.pib);
            printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
            printf("---------------------------\n");
        }
    }
}

int main() {
    Carta cartas[NUM_ESTADOS][NUM_CIDADES];

    printf("Bem-vindo ao Sistema de Cadastro de Cartas - Super Trunfo (Tema: Países)\n");
    cadastrarCartas(cartas);
    exibirCartas(cartas);
    
    return 0;
}
