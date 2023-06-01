#include "binary_trees.h"

/**
* binary_tree_sibling - find the sibling of a node
* @node: the node whose sibling is to be found
*
* Description: left sibling finds right sibling and vice versa
* Return: a pointer to the sibling node or NULL
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->right != node)
		return (node->parent->right);

	return (node->parent->left);
}
