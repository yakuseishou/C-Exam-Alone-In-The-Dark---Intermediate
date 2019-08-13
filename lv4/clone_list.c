#include <stdlib.h>

struct s_node {
    int           data;
    struct s_node *next;
    struct s_node *other;
};

struct s_node *init(int v)
{
    struct s_node *new = malloc(sizeof(struct s_node));
    new->data = v;
    new->next = 0;
    new->other = 0;
    return (new);
}

struct s_node *clonenext(struct s_node *node, int *l)
{
    if (!node)
        return (0);
    struct s_node *new = init(node->data);
    *l += 1;
    new->next = clonenext(node->next, l);
    return (new);
}

struct s_node   **nodeadr(struct s_node *node, int l)
{
    struct s_node     **arr;
    int     i = 0;

    arr = malloc(sizeof(struct s_node) * (l));
    while(node)
    {
        arr[i] = node;
        node = node->next;
        i++;
    }
    return (arr);
}

void    cloneothr(struct s_node *node, struct s_node *copy, struct s_node **a, struct s_node **b, int l)
{
    if (!node || !copy)
        return ;
    for (int i = 0; i < l; i++)
    {
        if (a[i] == node->other)
        {
            copy->other = b[i];
            break;
        }
    }
    cloneothr(node->next, copy->next, a, b, l);
}

struct s_node *clone_list(struct s_node *node)
{
    int     l = 0;
    struct s_node   *copy = clonenext(node, &l);
    struct s_node   **a = nodeadr(node, l);
    struct s_node   **b = nodeadr(copy, l);
    cloneothr(node, copy, a, b, l);
    return (copy);
}

#include <stdio.h>

int main() {

    struct s_node *a = init(1);
    struct s_node *b = init(2);
    struct s_node *c = init(3);
    struct s_node *d = init(4);

    a->next = b;
    b->next = c;
    c->next = d;
    a->other = a;
    b->other = b;
    c->other = a;
    d->other = b;

    struct s_node *tmp = a;
    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    tmp = a;
    while(tmp)
    {
        printf("%d ", tmp->other->data);
        tmp = tmp->next;
    }
    printf("\n");
    struct s_node *new = clone_list(a);
    tmp = new;
    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    tmp = new;
    while(tmp)
    {
        printf("%d ", tmp->other->data);
        tmp = tmp->next;
    }
    printf("\n");
    return 0;
}