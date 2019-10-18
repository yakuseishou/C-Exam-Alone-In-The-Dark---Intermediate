#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

/* initiating a s_node */

struct s_node *init(int v)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->data = v;
	new->next = 0;
	new->other = 0;
	return (new);
}

/* copying s_node->next */

struct s_node	*clone_next(struct s_node *node, int *nodeL)
{
	if (!node)
		return (0);
	struct s_node *new = init(node->data);
	new->next = clone_next(node->next, nodeL);
	*nodeL += 1;
	return (new);
}

/* copying s_node->other */

struct s_node	*clone_other(struct s_node *node, struct s_node *clon, int nodeL)
{
	struct s_node 	*tmp = node;
	struct s_node   *tmpC = clon;

	struct s_node	**old = malloc(sizeof(struct s_node) * nodeL);
	struct s_node   **ne = malloc(sizeof(struct s_node) * nodeL);
	int				i = 0;

	for(i = 0; i < nodeL; i++)
	{
		old[i] = tmp;
		ne[i] = tmpC;
		tmp = tmp->next;
		tmpC = tmpC->next;
	}
	tmp = node;
	tmpC = clon;
	while(tmp && tmpC)
	{
		if (tmp->other)
		{
			for (i = 0; i < nodeL; i++)
			{
				if (tmp->other != NULL && old[i] == tmp->other)
				{
					tmpC->other = ne[i];
					break;
				}
			}
		}
		tmp = tmp->next;
		tmpC = tmpC->next;
	}
	return (clon);
}

struct s_node *clone_list(struct s_node *node)
{
	if (!node)
		return (0);
	int		nodeL = 0;
	struct s_node *clon = clone_next(node, &nodeL);
	clone_other(node, clon, nodeL);

	return (clon);
}

/* main for testing */

// #include <stdio.h>

// int main() {

//     struct s_node *a = init(1);
//     struct s_node *b = init(2);
//     struct s_node *c = init(3);
//     struct s_node *d = init(4);

//     a->next = b;
//     b->next = c;
//     c->next = d;
//     a->other = a;
//     b->other = b;
//     c->other = a;
//     d->other = b;

//     struct s_node *tmp = a;
//     while(tmp)
//     {
//         printf("%d ", tmp->data);
//         tmp = tmp->next;
//     }
//     tmp = a;
//     while(tmp)
//     {
//         printf("%d ", tmp->other->data);
//         tmp = tmp->next;
//     }
//     printf("\n");
//     struct s_node *new = clone_list(a);
//     tmp = new;
//     while(tmp)
//     {
//         printf("%d ", tmp->data);
//         tmp = tmp->next;
//     }
//     tmp = new;
//     while(tmp)
//     {
//         printf("%d ", tmp->other->data);
//         tmp = tmp->next;
//     }
//     printf("\n");
//     return 0;
// }