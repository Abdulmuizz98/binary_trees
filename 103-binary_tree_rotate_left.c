#include "binary_trees.h"


/**
 * binary_tree_rotate_left - rotate a binary tree left.
 * @tree: pointer to the root of the tree.
 *
 * Return: NULL, if @tree is NULL.
 * otherwise, return the root of the rotated tree;
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root;

	if (tree == NULL)
		return (NULL);
	/*store roots right in som, root right is null;*/
	new_root = tree->right;
	new_root->parent = NULL;
	tree->right = NULL;

	/*store som left*/
	temp = new_root->left;

	/*som's left is now root;*/
	new_root->left = tree;
	tree->parent = new_root;

	/*attatch temp to root right;*/
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}
