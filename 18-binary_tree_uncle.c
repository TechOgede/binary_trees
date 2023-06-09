#include "binary_trees.h"

/**
* binary_tree_uncle - finds the uncle of a node
* @node: pointer to the node
*
* Description: traverses the tree in search
* of a sibling of a parent node
* Return: a pointer to the uncle, or NULL
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->parent->right != node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
