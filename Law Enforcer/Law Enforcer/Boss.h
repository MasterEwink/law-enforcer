//
// Created by mad on 01/06/19.
//

#ifndef LAW_ENFORCER_BOSS_H
#define LAW_ENFORCER_BOSS_H

#include "Entity.h"

#define BOSS_SIZE 2.0f

class Boss : public Entity {
protected:
    int damage_attack;
    int damage_dash;
    int damage_jump;
    int damage_contact;
public:
    Boss(b2World &world, b2Vec2 coordonnees, int pvmax, int damage_attack, int damage_dash, int damage_jump, int damage_contact);
    void draw(sf::RenderWindow &window) override;
    void update(const Inputs &inputs, WorldRules &worldRules) override;
    float32 jump(bool world_jump_rule, bool input_jump, float32 current_vspeed) override;
};


#endif //LAW_ENFORCER_BOSS_H
