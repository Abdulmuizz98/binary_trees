#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root of the tree.
 *
 * Return: 0 if @tree is NULL or if @tree not full;
 * 1, if @tree is full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_is_full, right_is_full;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (1);

	left_is_full = binary_tree_is_full(left);
	right_is_full = binary_tree_is_full(right);

	return (left_is_full * right_is_full);
}
