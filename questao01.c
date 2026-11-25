#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
};

int main() {
    int numeros[12], distintos[12], frequencia[12];
    int pares[12], qtdDistintos = 0, qtdPares = 0;
    struct Produto produtos[144], aux;
    int qtdProdutos = 0;
    int i, j, achou, quantidade;

    for (i = 0; i < 12; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 12; i++) {
        achou = 0;

        for (j = 0; j < qtdDistintos; j++) {
            if (numeros[i] == distintos[j]) {
                frequencia[j]++;
                achou = 1;
                break;
            }
        }

        if (achou == 0) {
            distintos[qtdDistintos] = numeros[i];
            frequencia[qtdDistintos] = 1;
            qtdDistintos++;
        }
    }

    for (i = 0; i < qtdDistintos; i++) {
        if (frequencia[i] % 2 == 0) {
            pares[qtdPares] = distintos[i];
            qtdPares++;
        } else if (distintos[i] > 0) {
            quantidade = distintos[i];

            for (j = 0; j < quantidade; j++) {
                if (qtdProdutos < 144) {
                    printf("Nome do produto %d: ", j + 1);
                    scanf(" %49[^\n]", produtos[qtdProdutos].nome);

                    printf("Preco unitario: ");
                    scanf("%f", &produtos[qtdProdutos].preco);

                    qtdProdutos++;
                }
            }
        }
    }

    /* Organiza os numeros pares em ordem decrescente. */
    for (i = 0; i < qtdPares - 1; i++) {
        for (j = i + 1; j < qtdPares; j++) {
            if (pares[i] < pares[j]) {
                int temp = pares[i];
                pares[i] = pares[j];
                pares[j] = temp;
            }
        }
    }

    /* Organiza os produtos em ordem alfabetica. */
    for (i = 0; i < qtdProdutos - 1; i++) {
        for (j = i + 1; j < qtdProdutos; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                aux = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = aux;
            }
        }
    }

    printf("\nNumeros informados:\n");
    for (i = 0; i < 12; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\nOcorrencias:\n");
    for (i = 0; i < qtdDistintos; i++) {
        printf("%d aparece %d vez(es)\n", distintos[i], frequencia[i]);
    }

    printf("\nProdutos cadastrados:\n");
    for (i = 0; i < qtdProdutos; i++) {
        printf("%s - R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    printf("\nNumeros com quantidade par, em ordem decrescente:\n");
    for (i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }

    printf("\n");
    return 0;
}
