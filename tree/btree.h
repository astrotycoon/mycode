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

#define TREE_ARG_CHECK	1			/* check arg or not	*/
typedef struct _btree_node {
	void *data;				/* pointer to data 	*/
	struct _btree_node *lchild;		/* left child 		*/
	struct _btree_node *rchild;		/* right child		*/
}btree_node_t, *p_btree_node_t;

typedef struct _btree {
	struct _btree_node *root;		/* pointer to root node	*/
	size_t count;
}btree_t, *p_btree_t;

typedef int (*Compare)(void *, void *);
typedef void (*Operate)(void *);

/* create a btree	*/
extern p_btree_t btree_create(void);
/* destroy a btree 	*/
extern void btree_destroy(p_btree_t tree);
/* return pointer to a specfied node	*/
extern p_btree_node_t btree_search(p_tree_t tree, void *data, Compare compare);
/* traverse btree	*/
extern void btree_prev_traverse(p_btree_t tree, Operate operate);
extern void btree_in_traverse(p_btree_t tree, Operate operate);
extern void btree_post_traverse(p_btree_t tree, Operate operate);
extern void btree_level_traverse(p_btree_t tree, Operate operate);


 



 
#endif	/* __BTREE_H__ */
