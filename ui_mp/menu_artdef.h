#include "ui/menudefinition.h"

#define COLOR_TITLE 1 1 1 1
#define COLOR_FOCUS 1 1 1 1
#define COLOR_DISABLED 0.6 0.55 0.55 1

#define FULLSCREEN 0 0 640 480
#define FULLSCREEN_WIDE -107 0 854 480

#define ORIGIN_TITLE 0 0 272 28 1 1

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

#define OPTIONS_LOCAL_CLOSE \
		close "pc_options_audio"; \
		close "pc_options_voice"; \
		close "pc_options_video"; \
		close "pc_options_adanced_video"; \
		close "pc_options_movement"; \
		close "pc_options_controls"; \
		close "options_graphics"; \
		close "options_multi"; \
		close "options_graphics_defaults"; \
		close "options_graphics_texture"; \
		close "options_control_defaults"; \
		close "options_voice"; \
		close "options_multi"; \
		close "controls_multi"; \
		close "main_options"; \
		close "main_controls"; \
		close "pc_options_audio"; \
		close "pc_options_video";
		
// string list defined for buttons.
// 12/14 languages listed

// graphic settings stuff
#define ASPECT_RATIO_STRLIST { "@MENU_AUTO"; "auto"; "@MENU_STANDARD_4_3"; "standard"; "@MENU_WIDE_16_10"; "wide 16:10"; "@MENU_WIDE_16_9"; "wide 16:9" }
#define AA_STRLIST { "@MENU_OFF"; "1"; "@MENU_2X"; "2"; "@MENU_4X"; "4" }
#define DLIGHT_STR { "@MENU_OFF"; "0"; "@MENU_LOW"; "2"; "@MENU_NORMAL"; "4" }
#define ZFEATHER_STR { "@MENU_NO"; "0"; "@MENU_YES"; "1" }
#define MDL_DETAIL_STR { "@MENU_NORMAL"; "1"; "@MENU_LOW"; "2" }
#define WTR_DETAIL_STR { "@MENU_NORMAL"; "1"; "@MENU_LOW"; "0" }

// graphic textures stuff
#define TEXTURE_MM_STRLIST { "@MENU_AUTOMATIC"; "Unchanged"; "@MENU_BILINEAR"; "Force Bilinear"; "@MENU_TRILINEAR"; "Force Trilinear" }
#define TEXTURE_QUALITY { "@MENU_AUTOMATIC"; "0"; "@MENU_MANUAL"; "1" }
#define TEXTURE_RESOLUTION { "@MENU_LOW"; "3"; "@MENU_NORMAL"; "2"; "@MENU_HIGH"; "1"; "@MENU_EXTRA"; "0" }

// sound stuff
#define SOUND_EQ_STR { "@MENU_OFF"; "0"; "@MENU_ON"; "1" }
#define SOUND_QUALITY_STR { "@MENU_11KHZ"; "11"; "@MENU_22KHZ"; "22"; "@MENU_44KHZ"; "44" }
#define SOUND_CONFIG_STR { "@MENU_WINDOWS_DEFAULT"; "Windows Default"; "@MENU_MONO"; "Mono"; "@MENU_STEREO"; "Stereo"; "@MENU_FOUR_SPEAKERS"; "4 Speakers"; "@MENU_FIVE_ONE_SPEAKERS"; "5.1 Speakers" }

// game options stuff
#define ENABLE_CONSOLE_STRLIST { "@MENU_YES"; "0"; "@MENU_NO"; "1" }
#define LANG_STRLIST { "@MENU_ENGLISH"; "0"; "@MENU_FRENCH"; "1"; "@MENU_GERMAN"; "2"; "@MENU_ITALIAN"; "3"; "@MENU_SPANISH"; "4"; "@MENU_BRITISH"; "5"; "@MENU_RUSSIAN"; "6"; "@MENU_POLISH"; "7" "@MENU_KOREAN"; "8"; "@MENU_TAIWANESE"; "9"; "@MENU_JAPANESE"; "10"; "@MENU_CHINESE"; "11" "@MENU_THAI"; "12" }

// Voice
#define VOICE_STR { "@MENU_NO"; "1"; "@MENU_YES"; "0" }
