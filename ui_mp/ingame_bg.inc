		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			foreColor 0 0 0 0.4
			background "white"
			textScale 0.55
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			textScale 0.55
			exp foreColor a ( ( ( sin( milliseconds( ) / 1500 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			decoration
			visible 1
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			textScale 0.55
			exp foreColor a ( ( ( sin( milliseconds( ) / 480 ) + 1 ) * 0.25 ) + 0.25 )
		}
#ifndef SIDE_BAR		
		itemDef
		{
			rect -64 0 280 480 1 0
			style 3
			decoration
			visible 1
			forecolor 0 0 0 0.25
			background "gradient_fadein_fadebottom"
			textscale 0.55
		}
#endif		