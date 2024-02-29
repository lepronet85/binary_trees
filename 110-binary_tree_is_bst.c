#include "binary_trees.h"

int is_bst_util(const binary_tree_t *tree, int *prev);

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree
 * @prev: A pointer to the previous node's value in inorder traversal
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int is_bst_util(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (*prev != -1 && tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (is_bst_util(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = -1;

	return (is_bst_util(tree, &prev));
}

