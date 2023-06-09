#include "binary_trees.h"


/**
* level - calls a function on each node at a level
* @tree: pointer to the root node
* @i: number denoting the level in the tree
* @func: function to be called on each node at that level
*
* Description:
*/

void level(binary_tree_t *tree, size_t i, void (*func)(int))
{
	if (!tree)
		return;

	if (i == 0)
		func(tree->n);
	else
	{
		level(tree->left, i - 1, func);
		level(tree->right, i - 1, func);
	}
}

/**
* binary_tree_levelorder - goes through a binary tree
* using level-order traversal
* @tree: pointer to the root node
* @func: pointer to a function to call for each node
* Description: Goes through each node on the same level
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i < height + 1; i++)
		level((binary_tree_t *)tree, i, func);
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
