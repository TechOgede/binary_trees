#include "binary_trees.h"


/**
* _pow - calculates the value of a number raised to a power
* @base: number to be raised
* @exp: number for which base is to be raised to
*
* Description: This function only calculates for positive powers
* of natural numbers
* Return: value sought
*/

size_t _pow(size_t base, size_t exp)
{
	size_t result = 1, i;

	for (i = 0; i < exp; i++)
		result *= base;

	return (result);
}
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
	size_t h_lt, h_rt;


	h_lt = tree && tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_rt = tree && tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (h_lt > h_rt ? h_lt : h_rt);
}

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

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree
*
* Description: A perfect binary tree is one where each node
* has two children and the leaf nodes are at the same level
* Return: 1 if binary tree is perfect, 0 othewise
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height, max_size;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	printf("height: %ld\n", height);
	max_size = _pow(2, (height + 1)) - 1;
	printf("base: %ld\n", max_size);

	size = binary_tree_size(tree);
	printf("size:  %ld\n", size);

	if (max_size == size)
		return (1);

	return (0);
}
