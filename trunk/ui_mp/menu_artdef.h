#include "ui/menudefinition.h"

#define COLOR_TITLE			1 1 1 1
#define COLOR_FOCUS			1 1 1 1
#define COLOR_DISABLED		0.6 0.55 0.55 1

#define FULLSCREEN			0 0 640 480
#define FULLSCREEN_WIDE		-107 0 854 480

#define ORIGIN_TITLE		0 0 272 28 1 1

#define LOCAL_EXEC \
		setDvar "onlinegame" 1; \
		setDvar "ui_mptype" 0; \
		setDvar "systemlink" 0; \
		setDvar "splitscreen" 0; \
		exec "xrequirelivesignin"; \
		exec "exec default_xboxlive.cfg"; \
		exec "party_maxplayers 18"; \
		exec "xblive_privatematch 0"; \
		exec "xblive_rankedmatch 0"; \
		exec "xstartprivateparty"; \
		exec "xcheckezpatch"; \
		exec "exec default_xboxlive.cfg"; \
		exec "exec xblive_rankedmatch 0"; \
		exec "ui_enumeratesaved"; \
		exec "xblive_privatematch 1"; \
		exec "xstartprivatematch"; \
		open "menu_xboxlive_privatelobby";