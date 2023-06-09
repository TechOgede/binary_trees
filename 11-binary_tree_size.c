#include "binary_trees.h"

/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree
*
* Description: the size of a binary tree can be determined
* using recursion
* Return: number denoting the size
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_lt, size_rt;

	size_lt = tree && tree->left ? binary_tree_size(tree->left) : 0;
	size_rt = tree && tree->right ? binary_tree_size(tree->right) : 0;

	if (!tree)
		return (size_lt + size_rt);

	return (size_lt + size_rt + 1);
}
