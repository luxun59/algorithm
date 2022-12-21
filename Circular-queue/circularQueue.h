/*
 * @Author: luxun59 luxun59@126.com
 * @Date: 2022-12-19 15:44:16
 * @LastEditors: luxun59 luxun59@126.com
 * @LastEditTime: 2022-12-20 09:53:13
 * @FilePath: \algorithm\Circular-queue\circularQueue.h
 * @Description: 
 * 
 * Copyright (c) 2022 by luxun59 luxun59@126.com, All Rights Reserved. 
 */


#ifndef _CIRCULARQUEUE_H

#define _CIRCULARQUEUE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>



#define elem int

typedef struct queue {
    elem *data;
    int front;
    int rear;
    int max_size;
}queue, *pqueue;




void init_queue(pqueue q, int max_size);
pqueue create_queue(int max_size);
int full_queue(pqueue q);
int empty_queue(pqueue q);
int enqueue(pqueue q, int val);
elem dequeue(pqueue q);
void qeueFree(pqueue obj);



#endif

