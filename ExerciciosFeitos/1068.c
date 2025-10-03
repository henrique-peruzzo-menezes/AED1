#include <stdio.h>
#include <string.h>

#define MAX 1001

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, char value) {
    if (q->rear == MAX - 1) {
        return;
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

char dequeue(Queue *q) {
    char item;
    if (isEmpty(q)) {
        return '\0';
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

const char* verifica_parenteses(const char* expressao) {
    Queue q;
    initQueue(&q);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            enqueue(&q, '(');
        } else if (expressao[i] == ')') {
            if (isEmpty(&q)) {
                return "incorrect";
            }
            dequeue(&q);
        }
    }
    
    return isEmpty(&q) ? "correct" : "incorrect";
}

int main() {
    char expressao[1001];

    while (fgets(expressao, 1001, stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0';
        printf("%s\n", verifica_parenteses(expressao));
    }

    return 0;
}