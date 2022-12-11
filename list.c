#include "list.h"

//funkcia na vytvorenie a inicializáciu listu
list_t* list_create()
{
    list_t* list = malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;
    return list;
}

//funkcia na uvoľnenie alokovanej pamäte pre list a jeho prvky
void list_free(list_t* list)
{
    list_node_t* cur = list->head;
    while (cur != NULL)
    {
        list_node_t* next = cur->next;
        free(cur->data);
        free(cur);
        cur = next;
    }
    free(list);
}

//funkcia na pridanie prvku na koniec listu
void list_append(list_t* list, void* data)
{
    list_node_t* node = malloc(sizeof(list_node_t));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL)
        list->head = node;
    else
    {
        list_node_t* cur = list->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }

    list->size++;
}

//funkcia na vloženie prvku na zadanú pozíciu v liste
void list_insert(list_t* list, size_t index, void* data)
{
    if (index > list->size)
        return;

    list_node_t* node = malloc(sizeof(list_node_t));
    node->data = data;

    if (index == 0)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        list_node_t* cur = list->head;
        for (size_t i = 0; i < index - 1; i++)
            cur = cur->next;
        node->next = cur->next;
        cur->next = node;
    }

    list->size++;
}

//funkcia na získanie prvku z listu na zadanom indexe
void* list_get(list_t* list, size_t index)
{
    if (index >= list->size)
        return NULL;

    list_node_t* cur = list->head;
    for (size_t i = 0; i < index; i++)
        cur = cur->next;

    return cur->data;
}

//funkcia na odstránenie a vrátenie prvku z listu na zadanom indexe
void* list_pop(list_t* list, size_t index)
{
    if (index >= list->size)
        return NULL;

    list_node_t* cur = list->head;
    for (size_t i = 0; i < index - 1; i++)
        cur = cur->next;

    list_node_t* to_remove = cur->next;
    void* data = to_remove->data;
    cur->next = cur->next->next;
    free(to_remove);

    list->size--;

    return data;
}

//funkcia na odstránenie prvku z listu na zadanom indexe
void list_remove(list_t* list, size_t index)
{
    if (index >= list->size)
        return;

    list_node_t* cur = list->head;
    for (size_t i = 0; i < index - 1; i++)
        cur = cur->next;

    list_node_t* to_remove = cur->next;
    cur->next = cur->next->next;
    free(to_remove->data);
    free(to_remove);

    list->size--;
}

//funkcia na získanie počtu prvkov v liste
size_t list_size(list_t* list)
{
    return list->size;
}
