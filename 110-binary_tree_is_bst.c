#include "binary_trees.h"

/**
* min_value - determines the min value in a subtree
* @tree: pointer to the root node
*
* Description: uses recursion to determmine min value
* Return: the min value in the subtree
*/

int min_value(binary_tree_t *tree)
{
	int value, min_left, min_right;

	min_left = tree->left ? min_value(tree->left) : INT_MAX;
	min_right = tree->right ? min_value(tree->right) : INT_MAX;

	if (min_left < min_right)
		value = min_left;

	else
		value = min_right;

	if (tree->n < value)
		value = tree->n;

	return (value);
}



/**
* max_value - determines the max value in a subtree
* @tree: pointer to the root node
*
* Description: uses recursion to determines max value
* Return: the max value in the sub tree
*/

int max_value(binary_tree_t *tree)
{
	int value, max_left, max_right;

	max_left = tree->left ? max_value(tree->left) : INT_MIN;
	max_right = tree->right ? max_value(tree->right) : INT_MIN;

	if (max_left > max_right)
		value = max_left;

	else
		value = max_right;

	if (tree->n > value)
		value = tree->n;

	return (value);
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

	if (tree->left && max_value(tree->left) > tree->n)
		return (0);

	if (tree->right && min_value(tree->right) < tree->n)
		return (0);

	return (1);
}
