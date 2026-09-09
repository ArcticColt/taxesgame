//THE WHOLE TOWN DIDN'T PAY THEIR TAXES


#include <kos.h>
#include <png/png.h>

#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <math.h>

// #region class
#include "class/drawable.h"
#include "class/entity.h"
#include "class/player.h"
#include "class/eneFollow.h"
#include "class/level.h"
#include "class/camera.h"
#include "romdisk/asset/texture/textureList.h"
// #endregion


struct drawStruct{
    const char* texture;
    float x;
    float y;
    float depth;
    int width;
    int height;
    float u;
    float v;
    float uwid;
    float vhig;
};


uint32_t vramUsage = 0;
uint32_t vramUsageMax = 6291456;//1572864;

Level level;

std::unordered_map<std::string, pvr_ptr_t> textures = {};

std::vector<Drawable*> globalDrawList;
std::vector<Entity*> globalUpdateList;
std::vector<Player*> players;

std::vector<drawStruct> drawList;

uint8_t load_texture(std::string texture){
    TextureList texstruct = textureMeta[texture];
    uint32_t vramTest = (texstruct.width * texstruct.height) * 2;
    if ((vramUsage + vramTest) <= vramUsageMax)
    {
        //make new texture
        pvr_ptr_t tex;
        //alocate space for it
        tex = pvr_mem_malloc(texstruct.width * texstruct.height * 2);
        png_to_texture(texstruct.path, tex, PNG_MASK_ALPHA);
        //put tex in texture list
        textures[texture] = tex;
        vramUsage += vramTest;
        return 0;
    }
    else
    return 2;
}

void draw_sprite(const char* texture, float x, float y, float depth)
{
    TextureList texstruct = textureMeta[texture];
    drawList.push_back({texture, x, y, depth, texstruct.width, texstruct.height, 0.0f, 0.0f, 1.0f, 1.0f});
}

void draw_sprite(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig)
{
    drawList.push_back({texture, x, y, depth, width, height, u, v, uwid, vhig});
}

void init_level(){
    level.init();
}

int main(){
    pvr_init_defaults();
    init_level();
    while(true)
    {
        level.update();
        //run Update() on everything
        for (Entity* entity : globalUpdateList)
            entity->update();

        pvr_wait_ready();
        pvr_scene_begin();

        pvr_list_begin(PVR_LIST_TR_POLY);

        //main draw
        level.draw();
        for (Drawable* drawable : globalDrawList)
            drawable->draw();



        //after all the drawing calls, let the cameras do their jobs
        for (Player* player : players)
            player->camera.draw();


        //clear memory so stuff can MOVE instead of SNAKE
        drawList.clear();
        pvr_list_finish();
        pvr_scene_finish();
    }
    return 0;
}

std::tuple<float, float> vectorNormalize(std::tuple<float, float> tup){
    float x = std::get<0>(tup);
    float y = std::get<1>(tup);
    float xx = x * x;
    float yy = y * y;
    float sum = xx + yy;
    float sq = std::sqrt(sum);
    if (sq <= 0.0001f)
        return {0.0f, 0.0f};
    std::tuple<float, float> answ = {x / sq, y / sq};
    return answ;
}

Player* getNearestPlayer(float x, float y){
    std::vector<std::tuple<Player*, float>> validPlayers;
    for (Player* player : players){
        if (player->dead == false)
        {
            float dist = hypot(x - player->x, y - player->y);
            validPlayers.push_back({player, dist});
        }
    }
    Player* retPlyr = nullptr;
    float retDist = 1000000000.0f;
    for (std::tuple<Player*, float> info : validPlayers)
        {
            float testDist = std::get<1>(info);
            if (testDist < retDist)
            {
                retPlyr = std::get<0>(info);
                retDist = std::get<1>(info);
            }
        }
    return retPlyr;
}