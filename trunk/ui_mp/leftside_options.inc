#include "ui_mp/menu_art.h"

CHOICE_BUTTON_VIS( 1, "@MENU_GRAPHICS", open "pc_options_video"; close "main_options"; close "pc_options_advanced_video"; close "pc_options_audio"; close "pc_options_controls"; close "pc_options_voice", when( !( dvarInt( "sv_running" ) || dvarInt( "cl_ingame" ) ) ) )
CHOICE_DBUTTON_VIS( 1, "@MENU_GRAPHICS", when( ( dvarInt( "sv_running" ) && dvarInt( "cl_ingame" ) == 1 ) ) ) )

CHOICE_BUTTON_VIS( 2, "@MENU_TEXTURE_SETTINGS", open "pc_options_advanced_video"; close "main_options"; close "pc_options_video"; close "pc_options_audio"; close "pc_options_controls"; close "pc_options_voice", when( !( dvarInt( "sv_running" ) || dvarInt( "cl_ingame" ) ) ) )
CHOICE_DBUTTON_VIS( 2, "@MENU_TEXTURE_SETTINGS", when( ( dvarInt( "sv_running" ) && dvarInt( "cl_ingame" ) == 1 ) ) ) )

CHOICE_BUTTON( 3, "@MENU_AUDIO", open "pc_options_audio"; close "pc_options_video"; close "main_options"; close "pc_options_advanced_video"; close "pc_options_controls"; close "pc_options_voice"; )
CHOICE_BUTTON( 4, "@MENU_CONTROLS", open "pc_options_controls"; close "pc_options_video"; close "main_options"; close "pc_options_advanced_video"; close "pc_options_audio"; close "pc_options_voice";  )

CHOICE_BUTTON_VIS( 5, "@MENU_VOICE", open "pc_options_voice"; close "pc_options_video"; close "main_options"; close "pc_options_advanced_video"; close "pc_options_audio"; close "pc_options_controls", when( dvarInt( "ui_multiplayer" ) ) ) )
CHOICE_DBUTTON_VIS( 5, "@MENU_VOICE", when( !dvarInt( "ui_multiplayer" ) ) ) )

CHOICE_SEPARATOR( 6 )

CHOICE_BUTTON_VIS( 6, "@MENU_RESET_SYSTEM_DEFAULTS", open "options_graphics_defaults", when( !( dvarInt( "sv_running" ) || dvarInt( "cl_ingame" ) ) ) )
CHOICE_DBUTTON_VIS( 6, "@MENU_RESET_SYSTEM_DEFAULTS", when( ( dvarInt( "sv_running" ) && dvarInt( "cl_ingame" ) == 1 ) ) ) )

