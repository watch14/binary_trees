#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node to the right
 * @parent: Pointer to the parent node
 * @value: Integer value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_br;

	if (!parent)
		return (NULL);

	new_br = binary_tree_node(parent, value);

	if (!new_br)
		return (NULL);

	if (parent->right)
	{
		new_br->right = parent->right;
		parent->right->parent = new_br;
	}
	parent->right = new_br;
	return (new_br);
}
