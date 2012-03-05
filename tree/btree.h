/*************************************************************************
*	filename:	btree.h
*
*	description:	binary tree head file
*
*	author:		astrol	
*
*	time:		19:13:40（2012-03-03）	
*************************************************************************/

#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdbool.h> 				/* C99			*/
#include <stddef.h>  				/* size_t		*/

typedef struct _btree_node {
	void *data;				/* data 		*/
	struct _btree_node *lchild;		/* left child 		*/
	struct _btree_node *rchild;		/* right child		*/
}btree_node_t, *p_btree_node_t;

typedef struct _btree {
	struct _btree_node *root;		/* pointer to root node	*/
	size_t count;
}btree_t, *p_btree_t;

/* create a btree	*/
extern p_btree_t btree_create(void);
/* destroy a btree 	*/
extern void btree_destroy(p_btree_t tree);
/* */
 



 
#endif
