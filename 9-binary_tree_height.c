#include "binary_trees.h"

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to be measured
*
* Description: The height of a binary tree is the number of edges
* on the longest path from root to leaf
* Return: a number denoting the size
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (h_left > h_right ? h_left : h_right);
}
