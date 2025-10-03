#include <stdio.h>
#include <string.h>

typedef struct {
    char items[1000];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }

int isEmpty(const Stack *s) { return s->top == -1; }

void push(Stack *s, char valor) {
    if (s->top < 999) {
        s->items[++(s->top)] = valor;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

int countDiamond(const char *sequencia) {
    Stack s;
    initStack(&s);
    int count = 0;

    size_t len = strlen(sequencia);
    for (size_t i = 0; i < len; i++) {
        if (sequencia[i] == '<') {
            push(&s, '<');
        } else if (sequencia[i] == '>') {
            if (!isEmpty(&s)) {
                pop(&s);
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int N;
    char sequencia[1001];
    if (scanf("%d", &N) != 1) return 0;

    while (N--) {
        scanf("%1000s", sequencia);
        printf("%d\n", countDiamond(sequencia));
    }
    return 0;
}
