#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao auxiliar para ler string e remover \n
void lerString(char *dest, int tamanho) {
    fgets(dest, tamanho, stdin);
    dest[strcspn(dest, "\n")] = 0; // Remove \n
}

// Funcao auxiliar para ler numero inteiro
int lerInteiro() {
    char buffer[50];
    lerString(buffer, sizeof(buffer));
    int valor;
    if (sscanf(buffer, "%d", &valor) == 1) {
        return valor;
    } else {
        printf("Valor invalido, usando 0.\n");
        return 0;
    }
}

// Funcao auxiliar para ler float
float lerFloat() {
    char buffer[50];
    lerString(buffer, sizeof(buffer));
    float valor;
    if (sscanf(buffer, "%f", &valor) == 1) {
        return valor;
    } else {
        printf("Valor invalido, usando 0.0.\n");
        return 0.0;
    }
}

int main() {
    // -------- Carta 1 --------
    char estado1[50];
    char codigo1[10];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // -------- Carta 2 --------
    char estado2[50];
    char codigo2[10];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Digite o Estado (A-H):\n");
    lerString(estado1, sizeof(estado1));

    printf("Digite o Codigo da Carta (ex: A01):\n");
    lerString(codigo1, sizeof(codigo1));

    printf("Digite o Nome da Cidade:\n");
    lerString(nomeCidade1, sizeof(nomeCidade1));

    printf("Digite a Populacao:\n");
    populacao1 = lerInteiro();

    printf("Digite a Area em km2:\n");
    area1 = lerFloat();

    printf("Digite o PIB em bilhoes de reais:\n");
    pib1 = lerFloat();

    printf("Digite o Numero de Pontos Turisticos:\n");
    pontosTuristicos1 = lerInteiro();

    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Digite o Estado (A-H):\n");
    lerString(estado2, sizeof(estado2));

    printf("Digite o Codigo da Carta (ex: B02):\n");
    lerString(codigo2, sizeof(codigo2));

    printf("Digite o Nome da Cidade:\n");
    lerString(nomeCidade2, sizeof(nomeCidade2));

    printf("Digite a Populacao:\n");
    populacao2 = lerInteiro();

    printf("Digite a Area em km2:\n");
    area2 = lerFloat();

    printf("Digite o PIB em bilhoes de reais:\n");
    pib2 = lerFloat();

    printf("Digite o Numero de Pontos Turisticos:\n");
    pontosTuristicos2 = lerInteiro();

    // Exibicao dos dados
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);

    // Sistema de pontuacao (Super Trunfo)
    printf("\n=== Resultado do Jogo Super Trunfo ===\n");
    int pontuacao1 = 0, pontuacao2 = 0;

    if (populacao1 > populacao2) pontuacao1++;
    else if (populacao2 > populacao1) pontuacao2++;

    if (area1 > area2) pontuacao1++;
    else if (area2 > area1) pontuacao2++;

    if (pib1 > pib2) pontuacao1++;
    else if (pib2 > pib1) pontuacao2++;

    if (pontosTuristicos1 > pontosTuristicos2) pontuacao1++;
    else if (pontosTuristicos2 > pontosTuristicos1) pontuacao2++;

    printf("Carta 1: %d ponto(s)\n", pontuacao1);
    printf("Carta 2: %d ponto(s)\n", pontuacao2);

    if (pontuacao1 > pontuacao2)
        printf("Vencedor: Carta 1 (%s)\n", nomeCidade1);
    else if (pontuacao2 > pontuacao1)
        printf("Vencedor: Carta 2 (%s)\n", nomeCidade2);
    else
        printf("Empate!\n");

    return 0;
}

