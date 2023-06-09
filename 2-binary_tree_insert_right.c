#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserts a node as the
* as the right child of another node.
* @parent: pointer to the node to insert right-child in
* @value: value to store in the new node
*
* Description: Dynamically allocates memory for a new node
* and sets it to be the right-child of its parent.
* if parent already has a right child, that child is set as the
* right child of the new node.
* Return: pointer to the new node or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	new->right = parent->right;
	if (parent->right)
		parent->right->parent = new;

	parent->right = new;

	return (new);
}
