#include <stdio.h>

struct Apostador {
    char nome[50];
    int numero;
    long long resultado;
    int premiado;
};

long long somarFibonacci(int quantidade) {
    int i;
    long long a = 0, b = 1, proximo, soma = 0;

    for (i = 0; i < quantidade; i++) {
        soma = soma + a;
        proximo = a + b;
        a = b;
        b = proximo;
    }

    return soma;
}

int ehPrimo(long long numero) {
    long long i;

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
    struct Apostador apostadores[5];
    int i, primeiro = -1, segundo = -1, terceiro = -1;
    long long soma = 0;
    double media;

    for (i = 0; i < 5; i++) {
        apostadores[i].premiado = 0;

        printf("Nome do apostador: ");
        scanf(" %49[^\n]", apostadores[i].nome);

        do {
            printf("Digite um numero inteiro positivo: ");
            scanf("%d", &apostadores[i].numero);
        } while (apostadores[i].numero <= 0);

        apostadores[i].resultado = somarFibonacci(apostadores[i].numero);
        soma = soma + apostadores[i].resultado;
    }

    media = soma / 5.0;

    /* Primeiro lugar: maior resultado primo. */
    for (i = 0; i < 5; i++) {
        if (ehPrimo(apostadores[i].resultado) == 1) {
            if (primeiro == -1 ||
                apostadores[i].resultado > apostadores[primeiro].resultado) {
                primeiro = i;
            }
        }
    }

    if (primeiro != -1) {
        apostadores[primeiro].premiado = 1;
    }

    /* Segundo lugar: maior resultado par entre os restantes. */
    for (i = 0; i < 5; i++) {
        if (apostadores[i].premiado == 0 &&
            apostadores[i].resultado % 2 == 0) {
            if (segundo == -1 ||
                apostadores[i].resultado > apostadores[segundo].resultado) {
                segundo = i;
            }
        }
    }

    if (segundo != -1) {
        apostadores[segundo].premiado = 1;
    }

    /* Terceiro lugar: maior resultado acima da media. */
    for (i = 0; i < 5; i++) {
        if (apostadores[i].premiado == 0 &&
            apostadores[i].resultado > media) {
            if (terceiro == -1 ||
                apostadores[i].resultado > apostadores[terceiro].resultado) {
                terceiro = i;
            }
        }
    }

    printf("\nVencedores:\n");
    if (primeiro != -1) {
        printf("1º lugar: %s\n", apostadores[primeiro].nome);
    } else {
        printf("1º lugar: Sem vencedor\n");
    }

    if (segundo != -1) {
        printf("2º lugar: %s\n", apostadores[segundo].nome);
    } else {
        printf("2º lugar: Sem vencedor\n");
    }

    if (terceiro != -1) {
        printf("3º lugar: %s\n", apostadores[terceiro].nome);
    } else {
        printf("3º lugar: Sem vencedor\n");
    }

    return 0;
}
