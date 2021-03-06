/*****************************************************************************/
/**       Copyright 1988 by Evans & Sutherland Computer Corporation,        **/
/**                          Salt Lake City, Utah                           **/
/**  Portions Copyright 1989 by the Massachusetts Institute of Technology   **/
/**                        Cambridge, Massachusetts                         **/
/**                                                                         **/
/**                           All Rights Reserved                           **/
/**                                                                         **/
/**    Permission to use, copy, modify, and distribute this software and    **/
/**    its documentation  for  any  purpose  and  without  fee is hereby    **/
/**    granted, provided that the above copyright notice appear  in  all    **/
/**    copies and that both  that  copyright  notice  and  this  permis-    **/
/**    sion  notice appear in supporting  documentation,  and  that  the    **/
/**    names of Evans & Sutherland and M.I.T. not be used in advertising    **/
/**    in publicity pertaining to distribution of the  software  without    **/
/**    specific, written prior permission.                                  **/
/**                                                                         **/
/**    EVANS & SUTHERLAND AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD    **/
/**    TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  OF  MERCHANT-    **/
/**    ABILITY  AND  FITNESS,  IN  NO  EVENT SHALL EVANS & SUTHERLAND OR    **/
/**    M.I.T. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAM-    **/
/**    AGES OR  ANY DAMAGES WHATSOEVER  RESULTING FROM LOSS OF USE, DATA    **/
/**    OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER    **/
/**    TORTIOUS ACTION, ARISING OUT OF OR IN  CONNECTION  WITH  THE  USE    **/
/**    OR PERFORMANCE OF THIS SOFTWARE.                                     **/
/*****************************************************************************/

/***********************************************************************
 *
 * $XConsortium: menus.h,v 1.24 89/12/10 17:46:26 jim Exp $
 *
 * twm menus include file
 *
 * 17-Nov-87 Thomas E. LaStrange		File created
 *
 ***********************************************************************/

#ifndef _MENUS_
#define _MENUS_

#define TWM_ROOT		"bLoB_GoOp"	/* my private root menu */

#define TWM_WINDOWS		"TwmWindows"	/* for f.menu "TwmWindows" */

#define VTWM_WINDOWS	"VTWM Windows"	/* for f.menu "VTWM Windows" */

#define MAX_FILE_SIZE	4096	/* max chars to read from file for cut */

/* for builtin system, presumably never needs changing */
#ifndef BOURNE_SHELL
#define BOURNE_SHELL	"/bin/sh"
#endif

typedef struct MenuItem
{
  struct MenuItem *next;	/* next menu item */
  struct MenuItem *prev;	/* prev menu item */
  struct MenuRoot *sub;		/* MenuRoot of a pull right menu */
  struct MenuRoot *root;	/* back pointer to my MenuRoot */
  char *item;			/* the character string displayed */
  char *action;			/* action to be performed */

  ColorPair normal;		/* unhiglight colors */
  ColorPair highlight;		/* highlight colors */

  short item_num;		/* item number of this menu */
  short x;			/* x coordinate for text */
  short func;			/* twm built in function */
  short state;			/* video state, 0 = normal, 1 = reversed */
  short strlen;			/* strlen(item) */
  short user_colors;		/* colors were specified */

  short separated;		/* separated from the next item */

} MenuItem;

/* The structure for the whole of the menu. */
typedef struct MenuRoot
{
  struct MenuItem *first;	/* first item in menu */
  struct MenuItem *last;	/* last item in menu */
  struct MenuRoot *prev;	/* the parent MenuRoot if this menu was entered
				 * by pulling right from another menu */
  struct MenuRoot *next;	/* next in the list of MenuRoots */
  char *name;			/* name of root */
  MyWindow w;			/* the window of the menu */
  Window shadow;		/* the shadow window */

  ColorPair highlight;		/* highlight colors */

  short mapped;			/* NEVER_MAPPED, UNMAPPED, or MAPPED */
  short height;			/* height of the menu */
  short width;			/* width of the menu */
  short items;			/* number of items in the menu */
  short pull;			/* is there a pull right entry? */
  short entered;		/* EnterNotify following pop up of this menu
				 * has been processed */
  short real_menu;		/* this is a real menu */

  short too_tall;		/* menu taller than display? */
  short top;			/* first item displayed */
} MenuRoot;

#define NEVER_MAPPED	0	/* constants for mapped field of MenuRoot */
#define UNMAPPED	1
#define MAPPED		2


typedef struct MouseButton
{
  int func;			/* the function number */
  int mask;			/* modifier mask */
  MenuRoot *menu;		/* menu if func is F_MENU */
  MenuItem *item;		/* action to perform if func != F_MENU */
} MouseButton;

typedef struct FuncButton
{
  struct FuncButton *next;	/* next in the list of function buttons */
  int num;			/* button number */
  int cont;			/* context */
  int mods;			/* modifiers */
  int func;			/* the function number */
  MenuRoot *menu;		/* menu if func is F_MENU */
  MenuItem *item;		/* action to perform if func != F_MENU */
} FuncButton;

typedef struct FuncKey
{
  struct FuncKey *next;		/* next in the list of function keys */
  char *name;			/* key name */
  KeySym keysym;		/* X keysym */
  KeyCode keycode;		/* X keycode */
  int cont;			/* context */
  int mods;			/* modifiers */
  int func;			/* function to perform */
  char *win_name;		/* window name (if any) */
  char *action;			/* action string (if any) */
} FuncKey;

extern int RootFunction;
extern MenuRoot *ActiveMenu;
extern MenuItem *ActiveItem;
extern int MoveFunction;
extern int WindowMoved;
extern int ConstMove;

#define MAXMENUDEPTH	10	/* max number of nested menus */
extern int MenuDepth;

#define MOVE_NONE	0	/* modes of constrained move */
#define MOVE_VERT	1
#define MOVE_HORIZ	2

#define WARPSCREEN_NEXT "next"
#define WARPSCREEN_PREV "prev"
#define WARPSCREEN_BACK "back"

#define COLORMAP_NEXT "next"
#define COLORMAP_PREV "prev"
#define COLORMAP_DEFAULT "default"


#endif /* _MENUS_ */


/*
  Local Variables:
  mode:c
  c-file-style:"GNU"
  c-file-offsets:((substatement-open 0)(brace-list-open 0)(c-hanging-comment-ender-p . nil)(c-hanging-comment-beginner-p . nil)(comment-start . "// ")(comment-end . "")(comment-column . 48))
  End:
*/
/* vim: sw=2
*/
