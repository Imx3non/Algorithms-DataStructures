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
    struct linkedList *items = *list;
    if (*list == NULL)
    {
        printf("error, List is empty\n");
        return;
    }

    else if (items->data == value)
    {

        if (items->next != NULL)
        {

            items->data = items->next->data;
            items->next = items->next->next;
        }
        else
        {
            free(items);
            free(list);
        }
    }

    else
    {
        struct linkedList *current = items->next;
        struct linkedList *prev = items;

        while (current != NULL)
        {

            if (current->data == value)
            {

                struct linkedList *temp = current;
                prev->next = current->next;
                free(temp);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
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

    delete (&list, 2);
    printf("\n");

    traverse(&list);

    freeList(&list);

    traverse(&list);
}