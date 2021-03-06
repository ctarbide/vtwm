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

/**********************************************************************
 *
 * $XConsortium: parse.h,v 1.14 89/12/14 14:51:25 jim Exp $
 *
 * .twmrc parsing externs
 *
 *  8-Apr-88 Tom LaStrange        Initial Version.
 *
 **********************************************************************/

#ifndef _PARSE_
#define _PARSE_


/*
 * This is private to VTWM, to indicate no or invalid functions.
 */
#define F_NOFUNCTION		0

#define F_NOP			0
#define F_BEEP			1
#define F_RESTART		2
#define F_QUIT			3
#define F_FOCUS			4
#define F_REFRESH		5
#define F_WINREFRESH		6
#define F_DELTASTOP		7
#define F_MOVE			8
#define F_POPUP			9
#define F_FORCEMOVE		10
#define F_AUTORAISE		11
#define F_IDENTIFY		12
#define F_ICONIFY		13
#define F_DEICONIFY		14
#define F_UNFOCUS		15
#define F_RESIZE		16
#define F_ZOOM			17
#define F_LEFTZOOM		18
#define F_RIGHTZOOM		19
#define F_TOPZOOM		20
#define F_BOTTOMZOOM		21
#define F_HORIZOOM		22
#define F_FULLZOOM		23
#define F_RAISE			24
#define F_RAISELOWER		25
#define F_LOWER			26
#define F_DESTROY		27
#define F_DELETE		28
#define F_SAVEYOURSELF		29
#define F_VERSION		30
#define F_TITLE			31
#define F_RIGHTICONMGR		32
#define F_LEFTICONMGR		33
#define F_UPICONMGR		34
#define F_DOWNICONMGR		35
#define F_FORWICONMGR		36
#define F_BACKICONMGR		37
#define F_NEXTICONMGR		38
#define F_PREVICONMGR		39
#define F_SORTICONMGR		40
#define F_CIRCLEUP		41
#define F_CIRCLEDOWN		42
#define F_CUTFILE		43
#define F_SHOWLIST		44
#define F_HIDELIST		45
#define F_NAIL			46
#define F_PANDOWN		47
#define F_PANLEFT		48
#define F_PANRIGHT		49
#define F_PANUP			50
#define F_RESETDESKTOP		51
#define F_MOVESCREEN		52
#define F_SNAP			53
#define F_HIDEDESKTOP		54
#define F_SHOWDESKTOP		55
#define F_ENTERDOOR		56
#define F_NEWDOOR		57
#define F_SNUGDESKTOP		58
#define F_SNUGWINDOW		59
#define F_AUTOPAN		60	/*RFB F_AUTOPAN */
#define F_RING			61	/*RFB F_RING */
#define F_SQUEEZELEFT		62	/*RFB F_SQUEEZE */
#define F_SQUEEZERIGHT		63	/*RFB F_SQUEEZE */
#define F_SQUEEZECENTER		64	/*RFB F_SQUEEZE */
#define F_SNAPREALSCREEN	65	/*RFB F_SNAPREALSCREEN */
#define F_VIRTUALGEOMETRIES	66	/*marcel@duteca.et.tudelft.nl */
#define F_DELETEDOOR		67	/*marcel@duteca.et.tudelft.nl */
#define F_ZOOMZOOM		68	/* RFB silly */
#define F_WARP			69	/* PF */
#define F_STICKYABOVE		70	/* DSE */
#define F_MAXIMIZE		71

#define F_MENU			101	/* string */
#define F_WARPTO		102	/* string */
#define F_WARPTOICONMGR		103	/* string */
#define F_WARPRING		104	/* string */
#define F_FILE			105	/* string */
#define F_EXEC			106	/* string */
#define F_CUT			107	/* string */
#define F_FUNCTION		108	/* string */
#define F_WARPTOSCREEN		109	/* string */
#define F_COLORMAP		110	/* string */
#define F_SETREALSCREEN		111	/* string */
#define F_WARPCLASSNEXT		112	/* string -- PF */
#define F_WARPCLASSPREV		113	/* string -- PF */
#define F_WARPTONEWEST		114	/* string -- PF */

#define F_SEPARATOR		115

#define F_NAMEDOOR		116

#define F_STARTWM		117

#define F_STATICICONPOSITIONS	118

#define F_WARPVISIBLE		119

#define F_WARPSNUG		120

#ifdef SOUND_SUPPORT
#define F_SOUNDS		121
#endif

#define F_STRICTICONMGR		122

#define F_BINDBUTTONS		123
#define F_BINDKEYS		124
#define F_UNBINDBUTTONS		125
#define F_UNBINDKEYS		126

#define F_PLAYSOUND		127

#ifdef TWM_USE_SLOPPYFOCUS
#define F_SLOPPYFOCUS		128
#endif

/*
 * Attention: the following panel-zoom functions should have their numeric codes
 * greater than the corresponding non-panel variants above, F_MAXIMIZE being the
 * 'threshold'. See also fullzoom().
 */
#define F_PANELZOOM		129	/* f.panelzoom "geom@#" (panel #, "0"-full, "."-current) */
#define F_PANELLEFTZOOM		130	/* geom := "left" */
#define F_PANELRIGHTZOOM	131
#define F_PANELTOPZOOM		132
#define F_PANELBOTTOMZOOM	133	/*  -"-           */
#define F_PANELHORIZOOM		134
#define F_PANELFULLZOOM		135
#define F_PANELMAXIMIZE		136
#define F_PANELGEOMETRYZOOM	137	/* geom := "WxH+X+Y" */

#define F_PANELMOVE		138	/* f.panelmove "geom@#" */
#define F_PANELLEFTMOVE		139
#define F_PANELRIGHTMOVE	140
#define F_PANELTOPMOVE		141
#define F_PANELBOTTOMMOVE	142
#define F_PANELGEOMETRYMOVE	143
#define F_RESIZETO		144

#define D_NORTH			1
#define D_SOUTH			2
#define D_EAST			3
#define D_WEST			4

#define R_NORTH			1
#define R_NORTHEAST		2
#define R_EAST			3
#define R_SOUTHEAST		4
#define R_SOUTH			5
#define R_SOUTHWEST		6
#define R_WEST			7
#define R_NORTHWEST		8
#define R_CENTERED		9


#endif /* _PARSE_ */


/*
  Local Variables:
  mode:c
  c-file-style:"GNU"
  c-file-offsets:((substatement-open 0)(brace-list-open 0)(c-hanging-comment-ender-p . nil)(c-hanging-comment-beginner-p . nil)(comment-start . "// ")(comment-end . "")(comment-column . 48))
  End:
*/
/* vim: sw=2
*/
