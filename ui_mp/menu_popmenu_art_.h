// Assumes that "choices_setup_common" has already been included

#ifndef CHOICE_POPUP_BORDER_X
#define CHOICE_POPUP_BORDER_X 19
#endif

#ifndef CHOICE_POPUP_BORDER_Y
#define CHOICE_POPUP_BORDER_Y 20
#endif

#ifndef CHOICE_POPUP_TITLE_WIDTH
#define CHOICE_POPUP_TITLE_WIDTH 0
#endif

#ifndef CHOICE_POPUP_TITLE_HEIGHT
#define CHOICE_POPUP_TITLE_HEIGHT 0
#endif

#ifndef CHOICE_POPUP_TITLE_TEXTSIZE
#define CHOICE_POPUP_TITLE_TEXTSIZE	TEXTSIZE_DEFAULT
#endif

#ifndef CHOICE_POPUP_SUBTITLE_HEIGHT
#define CHOICE_POPUP_SUBTITLE_HEIGHT 0
#endif

#ifndef CHOICE_POPUP_SUBTITLE_TEXTSIZE
#define CHOICE_POPUP_SUBTITLE_TEXTSIZE TEXTSIZE_SMALL
#endif

#ifndef CENTER_POPUP_ON_CLOSE
#define CENTER_POPUP_ON_CLOSE play "mouse_click"; 
#endif

#ifndef CHOICE_POPUP_BORDER_WIDTH
#define CHOICE_POPUP_BORDER_WIDTH 2
#endif

#ifndef CHOICE_POPUP_BORDER_COLOR
#define CHOICE_POPUP_BORDER_COLOR 1 1 1 0.5
#endif

#ifndef CHOICE_POPUP_BACKCOLOR
#define CHOICE_POPUP_BACKCOLOR 0.2 0.2 0.22 1
#endif

#ifndef CHOICE_POPUP_BACKCOLOR_NOALPHA
#define CHOICE_POPUP_BACKCOLOR_NOALPHA 0.1412 0.1412 0.1812
#endif

#define CHOICE_POPUP_WIDTH ( ( CHOICE_POPUP_BORDER_X * 2 ) + ( ( CHOICE_POPUP_TITLE_WIDTH > CHOICE_SIZE_X ) ? CHOICE_POPUP_TITLE_WIDTH : CHOICE_SIZE_X ) )
#define CHOICE_POPUP_HEIGHT( itemCount ) ( CHOICE_POPUP_TITLE_HEIGHT + CHOICE_POPUP_SUBTITLE_HEIGHT + ( CHOICE_Y_SPACING * ( itemCount ) + CHOICE_POPUP_BORDER_Y * 2 ) )

#define CHOICE_POPMENU_SETUP( nameArg, itemCount, xArg, yArg, onEscArg ) \
		CHOICE_POPMENU_SETUP_ONOPEN( nameArg, itemCount, xArg, yArg, onEscArg, focusfirst )

#define CHOICE_POPMENU_SETUP_ONOPEN( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg ) \
		CHOICE_POPMENU_SETUP_ONOPEN_EX( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg, ; )


#define CHOICE_POPMENU_SETUP_ONOPEN_EX( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg, extraArgs ) \
		name nameArg \
   		fullscreen 0 \
		rect ( xArg + 1 ) ( yArg + 1 ) CHOICE_POPUP_WIDTH CHOICE_POPUP_HEIGHT( itemCount ) CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
		backcolor CHOICE_POPUP_BACKCOLOR \
		border 1 \
		bordersize CHOICE_POPUP_BORDER_WIDTH \
		bordercolor CHOICE_POPUP_BORDER_COLOR \
		focusColor COLOR_FOCUSED \
   		style WINDOW_STYLE_FILLED \
		popup \
		extraArgs \
		onOpen \
		{ \
			onOpenArg; \
		} \
		onESC \
		{ \
			play "mouse_click"; \
			close "self"; \
			onEscArg; \
		}

#define CHOICE_POPMENU_TITLE( textArg ) \
		CHOICE_POPMENU_TITLE_VIS( textArg, 1 )
		
#define CHOICE_POPMENU_TITLE_VIS( textArg, visArg ) \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect ( ( CHOICE_POPUP_WIDTH - CHOICE_POPUP_TITLE_WIDTH ) / 2 ) ( CHOICE_POPUP_BORDER_Y / 2 ) CHOICE_POPUP_TITLE_WIDTH CHOICE_POPUP_TITLE_HEIGHT CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			exp text(textArg); \
			textfont UI_FONT_NORMAL \
			textscale CHOICE_POPUP_TITLE_TEXTSIZE \
			textAlign ITEM_ALIGN_TOP_CENTER \
			textstyle CHOICE_TEXTSTYLE \
			forecolor CHOICE_TEXTCOLOR \
			visible visArg \
			decoration \
		}

#define CHOICE_POPMENU_SUBTITLE( textArg ) \
		CHOICE_POPMENU_SUBTITLE_VIS( textArg, 1 )
		
