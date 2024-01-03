#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal on a binary tree
 * @tree: Pointer to the root of the binary tree
 * @func: Pointer to a function to apply to each node's value
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->right, func);
	binary_tree_preorder(tree->left, func);
}
