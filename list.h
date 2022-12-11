#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

//struktúra pre jeden prvok listu
typedef struct list_node_t
{
    void* data;
    struct list_node_t* next;
} list_node_t;

//struktúra pre celý list
typedef struct list_t
{
    size_t size;
    list_node_t* head;
} list_t;

//funkcie pre prácu s listami
list_t* list_create();
void list_free(list_t* list);

void list_append(list_t* list, void* data);
void list_insert(list_t* list, size_t index, void* data);
void* list_get(list_t* list, size_t index);

void* list_pop(list_t* list, size_t index);
void list_remove(list_t* list, size_t index);

size_t list_size(list_t* list);

#endif
