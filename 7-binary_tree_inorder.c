#include "binary_trees.h"

/**
 * binary_tree_inorder - inorder traversal of binary tree.
 * @tree: pointer to the root of the tree.
 * @func: pointer to a callback function for each node.
 *
 * Return: Nothing, if @tree or @func is NULL do nothing;
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left, *right;

	if (tree == NULL || func == NULL)
		return;

	left = tree->left;
	right = tree->right;

	binary_tree_inorder(left, func);
	func(tree->n);
	binary_tree_inorder(right, func);
}