#define CHOICE_POPMENU_SUBTITLE_VIS( textArg, visArg ) \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect CHOICE_POPUP_BORDER_X ( CHOICE_POPUP_BORDER_Y + CHOICE_POPUP_TITLE_HEIGHT ) ( CHOICE_POPUP_WIDTH - ( CHOICE_POPUP_BORDER_Y * 2 ) ) CHOICE_POPUP_SUBTITLE_HEIGHT CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			exp text( textArg ); \
			textfont UI_FONT_NORMAL \
			textscale CHOICE_POPUP_SUBTITLE_TEXTSIZE \
			textAlign ITEM_ALIGN_TOP_LEFT \
			textstyle CHOICE_TEXTSTYLE \
			forecolor CHOICE_TEXTCOLOR \
			visible visArg \
			decoration \
			autowrapped \
		}
#define PREPROC_CANCEL_OVERLAY( shadow_visArg, itemCount ) \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect -600 -800 2000 2000 0 0 \
			text "" \
			textfont UI_FONT_NORMAL \
			visible 1 \
			onFocus \
			{ \
				setDvar "ui_popup_close_icon" ( 1 ); \
			} \
			leaveFocus \
			{ \
				setDvar "ui_popup_close_icon" ( 0 ); \
			} \
			action \
			{ \
				close "self"; \
			} \
		} \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect -4 -4 CHOICE_POPUP_WIDTH CHOICE_POPUP_HEIGHT( itemCount ) 0 0 \
			textfont UI_FONT_NORMAL \
			visible 1 \
			action \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect -600 -800 2000 2000 0 0 \
			forecolor 0 0 0 0.275 \
			exp material( "white" ); \
			visible when( shadow_visArg ); \
			decoration \
		}				
#define IMPROVED_POPUP_SETUP( nameArg, itemCount, xArg, yArg, onEscArg, shadow_visArg ) \
		IMPROVED_POPUP_SETUP_ONOPEN( nameArg, itemCount, xArg, yArg, onEscArg, focusfirst, shadow_visArg )

#define IMPROVED_POPUP_SETUP_ONOPEN( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg, shadow_visArg ) \
		IMPROVED_POPUP_SETUP_RAW( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg, ;, shadow_visArg )

#define IMPROVED_POPUP_SETUP_RAW( nameArg, itemCount, xArg, yArg, onEscArg, onOpenArg, extraArgs, shadow_visArg ) \
		name nameArg \
    	visible 0 \
   		fullscreen 0 \
		rect ( xArg + 0 ) ( yArg + 56 ) CHOICE_POPUP_WIDTH CHOICE_POPUP_HEIGHT( itemCount ) CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
		tokenReplacement \
		border 1 \
		bordersize CHOICE_POPUP_BORDER_WIDTH \
		bordercolor 0 0 0 0 \
		focusColor COLOR_FOCUSED \
   		style WINDOW_STYLE_FILLED \
		popup \
		extraArgs \
		onOpen \
		{ \
			onOpenArg; \
		} \
		onESC \
		{ \
			play "mouse_click"; \
			close "self"; \
			onEscArg; \
		}\
		PREPROC_CANCEL_OVERLAY( shadow_visArg, itemCount ) \
		PREPROC_SHADER_DRAW( -4 -4 CHOICE_POPUP_WIDTH CHOICE_POPUP_HEIGHT( itemCount ), 0 0, "white", CHOICE_POPUP_BACKCOLOR, 1, CHOICE_POPUP_BORDER_WIDTH, CHOICE_POPUP_BORDER_COLOR )
		
#define CENTER_POPUP_SETUP( nameArg, itemCount, onEscArg, shadow_visArg ) \
		CENTER_POPUP_SETUP_ONOPEN( nameArg, itemCount, onEscArg, focusfirst, shadow_visArg )

#define CENTER_POPUP_SETUP_ONOPEN( nameArg, itemCount, onEscArg, onOpenArg, shadow_visArg ) \
		CENTER_POPUP_SETUP_RAW( nameArg, itemCount, onEscArg, onOpenArg, ;, shadow_visArg )

#define CENTER_POPUP_SETUP_RAW( nameArg, itemCount, onEscArg, onOpenArg, extraArgs, shadow_visArg ) \
		name nameArg \
	   	fullscreen 0 \
		rect ( 0 - ( CHOICE_POPUP_WIDTH / 2 ) ) ( 0 - ( CHOICE_POPUP_HEIGHT( itemCount ) / 2 ) ) CHOICE_POPUP_WIDTH CHOICE_POPUP_HEIGHT( itemCount ) HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
		tokenReplacement \
		border 1 \
		backcolor 0 0 0 0 \
		bordersize CHOICE_POPUP_BORDER_WIDTH \
		bordercolor CHOICE_POPUP_BORDER_COLOR \
		focusColor COLOR_FOCUSED \
	   	style WINDOW_STYLE_FILLED \
		popup \
		extraArgs \
		onOpen \
		{ \
			setLocalVarBool	"ui_centerPopup" ( 1 ); \
			onOpenArg; \
		} \
		onClose \
		{ \
			CENTER_POPUP_ON_CLOSE \
			setLocalVarBool	"ui_centerPopup" ( 0 ); \
		} \
		onESC \
		{ \
			setLocalVarBool	"ui_centerPopup" ( 0 ); \
			close "self"; \
			onEscArg; \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect 0 0 ( CHOICE_POPUP_WIDTH - ( CHOICE_POPUP_BORDER_WIDTH * 2 ) ) ( CHOICE_POPUP_HEIGHT( itemCount ) - ( CHOICE_POPUP_BORDER_WIDTH * 2 ) ) HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			background "white" \
			forecolor CHOICE_POPUP_BACKCOLOR \
			visible 1 \
			decoration \
		}