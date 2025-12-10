#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[MAXN + 1];
int cor[MAXN + 1];
int tem_ciclo;

void add_edge(int u, int v) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->next = adj[u];
    adj[u] = novo;
}

void dfs(int u) {
    cor[u] = 1;

    for (Node *p = adj[u]; p != NULL; p = p->next) {
        int v = p->v;

        if (cor[v] == 1) {
            tem_ciclo = 1;
            return;
        } else if (cor[v] == 0) {
            dfs(v);
            if (tem_ciclo) return;
        }
    }

    cor[u] = 2;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N, M;
        if (scanf("%d %d", &N, &M) != 2) return 0;

        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
            cor[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        tem_ciclo = 0;

        for (int i = 1; i <= N && !tem_ciclo; i++) {
            if (cor[i] == 0) {
                dfs(i);
            }
        }

        if (tem_ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        for (int i = 1; i <= N; i++) {
            Node *p = adj[i];
            while (p != NULL) {
                Node *prox = p->next;
                free(p);
                p = prox;
            }
        }
    }

    return 0;
}
