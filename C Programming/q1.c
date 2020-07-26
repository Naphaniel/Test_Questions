#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    unsigned val;
    struct node_t *next;
} node_t;

node_t *even_nodes(node_t **);

// Time Complexity O(N) where N is number of items in list.
// Space Complexity O(1) if excluding the created output list.
node_t *even_nodes(node_t **head)
{
    if (*head == NULL)
    {
        return NULL;
    }

    node_t *even_head = (node_t *)malloc(sizeof(node_t));
    if (even_head == NULL) // Memory not allocated
    {
        return NULL;
    }
    even_head->val = 0;
    even_head->next = NULL;

    node_t *current = *head;
    node_t *prev = *head;
    node_t *current_even = even_head;

    while (current)
    {
        if (current->val % 2 == 0)
        {
            prev->next = current->next;
            current_even->next = current;
            current_even = current_even->next;
        }
        prev = current;
        current = current->next;
    }
    return even_head->next;
}

int main(void)
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL) // Unable to allocate memory
    {
        return -1;
    }
    head->val = 1;
    head->next = NULL;

    return 0;
}
