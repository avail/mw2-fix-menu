#include "ui/menudefinition.h"

#define DEF_MP_CFG		"default_mp.cfg"
#define SS_MP_CFG		"default_splitscreen.cfg"
#define SL_MP_CFG		"default_systemlink.cfg"
#define XBL_MP_CFG		"default_xboxlive.cfg"

#define MAX_RANK		int( tableLookup( "mp/rankTable.csv", 0, "maxrank", 1 ) )
#define MAX_PRESTIGE	int( tableLookup( "mp/rankIconTable.csv", 0, "maxprestige", 1 ) )

#define PRESTIGE_AVAIL 	( stat( 2326 ) < MAX_PRESTIGE && stat( 2301 ) == int( tableLookup("mp/rankTable.csv", 0, MAX_RANK, 7 ) ) )
#define PRESTIGE_NEXT 	( stat( 2326 ) < MAX_PRESTIGE && stat( 252 ) == MAX_RANK )
#define PRESTIGE_FINISH ( stat( 2326 ) == MAX_PRESTIGE)

#define CAN_RANK_UP	( stat( 252 ) < MAX_RANK || stat( 2326 ) < MAX_PRESTIGE )

#define MAIN_EXEC \
		setdvar "systemlink" 0; \
		setdvar "splitscreen" 0; \
		setdvar "onlinegame" 1; \
		setdvar "ui_mptype" 0;	 \
		exec "xrequirelivesignin"; \
		exec "exec default_xboxlive.cfg"; \
		exec "party_maxplayers 18"; \
		exec "xblive_privatematch 0"; \
		exec "xblive_rankedmatch 0"; \
		exec "xstartprivateparty"; \
		exec "xcheckezpatch"; \
		exec "exec default_xboxlive.cfg" \
		exec "exec xblive_rankedmatch 0"; \
		exec "ui_enumeratesaved"; \
		exec "xblive_privatematch 1"; \
		exec "xstartprivatematch"; \
		open "menu_xboxlive_privatelobby"; \