#include "binary_trees.h"

/**
* binary_tree_postorder - goes through a binary tree using post-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: function to be called on each node of the tree
*
* Description: Post-order traversal involes visiting the left subtree first
* then the right subtree and finally the root node
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{

		binary_tree_postorder(tree->left, func);

		binary_tree_postorder(tree->right, func);

		func(tree->n);
	}
}
