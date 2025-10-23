#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

int canReorganize(int *entrada, int *saida, int n) {
    Stack estacao;
    initStack(&estacao);
    
    int entradaIdx = 0;
    int saidaIdx = 0;
    
    while (saidaIdx < n) {
        if (!isEmpty(&estacao) && peek(&estacao) == saida[saidaIdx]) {
            pop(&estacao);
            saidaIdx++;
        }
        else if (entradaIdx < n) {
            push(&estacao, entrada[entradaIdx]);
            entradaIdx++;
        }
        else {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        while (1) {
            int saida[MAX];
            scanf("%d", &saida[0]);
            
            if (saida[0] == 0) {
                printf("\n");
                break;
            }
            
            for (int i = 1; i < n; i++) {
                scanf("%d", &saida[i]);
            }
            
            int entrada[MAX];
            for (int i = 0; i < n; i++) {
                entrada[i] = i + 1;
            }
            
            if (canReorganize(entrada, saida, n)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}