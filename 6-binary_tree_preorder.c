#include "binary_trees.h"

/**
* binary_tree_preorder - goes through a binary tree using pre-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: function to be called on each node of the tree
*
* Description: Pre-order traversal involes visiting the root node first
* then the left subtree and then the right subtree
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);

		binary_tree_preorder(tree->right, func);
	}
}
