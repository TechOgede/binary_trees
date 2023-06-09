#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the
* as the left child of another node.
* @parent: pointer to the node to insert left-child in
* @value: value to store in the new node
*
* Description: Dynamically allocates memory for a new node
* and sets it to be the left-child of its parent.
* if parent already has a left child, that child is set as the
* left child of the new node.
* Return: pointer to the new node or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	new->left = parent->left;
	if (parent->left)
		parent->left->parent = new;

	parent->left = new;

	return (new);
}
