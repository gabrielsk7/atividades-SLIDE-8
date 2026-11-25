#include <stdio.h>

int ehPrimo(int numero) {
    int i;

    if (numero < 2) {
        return 0;
    }

    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numeros[15], frequencia[15], processado[15] = {0};
    char animais[15][50];
    int i, j, soma, quantidade, totalAnimais = 0;

    for (i = 0; i < 15; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nCadastre 15 nomes de animais:\n");
    for (i = 0; i < 15; i++) {
        printf("Animal %d: ", i + 1);
        scanf(" %49[^\n]", animais[i]);
    }

    printf("\nAnimais relacionados aos numeros:\n");

    for (i = 0; i < 15; i++) {
        if (processado[i] == 0) {
            quantidade = 0;
            soma = 0;

            for (j = 0; j < 15; j++) {
                if (numeros[i] == numeros[j]) {
                    quantidade++;
                    soma = soma + numeros[j];
                    processado[j] = 1;
                }
            }

            if (quantidade > 1) {
                printf("\nNumero %d aparece %d vezes.\n", numeros[i], quantidade);

                if (ehPrimo(numeros[i]) == 1 && quantidade % 2 != 0) {
                    printf("Cadastre %d nome(s) de animal:\n", soma);

                    for (j = 0; j < soma && totalAnimais < 15; j++) {
                        printf("Nome do animal: ");
                        scanf(" %49[^\n]", animais[totalAnimais]);
                        printf("Animal cadastrado: %s\n", animais[totalAnimais]);
                        totalAnimais++;
                    }
                } else if (quantidade % 2 == 0) {
                    printf("Animais relacionados pelas posicoes:\n");

                    for (j = 0; j < 15; j++) {
                        if (numeros[j] == numeros[i]) {
                            printf("Posicao %d: %s\n", j + 1, animais[j]);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
