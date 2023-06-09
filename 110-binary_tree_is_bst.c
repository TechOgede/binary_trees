#include "binary_trees.h"


/**
* check_nodes - compares the values in each node of a binary tree
* with max and min values
* @tree: pointer to root node
* @min: minimum value
* @max: maximum value
*
* Description: Employs recursion. Does not allow duplicate values
* Return: 1 if tree is BST, 0 otherise
*/

int check_nodes(binary_tree_t *tree, int min, int max)
{
	int lt, rt;

	if (tree->n > max || tree->n < min)
		return (0);

	lt = tree->left ? check_nodes(tree->left, min, tree->n - 1) : 1;
	rt = tree->right ? check_nodes(tree->right, tree->n + 1, max) : 1;

	return (lt & rt);
}

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree
*
* Description: A Binary Search Tree is one in which all the values
* in the left subtree are less than the value at the node and
* the values in the right subtree are greater than the value at the node
* Return: 1 if tree is BST, 0 otherwise
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_nodes((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
