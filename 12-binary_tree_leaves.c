#include "binary_trees.h"

/**
 * binary_tree_leaves - measures number of leaves of binary tree.
 * @tree: pointer to the root of the tree.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the height of @tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_leaves, right_leaves, all_leaves;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (1);

	left_leaves = binary_tree_leaves(left);
	right_leaves = binary_tree_leaves(right);

	all_leaves = left_leaves + right_leaves;

	return (all_leaves);
}
