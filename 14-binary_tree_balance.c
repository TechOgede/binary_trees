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
	int left, right;

	left = tree && tree->left ? binary_tree_balance(tree->left) : -1;

	right = tree && tree->right ? binary_tree_balance(tree->right) : -1;

	return (left - right);
}
