#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order traversal of binary tree.
 * @tree: pointer to the root of the tree.
 * @func: pointer to a callback function for each node.
 *
 * Return: Nothing, if @tree or @func is NULL do nothing;
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left, *right;

	if (tree == NULL || func == NULL)
		return;

	left = tree->left;
	right = tree->right;

	func(tree->n);
	binary_tree_preorder(left, func);
	binary_tree_preorder(right, func);
}
