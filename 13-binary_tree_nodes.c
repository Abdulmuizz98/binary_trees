#include "binary_trees.h"

/**
 * binary_tree_nodes - measures nodes with at least one child.
 * @tree: pointer to the tree to measure the nodes.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the depth of @tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (0);

	left_nodes = binary_tree_nodes(left);
	right_nodes = binary_tree_nodes(right);

	return (1 + left_nodes + right_nodes);
}
