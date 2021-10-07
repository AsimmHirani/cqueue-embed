#include "cqueue-embed.h"

#define MSSERT
#define CQUEUE_DESKTOP
#include "cqueue-target.h"
#include "../mssert/mssert.h"

static int CQUEUE_memcpy(void* dest, const void * src, unsigned int len) {
    char* d = (char*)dest;
    char* s = (char*)src;
    ms_assert(len >= 0);
    for(int i = 0; i < len; i++) {
        *(d+i) = *(s+i);
    }
    return len;
}

CQUEUE_EMBED_Queue CQUEUE_newQueue(const unsigned int maxLen, const unsigned int itemSize, void * buffer) {
    CQUEUE_EMBED_Queue result;

    ms_assert(maxLen > 0);
    ms_assert(itemSize > 0);

    result.buffer = buffer;
    result.head = result.n = 0;
    result.itemSize = itemSize;
    result.maxLen = maxLen;


    return result;
}

unsigned int CQUEUE_enqueue(CQUEUE_EMBED_Queue *queue, void * item, unsigned int len) {
    ms_assert(!CQUEUE_isFull(queue));
    ms_assert(queue->itemSize == len);
    int index = (queue->head + queue->n % queue->maxLen) * queue->itemSize;
    queue->n++;

    CQUEUE_memcpy((queue->buffer + index), item, queue->itemSize);

    return 0;
}

int CQUEUE_dequeue(CQUEUE_EMBED_Queue *queue, void * buf, unsigned int len) {
    int index;
    if (CQUEUE_isEmpty(queue)) {
        return 0;
    }
    ms_assert(queue->itemSize == len);
    index = (queue->head)*queue->itemSize;
    queue->head++;
    queue->n--;
    return CQUEUE_memcpy(buf, queue->buffer + index, len);
}

int CQUEUE_isEmpty(CQUEUE_EMBED_Queue *queue) {
    return !queue->n;
}

int CQUEUE_isFull(CQUEUE_EMBED_Queue *queue) {
    return queue->n == queue->maxLen;
}
