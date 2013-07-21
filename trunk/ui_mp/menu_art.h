#include "ui_mp/menu_artdef.h"

// define work here.

#define CHOICE_X_START				0
#define CHOICE_Y_START				28	// pretty much standard, where you want the defined button to start.
#define CHOICE_X_SPACING			250
#define CHOICE_Y_SPACING			20
#define CHOICE_Y_COUNT				20
#define CHOICE_SIZE_X				344	// text x axis
#define CHOICE_SIZE_Y				20	// y axis button size
#define	CHOICE_CAPTION_OFFSET 		0	// button image size

#define CHOICE_SEP_OFFSET_X			0
#define CHOICE_SEP_OFFSET_Y			0
#define CHOICE_SEP_WIDTH			130

#if !defined( CHOICE_SEP_1 ) || !defined( CHOICE_SEP_SPACING )
#define CHOICE_SEP_TOTAL_SPACING( itemIndex )	0
#elif !defined( CHOICE_SEP_2 )
#define CHOICE_SEP_TOTAL_SPACING( itemIndex )	( ( itemIndex <= CHOICE_SEP_1 ) ? 0 : CHOICE_SEP_SPACING )
#elif !defined( CHOICE_SEP_3 )
#define CHOICE_SEP_TOTAL_SPACING( itemIndex )	( ( itemIndex <= CHOICE_SEP_1 ) ? 0 : ( ( itemIndex <= CHOICE_SEP_2 ) ? CHOICE_SEP_SPACING : CHOICE_SEP_SPACING * 2 ) )
#else
#define CHOICE_SEP_TOTAL_SPACING( itemIndex )	( ( itemIndex <= CHOICE_SEP_1 ) ? 0 : ( ( itemIndex <= CHOICE_SEP_2 ) ? CHOICE_SEP_SPACING : ( ( itemIndex <= CHOICE_SEP_3 ) ? CHOICE_SEP_SPACING * 2 : CHOICE_SEP_SPACING * 3 ) ) )
#endif

#define CHOICE_SEP_OFFSET( itemIndex )		CHOICE_ORIGIN( itemIndex ) 216 1 1 1

#define CHOICE_ROW( itemIndex )		( ( itemIndex - 1 ) % CHOICE_Y_COUNT )
#define CHOICE_COL( itemIndex )		( ( itemIndex - 1 - ( ( itemIndex - 1 ) % CHOICE_Y_COUNT ) ) / CHOICE_Y_COUNT )

#define CHOICE_X( itemIndex ) 		( CHOICE_X_START + CHOICE_X_SPACING * CHOICE_COL( itemIndex ) )
#define CHOICE_Y( itemIndex ) 		( CHOICE_Y_START + CHOICE_Y_SPACING * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) )

#define CHOICE_ORIGIN( itemIndex )	CHOICE_X( itemIndex ) CHOICE_Y( itemIndex )

#define CHOICE_RECT( itemIndex )				CHOICE_ORIGIN( itemIndex ) 320 20 28 1 1

#define TITLE_RECT( x, y )			x y 344 28 1 1

// menu code work here.

#define CHOICE_MENU_TITLE( titleArg ) \
		CHOICE_MENU_TITLE_VIS( titleArg, 1 )

#define CHOICE_MENU_TITLE_VIS( titleArg, visArg ) \
		itemDef \
		{ \
			rect ORIGIN_TITLE \
			foreColor COLOR_TITLE \
			decoration  \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.5 \
			textFont 9 \
			text titleArg \
			visible visArg \
		}
#define CHOICE_SECTION_TITLE( titleArg, x, y ) \
		CHOICE_SECTION_TITLE_VIS( titleArg, x, y, 1 )	

#define CHOICE_SECTION_TITLE_VIS( titleArg, x, y, visArg ) \
		itemDef \
		{ \
				rect TITLE_RECT( x, y ) \
				foreColor 1 1 1 1 \
				decoration  \
				textAlign 5 \
				textScale 0.5 \
				textFont 9 \
				exp text ( titleArg ); \
				visible visArg \
		}
#define CHOICE_SEPARATOR( itemIndex ) \
		CHOICE_SEPARATOR_VIS( itemIndex, 1 )
		
#define CHOICE_SEPARATOR_VIS( itemIndex, visArg ) \
		itemDef \
		{ \
			rect CHOICE_SEP_OFFSET( itemIndex ) \
			style 3 \
			foreColor 1 1 1 0.65 \
			background "gradient_fadein" \
			decoration \
			textScale 0.55 \
			visible visArg \
		}
/*		
// needs fixing before used as it is broken and im lazy :p
#define CHOICE_SEPARATOR_ADV( itemIndex ) \
		CHOICE_SEPARATOR_VIS_ADV( itemIndex, 1 )

#define CHOICE_SEPARATOR_VIS_ADV( itemIndex, visArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) \
			style 3 \
			foreColor 1 1 1 0.65 \
			background "gradient_fadein" \
			decoration \
			textScale 0.55 \
			visible visArg \
		}	
*/		
#define CHOICE_BUTTON( itemIndex, textArg, actionArg ) \
		CHOICE_BUTTON_VIS( itemIndex, textArg, actionArg, 1 )

