#include "binary_trees.h"

/**
 * binary_tree_size - measures size of binary tree.
 * @tree: pointer to the tree to measure the size.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the depth of @tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	left_size = binary_tree_size(left);
	right_size = binary_tree_size(right);

	return (1 + left_size + right_size);
}
