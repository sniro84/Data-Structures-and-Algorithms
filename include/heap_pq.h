/************************************************ 
EXERCISE      : DS#10: Heap Priority Queue
Implmented by : Snir Holland
Reviewed by   : Yehuda Tarona
Date          : 20/6/23
File          : heap_pq.h
*************************************************/

#ifndef _HEAP_PRIORITY_QUEUE_H__
#define _HEAP_PRIORITY_QUEUE_H__

#include <stddef.h>
#include "heap_pq.h" 

/*
*    Compare function between data and parm.
*
*    Arguments:
*        data - the data to do compare.
*        param - the param to do compare.
*
*    Return: 0 if isnt math 1 if match
*
*/
typedef int (*pq_is_match_t)(const void *data, const void *param);

typedef int (*pq_compare_t)(const void *data_1, const void *data_2);

typedef struct priority_queue pq_t;

/*
*
*	creates a new Queue
*
*	Arguments:
*		cmp - compare function.
*
*	Return: a new priority Queue if successful
*				otherwise return NULL.
*
*	Time complexity: O(1) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
pq_t *HeapPQCreate(pq_compare_t cmp);

/*
*
*	frees all memory allocated for the Queue
*
*	Arguments:
*		pq - priority Queue to destroy. must be a valid address.
*
*	Return: void.
*
*	Time complexity: O(n) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
void HeapPQDestroy(pq_t *pq);

/*
*
*	add a value to the end of the Queue
*
*	Arguments:
*		pq - pointer to the queue to change. must be vaild.
*		data - The value that we wish to add to the end of the Queue.
*
*
*	Return: 0 - success,
*			1- failure.
*
*	Time complexity: O(n) best/average, O(n) - worst
*	Space complexity: O(1) best/average/worst
*
*/
int HeapPQEnqueue(pq_t *pq, void *data);

/*
*
*	remove a value from the front of the Queue
*
*	Arguments:
*		pq - pointer to the queue to change. must be vaild.
*
*	Return: data of dequeued element.
*
*	Time complexity: O(1) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
void *HeapPQDequeue(pq_t *pq);

/*
*
*	return the value at the front of the Queue.
*
*	Arguments:
*		pq - pointer to the queue to check. must be vaild.
*
*	Return: A pointer to the value at the front of the Queue.
*
*	Time complexity: O(1) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
void *HeapPQPeek(const pq_t *pq);

/*
*
*	Checks if the Queue is empty
*
*	Arguments:
*		pq - pointer to the queue to check. must be vaild.
*
*	Return: 1 - if the queue is empty, 0 - otherwise
*
*	Time complexity: O(1) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
int HeapPQIsEmpty(const pq_t *pq);

/*
*
*	Return the number of current values in the Queue 
*
*	Arguments:
*		pq - pointer to the queue to check. must be vaild.
*
*	Return: number of values in the queue 
*
*	Time complexity: O(n) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
size_t HeapPQGetSize(const pq_t *pq);


/*
*
*	Remove all the elements from the Queue 
*
*	Arguments:
*		pq - pointer to the queue to be cleared. must be vaild.
*
*	Return: void. 
*
*	Time complexity: O(n) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
void HeapPQClear(pq_t *pq);

/*
*
*	Erase the first occurrence of an element in the queue 
*
*	Arguments:
*		pq - pointer to the queue to search for the data. must be vaild.
*		func - boolean match function
		param - the param to match
*	Return: Erased data. 
*
*	Time complexity: O(n) best/average/worst
*	Space complexity: O(1) best/average/worst
*
*/
void *HeapPQErase(pq_t *pq, pq_is_match_t func, void *param);


#endif /* _HEAP_PRIORITY_QUEUE_H__ */
