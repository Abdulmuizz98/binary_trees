#include "binary_trees.h"


/**
 * free_queue - frees a queue.
 * @queue: the pointer to the head of the queue
 */
void free_queue(stack_t *queue)
{
	stack_t *trav;

	trav = queue;
	while (trav)
	{
		trav = trav->next;
		free(queue);
		queue = trav;
	}
}

/**
 * enqueue - adds a new node at the end of a queue.
 * @queue: the pointer to the head of the queue
 * @n: the value of the new node
 *
 * Return: if success - the address of the new element;
 * otherwise - NULL;
 */
stack_t *enqueue(stack_t **queue,  const binary_tree_t *n)
{
	stack_t *new_node, *trav;

	trav = *queue;
	/*create the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (NULL);
	}
	new_node->node = (binary_tree_t *)n;
	if (*queue) /* if head is not null */
	{
		/*traverse to the end of the list*/
		while ((trav)->next != NULL)
		{
			trav = (trav)->next;
		}
		/*set last element next to new node*/
		trav->next = new_node;
		/*set new node prev to last element*/
		new_node->prev = trav;
	}
	else
	{
		/*change head to new node*/
		*queue = new_node;
	}
	return (new_node);
}


/**
 * binary_tree_levelorder - level-order traversal of binary tree.
 * @tree: pointer to the root of the tree.
 * @func: pointer to a callback function for each node.
 *
 * Return: Nothing, if @tree or @func is NULL do nothing;
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	stack_t *queue = malloc(sizeof(stack_t));


	if (tree == NULL || func == NULL || queue == NULL)
		return;

	queue->node = (binary_tree_t *)tree;
	queue->next = NULL;
	queue->prev = NULL;
	while (queue != NULL)
	{
		stack_t *front = queue;
		binary_tree_t *current = front->node;

		func(current->n);
		if (current->left != NULL)
			enqueue(&queue, current->left);
		if (current->right != NULL)
			enqueue(&queue, current->right);
		queue = queue->next;
	}
	free_queue(queue);
}

