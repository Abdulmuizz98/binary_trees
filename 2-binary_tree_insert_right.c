#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node as right child of another.
 * @parent: pointer to the node to insert the right-child in
 * @value: value to put in the new node.
 *
 * Return: a pointer to the created node;
 * if fails, NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	else /* If parent has an existing right*/
	{
		/*set new_node right to be parent's existing right*/
		new_node->right = parent->right;
		/*set parent's existing right parent to new_node*/
		parent->right->parent = new_node;
		/*set parent's right to new_node*/
		parent->right = new_node;
	}
	return (new_node);
}
