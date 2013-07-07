//---------------- stuff ----------------//
#include "ui_mp/game_settings_left.inc"
#include "ui_mp/game_settings_right.inc"

#define TITLE( textArg ) \
		itemDef \
		{ \ \
			rect 0 0 0 28 2 1 \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textfont 9 \
			textalign 5 \
			textalignx 5 \
			textscale 0.5 \
			exp text ( textArg ) \
		}
#define CHOICE_BACK_ESC( visArg ) \
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
			text "@PLATFORM_BACK_CAPS" \
			visible visArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" ( 1 ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0 0 0 0.0; \
				setLocalVarBool "ui_menuAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				escape "self"; \
			} \
		}
//---------------- background ----------------//
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			forecolor 1 1 1 1
			background "mw2_main_background"
			textscale 0.55
		}
		itemDef
		{
			rect 0 0 1708 480 0 0
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds( ) % 60000 ) / 60000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect 0 0 -1708 -480 0 0
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds( ) / 1500 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds( ) / 480 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect 0 28 640 162 4 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.15
			background "white"
			textscale 0.55
		}
		itemDef
		{
			rect -32 -4 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_tl"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 -4 640 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_t"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 -4 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_tr"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 28 32 162 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_r"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 190 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_br"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 190 640 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_b"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect -32 190 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_bl"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect -32 28 32 162 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_l"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 226 640 144 4 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.15
			background "white"
			textscale 0.55
		}
		itemDef
		{
			rect -32 194 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_tl"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 194 640 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_t"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 194 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_tr"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 226 32 144 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_r"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 640 370 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_br"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 370 640 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_b"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect -32 370 32 32 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_bl"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect -32 226 32 144 4 1
			style 3
			decoration
			visible 1
			forecolor 0 0 0 1
			background "drop_shadow_l"
			textscale 0.55
			visible when ( 1 )
		}		