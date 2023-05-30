#include "binary_trees.h"

/**
* binary_tree_is_leaf - checks if a node is a leaf
* @node: pointer to the node to check
*
* Description: checks for the presence of children at the node
* Return: 1 if node is a leaf, otherwiase 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && (node->left ==  NULL && node->right == NULL))
		return (1);

	return (0);
}
