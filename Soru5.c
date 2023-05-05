#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000


struct Queue {
    int front, rear;
    char items[MAX_SIZE];
};


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}


int isEmpty(struct Queue* q) {
    return (q->front == -1);
}


void enqueue(struct Queue* q, char value) {
    if (isFull(q)) {
        printf("Sıra Dolu!\n");
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}


char dequeue(struct Queue* q) {
    char item;
    if (isEmpty(q)) {
        printf("Sıra Boş!\n");
        item = '\0';
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}


void removeDuplicates(struct Queue* q) {
    struct Queue* tempQueue = createQueue();
    int flag = 0;
    
    while (!isEmpty(q)) {
        char current = dequeue(q);
        if (!isEmpty(q) && current == q->items[q->front]) {
            flag = 1;
            dequeue(q);
        }
        else {
            enqueue(tempQueue, current);
        }
    }
    
   
    if (flag) {
        removeDuplicates(tempQueue);
    }
    else {
        while (!isEmpty(tempQueue)) {
            printf("%c", dequeue(tempQueue));
        }
    }
}

int main() {
    struct Queue* q = createQueue();
    char input[MAX_SIZE];

   
    printf("Harf Dizisini Gir: ");
    fgets(input, MAX_SIZE, stdin);

 
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '\n') {
            enqueue(q, input[i]);
        }
    }

   
    removeDuplicates(q);

    return 0;
}