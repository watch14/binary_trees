#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = 0, rear = 0;
	int null_found = 0;

	if (tree == NULL)
		return (0);

	binary_tree_t **queue = NULL;

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (current == NULL)
			null_found = 1;
		else
		{
			if (null_found)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	free(queue);
	return (1);
}
