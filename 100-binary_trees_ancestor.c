#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: pointer to the first node
* @second: pointer to the second node
*
* Description: checks through the ancestors of each node starting
* with their parents
* Return: a  pointer the lowest common ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *parent_first, *parent_second;
	int depth_first, depth_second, depth_diff, i;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	depth_first = (int)binary_tree_depth(first);
	depth_second = (int)binary_tree_depth(second);
	parent_first = first->parent;
	parent_second = second->parent;
	if (depth_first != depth_second)
	{
		depth_diff = depth_first - depth_second;
		for (i = 0; i < abs(depth_diff); i++)
		{
			if (depth_diff > 0)
			{
				if (parent_first == second)
					return (parent_first);
				parent_first = parent_first->parent;
			}
			else
			{
				if (parent_second == first)
					return (parent_second);
				parent_second = parent_second->parent;
			}
		}
	}
	while (parent_first != parent_second)
	{
		if (parent_first == second)
			return (parent_first);
		parent_first = parent_first->parent;
		if (parent_second == first)
			return (parent_second);
		parent_second = parent_second->parent;
	}
	return (parent_first);
}

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @tree: pointer to the node to measure the depth
*
* Description: The depth of a node is the num of ancestors it has
* Return: a number denoting the depth
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = tree && tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;

	return (depth);
}
