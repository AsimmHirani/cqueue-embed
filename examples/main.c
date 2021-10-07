//
// Created by Asimm on 2021-10-06.
//
#define MSSERT
#define CQUEUE_DESKTOP

#include "cqueue-embed.h"

#define QUEUE_LEN (50)

typedef struct queue_elem {
    int id, class;
    char data[8];
} queue_elem;

queue_elem buffer[QUEUE_LEN];
queue_elem t;

int main() {
    CQUEUE_EMBED_Queue queue = CQUEUE_newQueue(QUEUE_LEN,sizeof(queue_elem),buffer);
    for (int i = 0; i < QUEUE_LEN; i++) {
        t.id = t.class = i;
        for(int j = 0; j < 8; j++) {
            t.data[j] = i+j+rand();
        }
        CQUEUE_enqueue(&queue,&t,sizeof(t));
    }

    return 0;
}

