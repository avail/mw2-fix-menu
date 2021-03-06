//half pixels are GREAT - well, they seem to work here		
#define CHOICE_Y(i) ( 28 + ( i * 20 ) )
#define CHOICE_ORIGIN(i) -64 CHOICE_Y(i)
#define CHOICE_RECT(i) CHOICE_ORIGIN(i) 336 20 1 1
#define HR_ORIGIN(i) 0 ( CHOICE_Y(i) - 0 )
#define HR_RECT(i) HR_ORIGIN(i) 216 1 1 1

#define GAMETYPE_BUTTON( itemIndex, textArg, actionArg, namex, desc ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			foreColor 1 1 1 1 \
			style 1 \
			background "menu_button_selection_bar" \
			group "mw2_button" \
			type 1 \
			autoWrapped \
			textAlign 6 \
			textAlignX -60 \
			textScale 0.375 \
			textFont 3 \
			text textArg  \
			visible 1 \
			onFocus \
			{ \
				play mouse_over; \
				setItemColor self "backColor" 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
				setLocalVarFloat ui_popupYPos 0.000000; \
				setLocalVarString "ui_info_name" ( namex ); \
				setLocalVarString "ui_info_desc" ( desc ); \
			} \
			leaveFocus \
			{ \
				setItemColor self "backColor" 0 0 0 0.0; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
				setLocalVarString "ui_info_name" ( "" ); \
				setLocalVarString "ui_info_desc" ( "" ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				execOnDvarIntValue "xblive_privatematch" 1 "exec default_xboxlive.cfg"; \
				actionArg \
			} \
		}	
#define CHOICE_SEPERATOR( itemIndex ) \
		itemDef \
		{ \
			rect HR_RECT( itemIndex ) \
			style 3 \
			foreColor 1 1 1 0.65 \
			background "gradient_fadein" \
			decoration \
			textScale 0.55 \
			visible 1 \
		}