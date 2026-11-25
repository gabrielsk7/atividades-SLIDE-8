#include <stdio.h>
#include <string.h>
#include <math.h>

#define PARTICIPANTES 4
#define MAX_VALORES 50

struct Participante {
    char nome[50];
    int idade;
    long long id;
    float valores[MAX_VALORES];
    int quantidade;
    double media;
    char classificacao[30];
};

long long fatorial(int numero) {
    long long resultado = 1;
    int i;

    for (i = 1; i <= numero; i++) {
        resultado = resultado * i;
    }

    return resultado;
}

int idExiste(struct Participante participantes[], int limite, long long id) {
    int i;

    for (i = 0; i < limite; i++) {
        if (participantes[i].id == id) {
            return 1;
        }
    }

    return 0;
}

double calcularMediaPonderada(float valores[], int quantidade) {
    int i;
    double soma = 0, pesos = 0;

    for (i = 0; i < quantidade; i++) {
        soma = soma + valores[i] * (i + 1);
        pesos = pesos + (i + 1);
    }

    if (pesos == 0) {
        return 0;
    }

    return soma / pesos;
}

int main() {
    struct Participante p[PARTICIPANTES], aux;
    int i, j, tentativa, encontrou = 0;
    int quantidadeValores;
    int ladosEncontrados = 0;
    double lado1 = 0, lado2 = 0, diagonal = 0;
    float valor;

    for (i = 0; i < PARTICIPANTES; i++) {
        printf("\nNome do participante: ");
        scanf(" %49[^\n]", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);

        p[i].id = fatorial(p[i].idade) / 2;

        if (idExiste(p, i, p[i].id)) {
            printf("ID repetido. Calculando um novo ID.\n");
            tentativa = p[i].idade / 2;

            do {
                /* A tentativa aumenta o expoente para evitar repetir o mesmo ID. */
                p[i].id = 1;
                for (j = 0; j < tentativa; j++) {
                    p[i].id = p[i].id * fatorial(p[i].idade / 2);
                }
                tentativa++;
            } while (idExiste(p, i, p[i].id));
        }

        printf("ID: %lld\n", p[i].id);
    }

    printf("\nQuantidade de valores para cada participante (1 a %d): ", MAX_VALORES);
    scanf("%d", &quantidadeValores);

    if (quantidadeValores < 1 || quantidadeValores > MAX_VALORES) {
        printf("Quantidade invalida.\n");
        return 0;
    }

    for (i = 0; i < PARTICIPANTES; i++) {
        p[i].quantidade = quantidadeValores;

        printf("\nValores de %s:\n", p[i].nome);
        for (j = 0; j < quantidadeValores; j++) {
            printf("Digite o valor %d: ", j + 1);
            scanf("%f", &p[i].valores[j]);

            if (p[i].valores[j] >= 0 && ladosEncontrados < 2) {
                if (ladosEncontrados == 0) {
                    lado1 = p[i].valores[j];
                } else {
                    lado2 = p[i].valores[j];
                }
                ladosEncontrados++;
            }
        }

        p[i].media = calcularMediaPonderada(p[i].valores, quantidadeValores);
    }

    /* Ordena os participantes pelo nome, mantendo todos os dados juntos. */
    for (i = 0; i < PARTICIPANTES - 1; i++) {
        for (j = i + 1; j < PARTICIPANTES; j++) {
            if (strcmp(p[i].nome, p[j].nome) > 0) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    if (ladosEncontrados == 2) {
        diagonal = sqrt(lado1 * lado1 + lado2 * lado2);
        encontrou = 1;
    }

    printf("\nParticipantes em ordem alfabetica:\n");
    for (i = 0; i < PARTICIPANTES; i++) {
        if (encontrou == 1) {
            if (p[i].media > diagonal) {
                strcpy(p[i].classificacao, "Acima da diagonal");
            } else if (p[i].media < diagonal) {
                strcpy(p[i].classificacao, "Abaixo da diagonal");
            } else {
                strcpy(p[i].classificacao, "Sobre a diagonal");
            }

            printf("%s - ID: %lld - Media: %.2f - %s\n",
                   p[i].nome, p[i].id, p[i].media, p[i].classificacao);
        } else {
            printf("%s - ID: %lld - Media: %.2f\n",
                   p[i].nome, p[i].id, p[i].media);
        }
    }

    if (encontrou == 1) {
        printf("\nDiagonal do retangulo: %.2f\n", diagonal);
    } else {
        printf("\nNao foi possivel calcular a diagonal.\n");
    }

    return 0;
}
