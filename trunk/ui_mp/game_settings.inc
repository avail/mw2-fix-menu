//half pixels are GREAT - well, they seem to work here		
//#define CHOICE_Y(i) ( 28 + ( i * 20 ) )
//#define CHOICE_ORIGIN(i) -64 CHOICE_Y(i)
//#define CHOICE_RECT(i) CHOICE_ORIGIN(i) 336 20 1 1

//#define SETTING_DVAR_LEFT(i) -272 ( 46 +( i * 18 ) ) 272 18 2 1
//#define SETTING_DVAR_RIGHT(i) 0 ( 46 +( i * 18 ) ) 160 18 2 1

#define SETTING_LEFT(i) -272 ( 46 +( i * 18 ) ) 260 18 2 1
#define SETTING_RIGHT(i) 0 ( 46 +( i * 18 ) ) 260 18 2 1

#define SETTING_TEXT_LEFT( itemIndex, textArg, dvarArg, actionArg ) \
		itemDef \
		{ \
			rect SETTING_LEFT( itemIndex ) \
			dvar dvarArg \
			foreColor 1 1 1 1 \
			style 1 \
			background "menu_rules_selection_bar" \
			group "mw2_button" \
			type 1 \
			textFont 3 \
			textAlign 4 \
			textAlignX 0 \
			textAlignY -2 \
			textScale 0.375 \
			text textArg \
			visible 1 \
			onFocus \
			{ \
				play mouse_over; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_button" backcolor 0 0 0 0; \
				} \
				setItemColor self "backColor" 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
				setLocalVarFloat "ui_popupYPos" ( getfocuseditemy() ); \
			} \
			leaveFocus \
			{ \
				setItemColor self "backColor" 0 0 0 0.0; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
		}
#define SETTING_TEXT_RIGHT( itemIndex, textArg, dvarArg, actionArg ) \
		itemDef \
		{ \
			rect SETTING_DVAR_RIGHT( itemIndex ) \
			dvar dvarArg \
			foreColor 1 1 1 1 \
			style 1 \
			background "menu_rules_selection_bar" \
			group "mw2_button" \
			type 1 \
			textFont 3 \
			textAlign 4 \
			textAlignX 0 \
			textAlignY -2 \
			textScale 0.375 \
			text textArg \
			visible 1 \
			onFocus \
			{ \
				play mouse_over; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_button" backcolor 0 0 0 0; \
				} \
				setItemColor self "backColor" 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
				setLocalVarFloat "ui_popupYPos" ( getfocuseditemy() ); \
			} \
			leaveFocus \
			{ \
				setItemColor self "backColor" 0 0 0 0.0; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
		}		