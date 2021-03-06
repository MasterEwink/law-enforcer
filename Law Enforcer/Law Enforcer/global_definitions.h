//
// Created by mad on 02/06/19.
//

#ifndef LAW_ENFORCER_GLOBAL_DEFINITIONS_H
#define LAW_ENFORCER_GLOBAL_DEFINITIONS_H

#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <pugixml.hpp>

#define PIXELS_BY_METER 60.0

#define WORLD_WIDTH 13.0
#define WORLD_HEIGHT 10.0

#define SCREEN_WIDTH WORLD_WIDTH*PIXELS_BY_METER
#define SCREEN_HEIGHT WORLD_HEIGHT*PIXELS_BY_METER

typedef enum {
    plateform_groundbox,
    entity_groundbox,
    player_footsensor,
    player_hurtbox,
    player_jump_hitbox,
    player_dash_hitbox,
    player_attack_hitbox,
    boss_footsensor,
    boss_hurtbox,
    boss_contact_hitbox,
    boss_jump_hitbox,
	boss_dash_hitbox,
	boss_attack_hitbox
} BoxTypes;

typedef struct {
    bool jump;
    bool dash;
    bool attack;
} WorldRules ;

sf::Vector2f convert_coords(b2Vec2 coordonnees_b2d, int offset_x=0, int offset_y=0);
void loadFixture(b2Body* body, pugi::xml_node node);

#endif //LAW_ENFORCER_GLOBAL_DEFINITIONS_H
