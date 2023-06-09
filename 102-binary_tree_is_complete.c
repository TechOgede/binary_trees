#include "binary_trees.h"

/**
* check_node_index - checks the index of each node
* in a binary tree.
* @tree: pointer to the root node of the tree
* @index: index of the node
* @size: size of the tree
*
* Description: compares the index of each node with the
* size of the tree. It employs the array representation
* of a complete binary tree. In which the index of the left child
* is 2*i + 1 and that of the right child is 2*i + 2.
* For an incomplete binary tree, the index would equal or exceed
* the size of the tree.
* Return: 1 if tree is complete, 0 otherwise
*/

size_t check_node_index(binary_tree_t *tree, size_t index, size_t size)
{
	size_t lt, rt;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	lt = check_node_index(tree->left, (2 * index) + 1, size);
	rt = check_node_index(tree->right, (2 * index) + 2, size);

	return (lt & rt);
}

/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
*
* Description: the number of nodes in a complete binary tree
* is always a power of two
* Return: 1, if tree is complete. 0 othewise
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes, is_complete;

	if (!tree)
		return (0);

	num_nodes = binary_tree_size(tree);

	is_complete = check_node_index((binary_tree_t *)tree, 0, num_nodes);

	return (is_complete);
}

/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree
*
* Description: the size of a binary tree can be determined
* using recursion
* Return: number denoting the size
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_lt, size_rt;

	size_lt = tree && tree->left ? binary_tree_size(tree->left) : 0;
	size_rt = tree && tree->right ? binary_tree_size(tree->right) : 0;

	if (!tree)
		return (size_lt + size_rt);

	return (size_lt + size_rt + 1);
}
