#include "binary_trees.h"

/**
* binary_tree_nodes - counts the number of nodes with at least one child
* @tree: pointer to the root node of the binary tree
*
* Description: Checks for the children of each node
* Return: number denoting the node count
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_left, num_right;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (0);

	num_left = tree->left ? binary_tree_nodes(tree->left) : 0;
	num_right = tree->left ? binary_tree_nodes(tree->right) : 0;

	return (1 + num_left + num_right);
}
