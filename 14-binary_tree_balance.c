#include "binary_trees.h"

/**
* binary_tree_balance - measure the balancing factor of a binary tree
* @tree: pointer to the root node of the tree
*
* Description: The balancing factor is calculated by
* subtracting the height of the left subtree from that
* of the right subtree.
* Return: an integer denoting the balance factor, 0 if tree is NULL
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}

/**
* height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to be measured
*
* Description: The height of a binary tree is the number of edges
* on the longest path from root to leaf
* Return: a number denoting the size
*/

int height(const binary_tree_t *tree)
{
	size_t h_lt, h_rt;

	if (!tree)
		return (-1);

	h_lt = tree->left ? 1 + height(tree->left) : 0;
	h_rt = tree->right ? 1 + height(tree->right) : 0;

	return (h_lt > h_rt ? h_lt : h_rt);
}
