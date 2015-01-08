#ifdef BG_LAYER_1
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			foreColor 0 0 0 0.4
			background "white"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarString( "gameMode" ) == "mp" && !dvarbool( "ui_multiplayer" ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 1
			background "mw2_main_background"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarInt( "cl_ingame" ) != 1 ); )
		}
		itemDef
		{
			rect 0 0 1708 480
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarInt( "cl_ingame" ) != 1 ); )
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds( ) % 60000 ) / 60000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect 0 0 -1708 -480
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarInt( "cl_ingame" ) != 1 ); )
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			foreColor 1 1 1 1
			background "mw2_main_mp_image"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarString( "gameMode" ) == "mp" && ( dvarInt( "cl_ingame" ) != 1 ); )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( "cl_ingame" ) != 1 ); )
			exp forecolor a ( ( ( sin milliseconds( ) / 1500 ) + 1 ) * 0.250000 ) + 0.250000 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( "cl_ingame" ) != 1 ); )
			exp forecolor a ( ( ( sin milliseconds( ) / 480 ) + 1 ) * 0.250000 ) + 0.250000 )
		}
		itemDef
		{
			rect -64 0 280 480 1 0
			style 3
			foreColor 1 1 1 0.1
			background "gradient_fadein_fadebottom"
			decoration 
			textScale 0.55
			visible 1
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 0.25 0.25 0.25 0.75
			background "gradient_fadein"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( "cl_ingame" ) != 1 ); )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 0.25 0.25 0.25 0.75
			background "gradient_fadein"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( "cl_ingame" ) != 1 ); )
		}
#endif
#ifdef BG_LAYER_1_INNER
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 0 0 0 1
			background "black"
			decoration 
			textScale 0.55
			visible 1
		}
		itemDef
		{
			rect 0 0 1708 480
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			visible 1
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds( ) % 60000 ) / 60000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect 0 0 -1708 -480
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			visible 1
			visible when ( 1  )
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			foreColor 1 1 1 1
			background "mw2_main_sp_image"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarString( "gameMode" ) == "sp" )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			foreColor 1 1 1 1
			background "mw2_main_co_image"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarString( "gameMode" ) == "so" )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			style 3
			foreColor 1 1 1 1
			background "mw2_main_mp_image"
			decoration 
			textScale 0.55
			visible 1
			visible when ( dvarString( "gameMode" ) == "mp" )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( cl_ingame ) != 1 ); )
			exp forecolor a ( ( ( sin milliseconds( ) / 1500 ) + 1 ) * 0.250000 ) + 0.250000 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			visible 1
			visible when ( ( dvarInt( cl_ingame ) != 1 ); )
			exp forecolor a ( ( ( sin milliseconds( ) / 480 ) + 1 ) * 0.250000 ) + 0.250000 )
		}
#endif		