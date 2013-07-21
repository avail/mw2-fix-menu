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
			rect -875.258 0 1708 480 0 0
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
			rect -893.09 0 -1708 -480 0 0
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) )
		}
#ifdef DO_THE_CHICKEN_WING
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			decoration
			forecolor 1 1 1 1
			background "mw2_main_sp_image"
			textscale 0.55
			visible 1
		}	
#endif
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.25674
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
			forecolor 1 1 1 0.252388
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds( ) / 480 ) + 1 ) * 0.25 ) + 0.25 )
		}
#ifndef DONT_DO_THE_SIDEBAR_THINGY
		itemDef
		{
			rect -64 0 280 480 1 0
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.1
			background "gradient_fadein_fadebottom"
			textscale 0.55
		}
#endif