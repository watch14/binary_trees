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
        if (binary_tree_is_descendant(ancestor, second))
            return (ancestor);

        ancestor = ancestor->parent;
    }

    return (NULL);
}

/**
 * binary_tree_is_descendant - Checks if a node is a
 * descendant of another node.
 * @ancestor: The potential ancestor node.
 * @node: The node to check for descendant.
 *
 * Return: 1 if node is a descendant, 0 otherwise.
 */
int binary_tree_is_descendant(const binary_tree_t *ancestor,
                              const binary_tree_t *node)
{
    int left_descendant;
    int right_descendant;

    if (ancestor == NULL || node == NULL)
        return (0);

    left_descendant = binary_tree_is_descendant(ancestor, node->left);
    right_descendant = binary_tree_is_descendant(ancestor, node->right);

    return (left_descendant || right_descendant || (ancestor == node));
}
