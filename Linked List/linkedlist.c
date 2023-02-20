#include "stdlib.h"
#include "stdio.h"

struct linkedList
{
    int data;
    struct linkedList *next;
};

void insert(struct linkedList **list, int value)
{
    struct linkedList *node = malloc(sizeof(value));

    node->data = value;
    node->next = *list;
    *list = node;
}

void delete(struct linkedList **list, int value)
{
    struct linkedList *items = *list, *prev;

    // first element to delete
    if (items->next != NULL && items->data == value)
    {

        *list = items->next;
        free(items);
        return;
    }

    while (items != NULL && items->data != value)
    {
        prev = items;
        items = items->next;
    }

    if (items == NULL)
    {
        printf("Error, value not found\n");
        return;
    }

    prev->next = items->next;
    free(items);
}

struct linkedList *traverse(struct linkedList **list)
{

    if (list == NULL)
    {
        printf("Error, List is empty\n");
        return NULL;
    }
    struct linkedList *current = *list;

    while (current != NULL)
    {

        printf("%d\n", current->data);

        current = current->next;
    }
}

void freeList(struct linkedList **list)
{

    struct linkedList *items = *list;
    struct linkedList *next;

    while (items != NULL)
    {

        next = items->next;
        free(items);
        items = next;
    }

    free(list);
}

int main(int argc, char **argv)
{

    struct linkedList *list = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 4);

    traverse(&list);

    delete (&list, 9);
    printf("\n");

    traverse(&list);

    freeList(&list);

    traverse(&list);
}