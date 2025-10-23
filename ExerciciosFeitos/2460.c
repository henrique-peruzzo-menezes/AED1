#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, int id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    
    Node *temp = q->front;
    int id = temp->id;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return id;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF) {
        Queue fila;
        initQueue(&fila);
        
        for (int i = 0; i < N; i++) {
            int id;
            scanf("%d", &id);
            enqueue(&fila, id);
        }
        
        int M;
        scanf("%d", &M);
        
        int *saidas = (int*)malloc(M * sizeof(int));
        for (int i = 0; i < M; i++) {
            scanf("%d", &saidas[i]);
        }
        
        for (int i = 0; i < M; i++) {
            Node *current = fila.front;
            Node *prev = NULL;
            
            while (current != NULL) {
                if (current->id == saidas[i]) {
                    if (prev == NULL) {
                        fila.front = current->next;
                        if (fila.front == NULL) {
                            fila.rear = NULL;
                        }
                    } else {
                        prev->next = current->next;
                        if (current->next == NULL) {
                            fila.rear = prev;
                        }
                    }
                    free(current);
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
        
        int first = 1;
        while (!isEmpty(&fila)) {
            int id = dequeue(&fila);
            if (first) {
                printf("%d", id);
                first = 0;
            } else {
                printf(" %d", id);
            }
        }
        printf("\n");
        
        free(saidas);
        freeQueue(&fila);
    }
    
    return 0;
}