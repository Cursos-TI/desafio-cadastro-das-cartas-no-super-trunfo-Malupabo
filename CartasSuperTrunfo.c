#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];
    long long populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
    double super_poder;
} Carta;

Carta cadastrarCarta() {
    Carta c;
    printf("\nCódigo da cidade (ex: A01, B02): ");
    scanf("%s", c.codigo);
    printf("População: ");
    scanf("%lld", &c.populacao);
    printf("Área (km²): ");
    scanf("%lf", &c.area);
    printf("PIB: ");
    scanf("%lf", &c.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    // Cálculo das propriedades
    c.densidade_populacional = c.populacao / c.area;
    c.pib_per_capita = c.pib / c.populacao;
    c.super_poder = c.populacao + c.area + c.pib + c.pontos_turisticos;
    
    return c;
}

void exibirCarta(Carta c) {
    printf("\nCódigo: %s\n", c.codigo);
    printf("População: %lld\n", c.populacao);
    printf("Área: %.2lf km²\n", c.area);
    printf("PIB: %.2lf\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c.densidade_populacional);
    printf("PIB per Capita: %.2lf\n", c.pib_per_capita);
    printf("Super Poder: %.2lf\n", c.super_poder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação entre %s e %s:\n", c1.codigo, c2.codigo);
    printf("Densidade Populacional: %s vence\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("População: %s vence\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Área: %s vence\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: %s vence\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("Pontos turísticos: %s vence\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("Super Poder: %s vence\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
}

int main() {
    Carta c1, c2;
    int opcao, cartas_cadastradas = 0;

    do {
        printf("\n1 - Cadastrar carta\n2 - Exibir carta cadastrada\n3 - Comparar duas cartas\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (cartas_cadastradas == 0) {
                c1 = cadastrarCarta();
                cartas_cadastradas = 1;
            } else {
                c2 = cadastrarCarta();
                cartas_cadastradas = 2;
            }
        } else if (opcao == 2) {
            if (cartas_cadastradas == 0) {
                printf("Nenhuma carta cadastrada!\n");
            } else {
                exibirCarta(c1);
                if (cartas_cadastradas == 2) exibirCarta(c2);
            }
        } else if (opcao == 3) {
            if (cartas_cadastradas < 2) {
                printf("Cadastre duas cartas primeiro!\n");
            } else {
                compararCartas(c1, c2);
            }
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
 
