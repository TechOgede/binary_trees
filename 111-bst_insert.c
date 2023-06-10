#include "binary_trees.h"


/**
* bst_insert_util - inserts a value into a Binary Search Tree
* @tree: double pointer to the root of the BST
* @value: value to be stored in the BST
*
* Description: Insertion is done in a way that
* the traversal order is maintained
* Return: pointer to the new node
*/

bst_t *bst_insert_util(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));

		else
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));

		else
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
	}

	return (NULL);
}


/**
* bst_insert - Insert a value into a binary tree
* @tree: double pointer to the root node
* @value: value to be inserted
*
* Description: sets the root node if tree stores NULL
* and then calls bst_insert_util
* Return: pointer to the new node in which value is contained
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_util(tree, value));
}
