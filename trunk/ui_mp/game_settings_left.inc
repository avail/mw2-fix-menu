//half pixels are GREAT - well, they seem to work here		

#define DVAR_LEFT(i) -272 ( 46 +( i * 18 ) ) 272 18 2 1
#define CAPTION_LEFT(i) -272 ( 46 +( i * 18 ) ) 260 18 2 1

#define CHOICE_DVARSTRINGLIST_L( itemIndex, textArg, actionArg, dvarArg, dvarListArg ) \
		CHOICE_CAPTION_L( itemIndex, textArg ) \
		itemDef \
		{ \
			type 12 \
			dvar dvarArg \
			dvarStrList dvarListArg \
			rect DVAR_LEFT( itemIndex ) \
			style 1 \
			foreColor 1 1 1 1 \
			background "menu_rules_selection_bar" \
			group "mw2_button" \
			textAlign 4 \
			textAlignX 160 \
			textAlignY -2 \
			textScale 0.375 \
			textFont 3 \
			visible 1 \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
				setLocalVarFloat "ui_popupYPos" ( getfocuseditemy( ) ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0 0 0 "0.0"; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
		}
#define CHOICE_CAPTION_L( itemIndex, textArg ) \
		itemDef \
		{ \
			rect CAPTION_LEFT( itemIndex ) \
			exp text( textArg ); \
			style 1 \
			foreColor 1 1 1 1 \
			background "white" \
			type 1 \
			textAlign 4 \
			textAlignY -2 \
			textScale 0.375 \
			textFont 3 \
			visible 1 \
		}
#define TITLE_1_L( textArg ) \
		itemDef \
		{ \
			rect -272 28 160 18 2 1 \
			style 1 \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textAlign 6 \
			textAlignX -32 \
			textScale 0.3333 \
			textFont 9 \
			exp text ( textArg ) \
		}
#define TITLE_2_L( textArg ) \
		itemDef \
		{ \
			rect -272 226 160 18 2 1 \
			style 1 \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textAlign 6 \
			textAlignX -32 \
			textScale 0.3333 \
			textFont 9 \
			exp text ( textArg ) \
		}