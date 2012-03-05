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
	}data;
}glist_t, *p_glist_t;
/* init glist */
p_glist_t glist_init(char *string);
/* create glist */
int glist_crete(p_glist_t glist, char *string);
/* get the head of glist */
p_glist_t glist_gethead(p_glist_t glist);
/* get the tail of glist */
p_glist_t glist_gettail(p_glist_t glist);
/* get the length of glist */
int glist_getlength(p_glist_t glist);
/* get the depth of glist */
int glist_getdepth(p_glist_t glist);
/* copy glist_src to glist_dst */
bool glist_copy(p_glist_t glist_dst, p_glist_t glist_src);



#endif	/* __GLIST__ */
