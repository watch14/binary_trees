#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root of the binary tree
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	return (lh > rh ? lh + 1 : rh + 1);
}
