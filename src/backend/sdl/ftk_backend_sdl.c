
#include "ftk_bitmap_factory.h"
#include "ftk_image_sdl_decoder.h"
#include "ftk_display_sdl.h"
#include "ftk_source_sdl.h"
#include "ftk_globals.h"
#include "ftk_backend.h"

Ret ftk_backend_init(int argc, char* argv[])
{
	FtkSource* source = NULL;
	FtkDisplay* display = NULL;

	ftk_bitmap_factory_add_decoder(ftk_default_bitmap_factory(), ftk_image_sdl_decoder_create());

	display = ftk_display_sdl_create();
	ftk_set_display(display);

	source = ftk_source_sdl_create();
	ftk_sources_manager_add(ftk_default_sources_manager(), source);

	return display != NULL ? RET_OK : RET_FAIL;
}
