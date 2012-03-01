/*************************************************************************
*	filename: 	glist.h
*
*	description: 	general list implementation
*
*	author:		astrol	
*		
*	time: 		Sat Feb 25 20:57:03 CST 2012	
*
**************************************************************************/

#ifndef __GLIST__
#define __GLIST__

#include <stdbool.h> 	/* C99 */

typedef enum gtypes
{
	ATOM,	/* ATOM == 0, the data is atom */
	LIST	/* LIST == 1, the data is list */
}gtypes_t;

typedef struct glnode
{
	gtypes_t type;	/* distinguish the data is atom or list */

	union
	{
		void *atom;
		struct
		{
			struct glnode *phead;	/* pointer to the head of glist */
			struct glnode *ptail;	/* pointer to the tail of glist */
		}ptr;	
	}
}glnode_t, *p_glnode_t;

p_glnode_t glist_init(char *string);
p_glnode_t glist_gethead(p_glnode_t glist);

#endif	/* __GLIST__ */
