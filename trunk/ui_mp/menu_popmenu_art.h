//	PLAYERCARD2(0, 1, 3, 1, -274, 18)
// -1004 -564 1708 960 2 2
#define POPMENU( nameArg, X, Y, Z ) \
		name nameArg \
   		fullscreen 0 \
		rect 0 0 0 84 2 2 \
		focusColor 1 1 1 1 \
   		style 1 \
		popup \
		onESC \
		{ \
			close "self"; \
		} \
		itemDef \
		{ \
			rect X Y 1708 Z 2 2 \
			style 1 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0.35 \
			background "white" \
			decoration \
			textScale 0.55 \
			visible 1 \
		} \
		itemDef \
		{ \
			rect -1004 -564 1708 960 2 2 \
			style 1 \
			foreColor 1 1 1 1 \
			backColor 1 1 1 1 \
			background "xpbar_stencilbase" \
			decoration \
			textScale 0.55 \
			visible 1 \
		} \
		itemDef \
		{ \
			rect X Y 300 Z 2 2 \
			style 1 \
			foreColor 1 1 1 1 \
			backColor 0.5 0.5 0.5 1 \
			background "white" \
			decoration \
			textScale 0.55 \
			visible 1 \
		}