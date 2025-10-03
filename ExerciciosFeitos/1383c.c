#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int instancias;
    if (scanf("%d", &instancias) != 1) return 0;

    for (int caso = 1; caso <= instancias; caso++) {
        /* Aloca um bloco contíguo para 9x9 e um vetor de 9 ponteiros para as linhas */
        int *data = (int *)malloc(9 * 9 * sizeof(int));
        if (!data) return 0;

        int **matriz = (int **)malloc(9 * sizeof(int *));
        if (!matriz) { free(data); return 0; }

        for (int i = 0; i < 9; i++) {
            matriz[i] = data + i * 9; /* aponta cada linha para o trecho correto */
        }

        /* Leitura */
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int valido = 1;

        /* Verifica linhas */
        for (int i = 0; i < 9 && valido; i++) {
            int visto[10] = {0};
            for (int j = 0; j < 9; j++) {
                int valor = matriz[i][j];
                if (valor < 1 || valor > 9 || visto[valor]) { /* checagem de faixa + repetição */
                    valido = 0;
                    break;
                }
                visto[valor] = 1;
            }
        }

        /* Verifica colunas */
        for (int j = 0; j < 9 && valido; j++) {
            int visto[10] = {0};
            for (int i = 0; i < 9; i++) {
                int valor = matriz[i][j];
                if (valor < 1 || valor > 9 || visto[valor]) {
                    valido = 0;
                    break;
                }
                visto[valor] = 1;
            }
        }

        /* Verifica blocos 3x3 */
        for (int bi = 0; bi < 9 && valido; bi += 3) {
            for (int bj = 0; bj < 9 && valido; bj += 3) {
                int visto[10] = {0};
                for (int i = 0; i < 3 && valido; i++) {
                    for (int j = 0; j < 3; j++) {
                        int valor = matriz[bi + i][bj + j];
                        if (valor < 1 || valor > 9 || visto[valor]) {
                            valido = 0;
                            break;
                        }
                        visto[valor] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", caso);
        if (valido) printf("SIM\n\n");
        else        printf("NAO\n\n");

        /* Libera a memória da matriz desta instância */
        free(matriz);
        free(data);
    }

    return 0;
}
