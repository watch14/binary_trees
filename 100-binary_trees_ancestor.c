#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if none found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	binary_tree_t *ancestor = (binary_tree_t *)first;

	while (ancestor != NULL)
	{
		if (ancestor == second ||
				(ancestor->left == second || ancestor->right == second) ||
				(ancestor->parent == second && ancestor->parent != NULL))
			return (ancestor);

		ancestor = ancestor->parent;
	}

	return (NULL);
}
