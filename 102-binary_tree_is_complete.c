#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_last_level = 0;
	binary_tree_t *queue[1024];
	int front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current == NULL)
			is_last_level = 1;
		else
		{
			if (is_last_level)
				return (0);

			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	return (1);
}

