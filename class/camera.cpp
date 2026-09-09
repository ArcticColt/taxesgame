#include <png/png.h>

#include "camera.h"
#include "../game.h"
#include "../romdisk/asset/texture/textureList.h"

Camera::Camera()
{
    x = 0;
    y = 0;
    hpos = 0;
    vpos = 0;
    wid = 320.0f;
    hig = 240.0f;
}

void Camera::draw()
{
    for (drawStruct tex : drawList){
        //test left boundary
        //if ((tex.x + tex.width))
        _draw_texture(tex.texture, tex.x - int(x) + hpos, tex.y - int(y) + vpos, tex.depth, tex.width, tex.height, tex.u, tex.v, tex.uwid, tex.vhig);
    }
}

void Camera::_draw_texture(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig){
    TextureList texstruct = textureMeta[texture];

    pvr_poly_cxt_t cxt;
    pvr_poly_hdr_t hdr;
    pvr_vertex_t vert;

    pvr_ptr_t tex = textures[textureMeta[texture].name];

    pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, PVR_TXRFMT_ARGB1555, texstruct.width, texstruct.height, tex, PVR_FILTER_NEAREST);
    
    pvr_poly_compile(&hdr, &cxt);
    pvr_prim(&hdr, sizeof(hdr));

    vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
    vert.oargb = 0;
    vert.flags = PVR_CMD_VERTEX;

    vert.x = x;
    vert.y = y;
    vert.z = depth;
    vert.u = u;
    vert.v = v;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x+width;
    vert.y = y;
    vert.z = depth;
    vert.u = u + uwid;
    vert.v = v;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x;
    vert.y = y+height;
    vert.z = depth;
    vert.u = u;
    vert.v = v + vhig;
    pvr_prim(&vert, sizeof(vert));

    vert.x = x+width;
    vert.y = y+height;
    vert.z = depth;
    vert.u = u + uwid;
    vert.v = v + vhig;
    vert.flags = PVR_CMD_VERTEX_EOL;
    pvr_prim(&vert, sizeof(vert));
}