#ifndef ALT_PANEL
#define ALT_PANEL 0
#endif

#ifndef PC
	itemDef 	
	{ 
		style WINDOW_STYLE_SHADER 
		rect -120 0 420 38 0 0
		background "white" 
		forecolor 0.9 0.9 0.95 0.175 
		visible when( ENABLE_TITLE_BG ); 
		decoration 	
	}
	itemDef 	
	{ 
		style WINDOW_STYLE_SHADER 
		rect 300 0 16 -38 0 0 
		background HIGHLIGHT_SHADER_ART 
		forecolor 0.9 0.9 0.95 0.175 
		visible when( ENABLE_TITLE_BG );
		decoration	
	}
#endif

#ifdef PC

	#ifndef BACK_ENABLE
	#define BACK_ENABLE	1
	#endif

	#ifndef BACK_OPEN
	#define BACK_OPEN	open "main_text";
	#endif
	
	itemDef 
	{
		name back
		text "@MENU_BACK"
		type 1
		style WINDOW_STYLE_FILLED
		textstyle ITEM_TEXTSTYLE_SHADOWED
		rect -250 -26 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
		textfont UI_FONT_NORMAL
		textalign ITEM_ALIGN_LEFT
		textscale TEXTSIZE_SMALL
		textaligny 18
		visible when( BACK_ENABLE );
		mouseEnter 
		{ 
			play "mouse_over"; 
		}
		action 
		{
			play "mouse_click";
			close "self";
			BACK_OPEN
		}	
	}
	
#endif