#define CHOICE_BUTTON_VIS( itemIndex, textArg, actionArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			foreColor COLOR_FOCUS \
			style 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 1 \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			onFocus \
			{ \
				play mouse_over; \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
				setLocalVarFloat "ui_popupYPos" ( getfocuseditemy( ) ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0 0 0 0.0; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play mouse_click; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_BUTTON_ADV( itemIndex, textArg, actionArg ) \
		CHOICE_BUTTON_VIS_ADV( itemIndex, textArg, actionArg, 1 )

#define CHOICE_BUTTON_VIS_ADV( itemIndex, textArg, actionArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 1 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_BUTTON_FOCUS( itemIndex, textArg, actionArg, onFocusArg, leaveFocusArg ) \
		CHOICE_BUTTON_FOCUS_VIS( itemIndex, textArg, actionArg, onFocusArg, leaveFocusArg, 1 )

#define CHOICE_BUTTON_FOCUS_VIS( itemIndex, textArg, actionArg, onFocusArg, leaveFocusArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 1 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}		
#define CHOICE_BUTTON_NOHI( itemIndex, textArg, actionArg ) \
		CHOICE_BUTTON_VIS_NOHI( itemIndex, textArg, actionArg, 1 )
		
#define CHOICE_BUTTON_VIS_NOHI( itemIndex, textArg, actionArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			foreColor COLOR_FOCUS \
			style 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 1 \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			exp text ( textArg ); \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self backColor 0 0 0 1; \
				setLocalVarBool ui_menuAButton ( 1 ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backColor 0 0 0 0.0; \
				setLocalVarBool ui_menuAButton ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_DBUTTON_NOHI( itemIndex, textArg ) \
		CHOICE_DBUTTON_VIS_NOHI( itemIndex, textArg, 1 )
	
#define CHOICE_DBUTTON_VIS_NOHI( itemIndex, textArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			foreColor COLOR_DISABLED \
			style 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 1 \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			exp text ( textArg ); \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self backColor 0 0 0 1; \
				setLocalVarBool ui_menuAButton ( 1 ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backColor 0 0 0 0.0; \
				setLocalVarBool ui_menuAButton ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_DBUTTON( itemIndex, textArg ) \
		CHOICE_DBUTTON_VIS( itemIndex, textArg, 1 )
	
#define CHOICE_DBUTTON_VIS( itemIndex, textArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			foreColor COLOR_DISABLED \
			style 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 0 \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			visible visArg \
			decoration \
		}
#define CHOICE_DVARENUMLIST( itemIndex, textArg, dvarArg, dvarListArg, actionArg ) \
		CHOICE_DVARENUMLIST_VIS( itemIndex, textArg, dvarArg, dvarListArg, actionArg, 1 )

#define CHOICE_DVARENUMLIST_VIS( itemIndex, textArg, dvarArg, dvarListArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 13 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			dvarEnumList dvarListArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_DVARENUMLIST_FOCUS( itemIndex, textArg, dvarArg, dvarListArg, onFocusArg, leaveFocusArg, actionArg ) \
		CHOICE_DVARENUMLIST_FOCUS_VIS( itemIndex, textArg, dvarArg, dvarListArg, onFocusArg, leaveFocusArg, actionArg, 1 )

#define CHOICE_DVARENUMLIST_FOCUS_VIS( itemIndex, textArg, dvarArg, dvarListArg, onFocusArg, leaveFocusArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 13 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			dvarEnumList dvarListArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
				onFocusArg \
			} \
			leaveFocus \
			{ \
				leaveFocusArg \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}		
// somewhat broken needs tons of text offset working :c
// well i think it does 
//e.g CHOICE_DVARLIST( 22, "@MENU_GAME_TYPE", "", 12, ownerDraw UI_NETGAMETYPE;  ) = broken alignment
#define CHOICE_DVARLIST( itemIndex, textArg, dvarArg, ItemTypeArg, listArg, actionArg ) \
		CHOICE_DVARLIST_VIS( itemIndex, textArg, dvarArg, ItemTypeArg, listArg, actionArg, 1 )

#define CHOICE_DVARLIST_VIS( itemIndex, textArg, dvarArg, ItemTypeArg, listArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type ItemTypeArg \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			listArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_DVARSTRINGLIST( itemIndex, textArg, dvarArg, strListArg, actionArg ) \
		CHOICE_DVARSTRINGLIST_VIS( itemIndex, textArg, dvarArg, strListArg, actionArg, 1 )

#define CHOICE_DVARSTRINGLIST_VIS( itemIndex, textArg, dvarArg, strListArg, actionArg, visArg ) \
		CHOICE_CAPTION_VIS( itemIndex, textArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 12 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			dvarStrList strListArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_DVARFLOATLIST( itemIndex, textArg, dvarArg, strListArg, actionArg ) \
		CHOICE_DVARFLOATLIST_VIS( itemIndex, textArg, dvarArg, strListArg, actionArg, 1 )
		
#define CHOICE_DVARFLOATLIST_VIS( itemIndex, textArg, dvarArg, strListArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 12 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			dvarStrList strListArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_DVAREDIT_NUMERIC( itemIndex, textArg, dvarArg, max_chars, actionArg ) \
		CHOICE_DVAREDIT_NUMERIC_VIS( itemIndex, textArg, dvarArg, max_chars, actionArg, 1 )
		
#define CHOICE_DVAREDIT_NUMERIC_VIS( itemIndex, textArg, dvarArg, max_chars, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 9 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text " " \
			dvar dvarArg \
			maxChars max_chars \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_DVAREDIT( itemIndex, textArg, dvarArg, actionArg ) \
		CHOICE_DVAREDIT_VIS( itemIndex, textArg, dvarArg, 31, 18, actionArg, 1 )
		
#define CHOICE_DVAREDIT_VIS( itemIndex, textArg, dvarArg, max_chars, max_paintchars, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 4 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text " " \
			dvar dvarArg \
			maxChars max_chars \
			maxPaintChars max_paintchars \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}
#define CHOICE_DVARSLIDER( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, actionArg ) \
		CHOICE_DVARSLIDER_VIS( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, actionArg, 1 )
		
#define CHOICE_DVARSLIDER_VIS( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			foreColor COLOR_FOCUS \
			type 10 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text " " \
			dvarFloat dvarArg defaultArg minArg maxArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_DVARSLIDER_FOCUS( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, onFocusArg, leaveFocusArg, actionArg ) \
		CHOICE_DVARSLIDER_FOCUS_VIS( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, onFocusArg, leaveFocusArg, actionArg, 1 )
		
#define CHOICE_DVARSLIDER_FOCUS_VIS( itemIndex, textArg, dvarArg, defaultArg, minArg, maxArg, onFocusArg, leaveFocusArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			foreColor COLOR_FOCUS \
			type 10 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text " " \
			dvarFloat dvarArg defaultArg minArg maxArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
				onFocusArg \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
				leaveFocusArg \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}		
#define CHOICE_DVARYESNO( itemIndex, textArg, dvarArg, actionArg ) \
		CHOICE_DVARYESNO_VIS( itemIndex, textArg, dvarArg, actionArg, 1 )

#define CHOICE_DVARYESNO_VIS( itemIndex, textArg, dvarArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 11 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_BIND( itemIndex, textArg, cmdArg, actionArg ) \
		CHOICE_BIND_VIS( itemIndex, textArg, cmdArg, actionArg, 1 )
		
#define CHOICE_BIND_VIS( itemIndex, textArg, cmdArg, actionArg, visArg ) \
		CHOICE_CAPTION( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			style 1 \
			foreColor COLOR_FOCUS \
			background "menu_setting_selection_bar" \
			type 14 \
			textAlign 4 \
			textAlignX 180 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			dvar dvarArg \
			onFocus \
			{ \
				play "mouse_over"; \
				show "keyBindStatus"; \
				setItemColor self "backcolor" 0 0 0 1; \
			} \
			leaveFocus \
			{ \
				hide "keyBindStatus"; \
				setItemColor self "backcolor" 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
			visible visArg \
		}

#define CHOICE_CAPTION( itemIndex, textArg ) \
		CHOICE_CAPTION_VIS( itemIndex, textArg, 1 )

#define CHOICE_CAPTION_VIS( itemIndex, textArg, visArg ) \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + CHOICE_CAPTION_OFFSET ) CHOICE_SIZE_Y 0 0 \
			foreColor COLOR_FOCUS \
			textAlign 6 \
			textAlignX -180 \
			textScale 0.375 \
			textFont 3 \
			exp text( textArg ); \
			visible visArg \
			decoration \
		}
#define CHOICE_SCRIPTS_ACTION( itemIndex, actionArg ) \
		CHOICE_SCRIPTS_ALL( itemIndex, actionArg, ;, ; )

#define CHOICE_SCRIPTS_ALL( itemIndex, actionArg, onFocusArg, leaveFocusArg ) \
		onFocus \
		{ \
			play mouse_over; \
			setLocalVarBool "ui_menuAButton" ( 1 ); \
			onFocusArg \
		} \
		leaveFocus \
		{ \
			setLocalVarBool "ui_menuAButton" ( 0 ); \
			leaveFocusArg \
		} \
		action \
		{ \
			play "mouse_click"; \
			actionArg \
		}
#define CHOICE_BACK( textArg, actionArg ) \
		CHOICE_BACK_VIS( textArg, actionArg, 1 )

#define CHOICE_BACK_VIS( textArg, actionArg, visArg ) \
		itemDef \
		{ \
			rect -64 -20 336 20 1 3 \
			style 1 \
			foreColor 1 1 1 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 1 \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			text textArg \
			visible visArg \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarString( "gameMode" ) != "mp"  ) \
				{ \
					setItemColor mw2_button "backColor" 0 0 0 0; \
				} \
				setItemColor self "backColor" 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
			} \
			leaveFocus \
			{ \
				setItemColor self "backColor" 0 0 0 "0.0"; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg; \
			} \
			visible when ( "@PLATFORM_BACK_CAPS" == "@PLATFORM_BACK_CAPS"  ) \
		}
		