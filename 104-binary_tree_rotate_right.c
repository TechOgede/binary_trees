#include "binary_trees.h"

/**
* binary_tree_rotate_right - perfoms a right-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
*
* Description: The left child of the root node becomes the new root node
* and the old root node becoems the right child of the new root node.
* The right child of the new root becomes the left child of the old root
*
* Return: a pointer to the new root node
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	new_root = tree->left;

	tree->parent = new_root;

	tree->left = new_root->right;

	new_root->right = tree;

	new_root->parent = NULL;

	return (new_root);
}
