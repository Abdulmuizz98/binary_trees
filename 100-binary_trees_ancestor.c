#include "binary_trees.h"

/**
 * is_ancestor - checks if a node is an ancestor of another.
 * @node: pointer to the node to check ancestor.
 * @ancestor: pointer to the possible ancestor.
 *
 * Return: 0 - if @ancestor or @node is NUll, if @ancestor is
 * not ancestor or @node or if @node's parent is NULL;
 * otherwise, 1 if @ancestor is ancestor of @node.
 */
int is_ancestor(const binary_tree_t *node, const binary_tree_t *ancestor)
{
	binary_tree_t *parent;

	if (node == NULL || ancestor == NULL || node->parent == NULL)
		return (0);

	parent = node->parent;

	while (parent != NULL)
	{
		if (parent == ancestor)
			return (1);

		parent = parent->parent;
	}

	return (0);
}

/**
 * binary_tree_depth - measures depth of a node of binary tree.
 * @tree: pointer to the node to measure the depth.
 *
 * Return: 0 if @tree is NULL;
 * otherwise, the depth of @tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (tree == NULL)
		return (0);

	parent = tree->parent;

	if (parent == NULL)
		return (0);

	return (1 + binary_tree_depth(parent));
}


/**
 * binary_trees_ancestor - finds the the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: NULL - if first or second is NUll,
 * or if no common ancestor was found;
 * otherwise, pointer to the lowest common ancestor of two nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *parent;
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first == 0)
		return ((binary_tree_t *)first);
	if (depth_second == 0)
		return ((binary_tree_t *)second);
	if (first == second)
		return (first);

	if (depth_first < depth_second)
	{
		parent = (binary_tree_t *)first;
		while (parent != NULL)
		{
			if (is_ancestor(second, parent))
				return (parent);
			parent = parent->parent;
		}
	}
	else
	{
		parent = (binary_tree_t *)second;
		while (parent != NULL)
		{
			if (is_ancestor(first, parent))
				return (parent);
			parent = parent->parent;
		}
	}

	return (NULL);
}
