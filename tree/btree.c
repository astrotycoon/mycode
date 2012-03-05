/*************************************************************************
*	filename:	btree.c
*
*	descripton:	binary tree 
*
*	author:		astrol	
*	
*	time:		10:32:45（2012-03-04）
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "btree.h"

static p_btree_node_t btree_create_node(void)
{
	p_tree_node_t node_ret = NULL;
	node_ret = (p_tree_node_t)malloc(sizeof(btree_node_t));
	
	return node_ret;
}

extern p_btree_t btree_create(void)
{
	p_btree_t tree_ret = NULL;

	tree_ret = (p_btree_t)malloc(sizeof(btree_t));
	if (NULL == tree_ret)
	{
		errno = ENOMEM;
		return NULL;
	}
	
	tree_ret->root = btree_create_node();
	if (NULL == tree_ret->root)
	{
		free(tree_ret);
		errno = ENOMEM;
		return NULL;
	}

	tree_ret->count = 0;
	tree_ret->root->data = NULL;
	tree_ret->root->lchild = NULL;
	tree_ret->root->rchild = NULL;

	return tree_ret;
}

extern void btree_destroy(p_btree_t tree)
{
#if TREE_ARG_CHECK == 1
	if (NULL == tree)
	{
		errno = EINVAL;
		return;
	}
#endif
	if (tree->lchild != NULL)
	{
		btree_destroy(tree->lchild);
	}
	if (tree->rchild != NULL)
	{
		btree_destroy(tree->rchild);
	}

	
}
