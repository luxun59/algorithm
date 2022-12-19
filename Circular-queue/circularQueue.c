/*
 * @Author: luxun59 luxun59@126.com
 * @Date: 2022-12-19 15:43:07
 * @LastEditors: luxun59 luxun59@126.com
 * @LastEditTime: 2022-12-19 23:00:16
 * @FilePath: \algorithm\Circular-queue\circularQueue.c
 * @Description: 
 * 
 * Copyright (c) 2022 by luxun59 luxun59@126.com, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "circularQueue.h"

// #define elem int

// typedef struct queue {
//     elem *data;
//     int front;
//     int rear;
//     int max_size;
// }queue, *pqueue;


/**
 * @description: 初始化队列
 * @param {pqueue} q
 * @param {int} max_size
 * @return {*}
 */
void init_queue(pqueue q, int max_size)
{
    q->front = q->rear = 0;
    q->data = (elem *)malloc(max_size * sizeof(elem));
    q->max_size = max_size;
}

/**
 * @description: 创建队列
 * @param {int} max_size
 * @return {*}
 */
pqueue create_queue(int max_size)
{
    pqueue mq = (pqueue)malloc(sizeof(queue));
    mq->front = mq->rear = 0;
    mq->data = (elem *)malloc(max_size * sizeof(elem));
    mq->max_size = max_size;
    return mq;
}
/**
 * @description: 判断队列是否已满
 * @param {pqueue} q
 * @return {*}
 */
int full_queue(pqueue q)
{
    return (q->front == (q->rear+1)%q->max_size) ? 1 : 0;
}
/**
 * @description: 判断队列是否为空
 * @param {pqueue} q
 * @return {*}
 */
int empty_queue(pqueue q)
{
    return (q->front == q->rear) ? 1 : 0;
}
/**
 * @description: 进入队列
 * @param {pqueue} q
 * @param {int} val
 * @return {*}
 */
int enqueue(pqueue q, int val)
{
    if(full_queue(q))
        return 0;
    else
    {
        q->data[q->rear]=val;
        q->rear = (q->rear+1)%q->max_size;
    }
    return 1;
}

/**
 * @description: 弹出队列
 * @param {pqueue} q
 * @return {*}
 */
bool dequeue(pqueue q)
{
    if(empty_queue(q))
        return 0;
    else
    {
        q->front = (q->front+1)%q->max_size;
    }
    return true;
}

void qeueFree(pqueue obj) {
    free(obj->data);
    free(obj);
}

// void print_queue(pqueue q)
// {
//     int i;
//     if(empty_queue(q)) {
//         printf("queue is empty\n");
//         return ;
//     } else {
//         for(i = q->front; i < q->rear; i++)
//             printf("queue data is %d\n", q->data[i]);
//     }
//     return;
// }

// int main()
// {
//     int i, num;
//     queue Q;
//     init_queue(&Q, 100);
//     for(i = 0; i < 3; i++)
//     {
//         printf("please input a number:");
//         scanf("%d", &num);
//         printf("\n");
//         if(enqueue(&Q, num) != 0)
//             printf("enqueue successful!\n");
//     }
//     print_queue(&Q);
//     return 0;
// }

