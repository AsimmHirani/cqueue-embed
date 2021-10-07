//
// Created by Asimm on 2021-10-06.
//

#ifndef CQUEUE_EMBED_CQUEUE_TARGET_H
#define CQUEUE_EMBED_CQUEUE_TARGET_H

#ifdef CQUEUE_DESKTOP

#include <stdio.h>
#include <stdlib.h>
#define ms_abort fprintf(stderr, "%s\n", mssert_buffer); exit(EXIT_FAILURE);

#elif defined(CQUEUE_EMBED)

#define ms_abort while(1);

#endif

#endif //CQUEUE_EMBED_CQUEUE_TARGET_H
