#include <stdio.h>

int main() {
    int instancias;
    scanf("%d", &instancias);

    for (int caso = 1; caso <= instancias ; caso++) {
        int matriz[9][9];
        int valido = 1;

        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // linhas
        for (int i = 0 ; i < 9 && valido ; i++) {
            int visto[10] = {0};
            for (int j = 0 ; j < 9 ; j++) {
                int valor = matriz[i][j];
                if (visto[valor]) {
                    valido = 0;
                    break;
                }
                visto[valor] = 1;
            }
        }

        // colunas
        for (int i = 0 ; i < 9 && valido; i++) {
            int visto[10] = {0};
            for (int j = 0; j < 9 ; j++) {
                int valor = matriz[j][i];
                if (visto[valor]) {
                    valido = 0;
                    break;
                }
                visto[valor] = 1;
            }
        }

        // blocos 3x3
        for (int blocoi = 0 ; blocoi < 9 && valido ; blocoi += 3) {
            for (int blocoj = 0 ; blocoj < 9 && valido ; blocoj += 3) {
                int visto[10] = {0};
                for (int i = 0 ; i < 3 ; i++) {
                    for (int j = 0 ; j < 3 ; j++) {
                        int valor = matriz[blocoi + i][blocoj + j];
                        if (visto[valor]) {
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
        else printf("NAO\n\n");
    }
    return 0;
}