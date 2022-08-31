#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: pointer to the node to find sibling.
 *
 * Return: NULL - if the node is NUll, has no siblings,
 * or node's parent is NULL;
 * otherwise, pointer to the sibling of node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (0);

	parent = node->parent;

	return ((parent->left == node) ? parent->right : parent->left);
}
