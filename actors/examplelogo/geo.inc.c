#include "src/game/envfx_snow.h"

const GeoLayout examplelogo_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, examplelogo_DrawCall_48_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, examplelogo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
