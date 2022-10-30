#include "binary_trees.h"


/**
 * binary_tree_rotate_left - rotate a binary tree left.
 * @tree: pointer to the root of the tree.
 *
 * Return: NULL, if @tree is NULL.
 * otherwise, return the root of the rotated tree;
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root;

	if (tree == NULL)
		return (NULL);
	/*store roots left in som, root left is null;*/
	new_root = tree->left;
	new_root->parent = NULL;
	tree->left = NULL;

	/*store som right*/
	temp = new_root->right;

	/*som's right is now root;*/
	new_root->right = tree;
	tree->parent = new_root;

	/*attatch temp to root left;*/
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}
