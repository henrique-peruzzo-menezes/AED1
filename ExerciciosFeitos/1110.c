#include <stdio.h>

void simulate_game(int n) {
    int queue[100000], discarded_cards[100000];
    int front = 0, rear = n - 1;
    int discarded_index = 0;

    for (int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }

    while (rear - front > 0) {
        discarded_cards[discarded_index++] = queue[front % n];
        front++;
        queue[(rear + 1) % n] = queue[front % n];
        front++;
        rear++;
    }

    printf("Discarded cards: ");
    if (discarded_index > 0) {
        for (int i = 0; i < discarded_index - 1; i++) {
            printf("%d, ", discarded_cards[i]);
        }
        printf("%d\n", discarded_cards[discarded_index - 1]);
    } else {
        printf("\n");
    }

    printf("Remaining card: %d\n", queue[front % n]);
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        simulate_game(n);
    }
    return 0;
}