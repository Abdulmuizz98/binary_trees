#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: pointer to the root of the tree
 *
 * Return: Nothing, if @tree is NULL do nothing;
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return;

	left = tree->left;
	right = tree->right;


	binary_tree_delete(left);
	free(tree);
	binary_tree_delete(right);
}
