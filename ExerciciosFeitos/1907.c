#include <stdio.h>

#define MAXN 1024
#define MAXM 1024
#define MAXQ (MAXN * MAXM)

static char grid[MAXN][MAXM + 1];
static int visited[MAXN][MAXM];
static int qx[MAXQ];
static int qy[MAXQ];

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int dx[4] = { 1, -1,  0,  0 };
    int dy[4] = { 0,  0,  1, -1 };

    int componentes = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {
                componentes++;

                int head = 0, tail = 0;
                visited[i][j] = 1;
                qx[tail] = i;
                qy[tail] = j;
                tail++;

                while (head < tail) {
                    int x = qx[head];
                    int y = qy[head];
                    head++;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (grid[nx][ny] == '.' && !visited[nx][ny]) {
                                visited[nx][ny] = 1;
                                qx[tail] = nx;
                                qy[tail] = ny;
                                tail++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", componentes);
    return 0;
}
