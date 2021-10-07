#ifndef CQUEUE_EMBED_CQUEUE_EMBED_H
#define CQUEUE_EMBED_CQUEUE_EMBED_H

#define MSSERT
#define CQUEUE_DESKTOP
#include "cqueue-target.h"
#include "../mssert/mssert.h"

typedef struct CQUEUE_Queue {
    unsigned int maxLen;
    unsigned int itemSize;
    unsigned int head, n;
    void * buffer;
} CQUEUE_EMBED_Queue;

CQUEUE_EMBED_Queue  CQUEUE_newQueue     (unsigned int maxLen, unsigned int itemSize, void * buffer);
unsigned int        CQUEUE_enqueue      (CQUEUE_EMBED_Queue * queue, void * item, unsigned int len);
int                 CQUEUE_dequeue      (CQUEUE_EMBED_Queue * queue, void * buf, unsigned int len);
int                 CQUEUE_isEmpty      (CQUEUE_EMBED_Queue * queue);
int                 CQUEUE_isFull       (CQUEUE_EMBED_Queue * queue);

#endif //CQUEUE_EMBED_CQUEUE_EMBED_H
