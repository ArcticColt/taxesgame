//THE WHOLE TOWN DIDN'T PAY THEIR TAXES


#include <kos.h>
#include <png/png.h>

#include <string>
#include <vector>

// #region class
#include "class/drawable.h"
#include "class/entity.h"
#include "class/player.h"
#include "romdisk/asset/texture/textureList.h"
// #endregion

pvr_ptr_t tex;
std::vector<Drawable*> globalDrawList;

void load_texture(std::string texture){
    TextureList texstruct = textures[texture];
    tex = pvr_mem_malloc(texstruct.width * texstruct.height * 2);
    png_to_texture(texstruct.path, tex, texstruct.alphaType);
}

void draw_sprite(const char* texture, float x, float y, float depth){
    TextureList texstruct = textures[texture];

    pvr_poly_cxt_t cxt;
    pvr_poly_hdr_t hdr;
    pvr_vertex_t vert;

    int width = texstruct.width;
    int height = texstruct.height;

    pvr_poly_cxt_txr(&cxt, PVR_LIST_OP_POLY, texstruct.format, width, height, tex, PVR_FILTER_NEAREST);
    pvr_poly_compile(&hdr, &cxt);
    pvr_prim(&hdr, sizeof(hdr));

    float w = float(width);
    float h = float(height);

    vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
    vert.oargb = 0;
    vert.flags = PVR_CMD_VERTEX;

    vert.x = x;
    vert.y = y;
    vert.z = depth;
    vert.u = 0.0f;
    vert.v = 0.0f;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x+w;
    vert.y = y;
    vert.z = depth;
    vert.u = 1.0f;
    vert.v = 0.0f;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x;
    vert.y = y+h;
    vert.z = depth;
    vert.u = 0.0f;
    vert.v = 1.0f;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x+w;
    vert.y = y+h;
    vert.z = depth;
    vert.u = 1.0f;
    vert.v = 1.0f;
    vert.flags = PVR_CMD_VERTEX_EOL;
    pvr_prim(&vert, sizeof(vert));
}

void init_level(){
    Player *P1 = new Player();
}

int main(){
    pvr_init_defaults();
    load_texture("koffiaRun");
    init_level();
    while(true)
    {
        pvr_wait_ready();
        pvr_scene_begin();

        pvr_list_begin(PVR_LIST_OP_POLY);

        //main draw
        for (Drawable* drawable : globalDrawList)
            drawable->draw();

        pvr_list_finish();
        pvr_scene_finish();
    }
    return 0;
}