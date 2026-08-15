//THE WHOLE TOWN DIDN'T PAY THEIR TAXES


#include <kos.h>
#include <png/png.h>

#include <string>
#include <vector>
#include <unordered_map>

// #region class
#include "class/drawable.h"
#include "class/entity.h"
#include "class/player.h"
#include "class/enemy.h"
#include "romdisk/asset/texture/textureList.h"
// #endregion

uint32_t vramUsage = 0;
uint32_t vramUsageMax = 1572864;

std::unordered_map<std::string, pvr_ptr_t> textures = {};

std::vector<Drawable*> globalDrawList;
std::vector<Entity*> globalUpdateList;

uint8_t load_texture(std::string texture){
    TextureList texstruct = textureMeta[texture];
    uint32_t vramTest = (texstruct.width * texstruct.height) * 2;
    if ((vramUsage + vramTest) <= vramUsageMax)
    {
        //make new texture
        pvr_ptr_t tex;
        //alocate space for it
        tex = pvr_mem_malloc(texstruct.width * texstruct.height * 2);
        png_to_texture(texstruct.path, tex, texstruct.alphaType);
        //put tex in texture list
        textures[texture] = tex;
        vramUsage += vramTest;
        return 0;
    }
    else
    return 2;
}

void draw_sprite(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig){
    TextureList texstruct = textureMeta[texture];

    pvr_poly_cxt_t cxt;
    pvr_poly_hdr_t hdr;
    pvr_vertex_t vert;

    pvr_ptr_t tex = textures[textureMeta[texture].name];

    pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, texstruct.format, texstruct.width, texstruct.height, tex, PVR_FILTER_NEAREST);
    
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

void init_level(){
    Player *P1 = new Player();
    Enemy *enemy = new Enemy();
}

int main(){
    pvr_init_defaults();
    load_texture("koffiaRun");
    load_texture("sylveon");
    init_level();
    while(true)
    {

        //run Update()
        for (Entity* entity : globalUpdateList)
            entity->update();

        pvr_wait_ready();
        pvr_scene_begin();

        pvr_list_begin(PVR_LIST_TR_POLY);

        //main draw
        for (Drawable* drawable : globalDrawList)
            drawable->draw();

        pvr_list_finish();
        pvr_scene_finish();
    }
    return 0;
}