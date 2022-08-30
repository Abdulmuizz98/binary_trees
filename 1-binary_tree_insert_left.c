#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as left child of another.
 * @parent: pointer to the node to insert the left-child in
 * @value: value to put in the new node.
 *
 * Return: a pointer to the created node;
 * if fails, NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else /* If parent has an existing left*/
	{
		/*set new_node left to be parent's existing left*/
		new_node->left = parent->left;
		/*set parent's existing left parent to new_node*/
		parent->left->parent = new_node;
		/*set parent's left to new_node*/
		parent->left = new_node;
	}
	return (new_node);
}
