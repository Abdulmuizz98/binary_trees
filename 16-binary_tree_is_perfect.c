#include "binary_trees.h"
/**
 * binary_tree_height - measures height of binary tree.
 * @tree: pointer to the root of the tree.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the height of @tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_height, right_height, max_height;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (0);

	left_height = binary_tree_height(left);
	right_height = binary_tree_height(right);

	max_height = (left_height >= right_height) ? left_height : right_height;

	return (1 + max_height);
}

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

/**
 * power - raises a number to a power.
 * @a: number to be raised.
 * @b: power to be raised to.
 *
 * Return: a to power b.
 */
int power(int a, int b)
{
	int res = a;

	while (--b)
		res *= a;
	return (res);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root of the tree.
 *
 * Return: 0 if @tree is NULL or not perfect;
 * otherwise 1, if the @tree is perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/*
	 *	----------- condition for perfect tree -----------
	 *	number of leaves of the tree == 2 ^ height of tree
	 */
	return (power(2, binary_tree_height(tree)) == (int)binary_tree_leaves(tree));
}
