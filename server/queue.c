#include "client.h"

typedef struct queue {
	Node* front;
	Node* rear;
} Queue;

typedef struct node 
{
	client_t *client;
	Node* next;
} Node;

int enqueue(Queue *q, client_t *client);
client_t *dequeue(Queue *q);
