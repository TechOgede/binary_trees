#include "binary_trees.h"

/**
* binary_tree_node - Creates a binary tree node
* @parent: pointer to the parent node
* of the node to create.
* @value: integer value to be put in the new node
*
* Description: Dynamically allocates memory for a new node
* Return: pointer to the new node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;

	return (new);
}
