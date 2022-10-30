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
	new_node->next = NULL;
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
 * binary_tree_is_complete - level-order traversal of binary tree.
 * @tree: pointer to the root of the tree.
 *
 * Return: 0, if @tree is NULL or if tree is not complete.
 * otherwise, return 1;
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count = 0;
	stack_t *temp, *queue;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(stack_t));
	if (queue == NULL)
		return (0);

	queue->node = (binary_tree_t *)tree;
	queue->next = NULL;
	queue->prev = NULL;

	temp = queue;
	while (temp != NULL)
	{
		stack_t *front = temp;
		binary_tree_t *current = front->node;

		if (current->left != NULL)
		{
			if (current->right == NULL)
				count++;
			enqueue(&temp, current->left);
		}
		if (current->right != NULL)
		{
			if (current->left == NULL)
				return (0);
			enqueue(&temp, current->right);
		}
		temp = temp->next;
	}
	free_queue(queue);
	return ((count > 1) ? 0 : 1);
}

