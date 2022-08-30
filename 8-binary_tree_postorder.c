#include "binary_trees.h"

/**
 * binary_tree_postorder - post-order traversal of binary tree.
 * @tree: pointer to the root of the tree.
 * @func: pointer to a callback function for each node.
 *
 * Return: Nothing, if @tree or @func is NULL do nothing;
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left, *right;

	if (tree == NULL || func == NULL)
		return;

	left = tree->left;
	right = tree->right;

	binary_tree_postorder(left, func);
	binary_tree_postorder(right, func);
	func(tree->n);
}
