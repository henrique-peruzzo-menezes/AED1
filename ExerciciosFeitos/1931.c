#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 11234
#define INF 0x3f3f3f3

typedef struct _node {
    int u, w;
    struct _node *next;
} node_t;

typedef struct _g {
    node_t *adj;
} g_t;

int vis[MAXSIZE];
int dist[MAXSIZE];

g_t *make_graph(int size);
node_t *make_node(int u, int w);
void dijkstra(g_t *g, int s, int size);
void push_back(g_t *g, int u, int v, int w);
void make_aux_graph(g_t *g1, g_t *g2, int size);

int main(void) {

    int u, v, w;
    int n, m;

    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    /* g1: grafo original; g2: grafo auxiliar (somente caminhos com nº par de pedágios) */
    g_t *g1 = make_graph(n + 1);
    g_t *g2 = make_graph(n + 1);

    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        /* estradas são bidirecionais */
        push_back(g1, u, v, w);
        push_back(g1, v, u, w);
    }

    /* monta o grafo auxiliar com caminhos de 2 arestas */
    make_aux_graph(g1, g2, n);

    /* menor caminho de 1 até n no grafo auxiliar */
    dijkstra(g2, 1, n);

    if (dist[n] == INF)
        puts("-1");
    else
        printf("%d\n", dist[n]);

    return 0;
}

g_t *make_graph(int size) {
    g_t *g = (g_t *) malloc(sizeof(g_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (size + 1));
    for (int i = 0; i <= size; ++i)
        g->adj[i].next = NULL;
    return g;
}

node_t *make_node(int u, int w) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->u = u;
    new_node->w = w;
    new_node->next = NULL;
    return new_node;
}

/* adiciona aresta v -> u com peso w */
void push_back(g_t *g, int u, int v, int w) {
    node_t *new_node = make_node(u, w);
    new_node->next = g->adj[v].next;
    g->adj[v].next = new_node;
}

void dijkstra(g_t *g, int s, int size) {
    node_t *k;
    int i, j, v;

    memset(vis, 0, sizeof(vis));

    for (i = 1; i <= size; ++i)
        dist[i] = INF;

    dist[s] = 0;

    for (i = 1; i <= size; ++i) {

        v = -1;
        for (j = 1; j <= size; ++j)
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (v == -1 || dist[v] == INF)
            break;

        vis[v] = 1;

        for (k = g->adj[v].next; k != NULL; k = k->next) {
            int to  = k->u;
            int len = k->w;
            if (dist[v] + len < dist[to])
                dist[to] = dist[v] + len;
        }
    }
}

/* g2 recebe arestas que representam 2 estradas consecutivas em g1:
   i -> u -> v vira uma aresta i -> v com peso w(i,u) + w(u,v) */
void make_aux_graph(g_t *g1, g_t *g2, int size) {
    int i;
    node_t *j, *k;

    for (i = 1; i <= size; ++i) {
        for (j = g1->adj[i].next; j != NULL; j = j->next) {
            int u = j->u;
            int w = j->w;

            for (k = g1->adj[u].next; k != NULL; k = k->next) {
                int v  = k->u;
                int w2 = k->w;
                push_back(g2, i, v, w + w2);
            }
        }
    }
}
