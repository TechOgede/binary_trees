#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
*
* Description: To rotate a tree left,
* the right child of the root node becomes the root node
* and the ex root node becomes the left child of the new root node.
* the left child of the new root becomes the right child of the old root
* Return: pointer to the new root node
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	new_root = tree->right;

	tree->parent = new_root;

	tree->right = new_root->left;

	new_root->left = tree;

	new_root->parent = NULL;

	return (new_root);
}
