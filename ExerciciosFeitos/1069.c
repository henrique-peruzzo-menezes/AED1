#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char items [1000];
    int top;
} Stack;

void initStack (Stack *s) {
    s->top = -1;
}

int isEmpty (Stack *s){
    return s->top == -1;
}

void add(Stack *s, char valor){
    if (s->top < 999){
        s->items[++(s->top)] = valor;
    }
}

char remove (Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

int countDiamond (const char *sequencia){
    Stack s;
    initStack(&s);
    int count = 0;

    for (int i = 0; i< strlen(sequencia); i++) {
        if (sequencia[i] == '<') {
            add(&s, '<');
        }
        else if (sequencia[i] == '>') {
            if (!isEmpty(&s)){
                remove(&s);
                count++;
            }
        }
    }
    return count;
}

int main () {
    int N;
    char sequencia[1001];
    scanf("%d", &N);

    while (N--){
        scanf("%s", sequencia);
        printf("%d\n", countDiamond(sequencia));
    }
    return 0;
}