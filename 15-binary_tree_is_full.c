#include "binary_trees.h"

/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: pointer to the root node of the tree
*
* Description: A full binary tree is one in which
* each node has exactly zero or two children
* Return: 1 if binary tree is full, 0 otherwise.
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int lt, rt;

	if (!tree)
		return (0);

	if ((tree->left && !(tree->right)) || (tree->right && !(tree->left)))
		return (0);

	lt = tree->left ? binary_tree_is_full(tree->left) : 1;
	rt = tree->right ? binary_tree_is_full(tree->right) : 1;

	return (1 & lt & rt);
}
