typedef struct s_node {
	int           value;
	struct s_node **nodes;
} Node;

int     height_tree(struct s_node *root)
{
    if (!root)
        return 0;
    int     max;
    int     h;

    h = 0;
    max = 0;
    while(*(root->nodes))
    {
        h = 1 + height_tree(*(root->nodes));
        if (h > max)
            max = h;    
        root->nodes++;
    }
    return (max);
}

#include <stdlib.h>
#include <stdio.h>

Node    *init(int v) {
    Node    *new = malloc(sizeof(Node));
    new->value = v;
    new->nodes = malloc(100000);
    return new;
}

void    to_free(Node *root)
{
    while(*(root->nodes))
    {
        Node *tmp;

        to_free(*(root->nodes));
        tmp = root;
        root->nodes++;
        free(tmp->nodes);
        free(tmp);
    }
}

int main() {

    Node* r = init(94);
    r->nodes[0] = init(34);
    r->nodes[1] = init(52);

    r->nodes[0]->nodes[0] = init(1);
    r->nodes[0]->nodes[1] = init(99);
    r->nodes[0]->nodes[2] = init(11);

    r->nodes[0]->nodes[1]->nodes[0] = init(13);

    printf("%d\n", height_tree(r));
    to_free(r);
    return (0);
}