#include "src/game/envfx_snow.h"

const GeoLayout title_player_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, title_player_platform_PLATFORM_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, title_player_platform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
