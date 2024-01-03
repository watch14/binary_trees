#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	return (binary_tree_is_perfect_recursive(tree, height, 0, nodes));
}

/**
 * binary_tree_is_perfect_recursive - Helper function to check
 * if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * @height: The height of the tree.
 * @level: The current level.
 * @nodes: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, size_t height,
		size_t level, size_t nodes)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (height == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_recursive(tree->left, height, level + 1, nodes)
			&& binary_tree_is_perfect_recursive(tree->right, height, level + 1, nodes));
}
