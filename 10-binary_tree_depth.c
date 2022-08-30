#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of a node of binary tree.
 * @tree: pointer to the node to measure the depth.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the depth of @tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (tree == NULL)
		return (0);

	parent = tree->parent;

	if (parent == NULL)
		return (0);

	return (1 + binary_tree_depth(parent));
}
