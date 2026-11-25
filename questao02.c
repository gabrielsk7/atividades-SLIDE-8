#include <stdio.h>

int main() {
    int numeros[10], positivosPares[10], negativosImpares[10];
    int qtdPositivos = 0, qtdNegativos = 0;
    int i, j, temp;

    for (i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);

        if (numeros[i] > 0 && numeros[i] % 2 == 0) {
            positivosPares[qtdPositivos] = numeros[i];
            qtdPositivos++;
        }

        if (numeros[i] < 0 && numeros[i] % 2 != 0) {
            negativosImpares[qtdNegativos] = numeros[i];
            qtdNegativos++;
        }
    }

    for (i = 0; i < qtdPositivos - 1; i++) {
        for (j = i + 1; j < qtdPositivos; j++) {
            if (positivosPares[i] > positivosPares[j]) {
                temp = positivosPares[i];
                positivosPares[i] = positivosPares[j];
                positivosPares[j] = temp;
            }
        }
    }

    for (i = 0; i < qtdNegativos - 1; i++) {
        for (j = i + 1; j < qtdNegativos; j++) {
            if (negativosImpares[i] > negativosImpares[j]) {
                temp = negativosImpares[i];
                negativosImpares[i] = negativosImpares[j];
                negativosImpares[j] = temp;
            }
        }
    }

    printf("\nPositivos e pares:\n");
    for (i = 0; i < qtdPositivos; i++) {
        printf("%d ", positivosPares[i]);
    }

    printf("\nNegativos e impares:\n");
    for (i = 0; i < qtdNegativos; i++) {
        printf("%d ", negativosImpares[i]);
    }

    printf("\n");
    return 0;
}
