#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Integer value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_br;

	new_br = malloc(sizeof(binary_tree_t));

	if (!new_br)
		return (NULL);

	new_br->n = value;
	new_br->parent = parent;
	new_br->right = NULL;
	new_br->left = NULL;

	return (new_br);
}
