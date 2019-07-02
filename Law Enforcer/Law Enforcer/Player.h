//
// Created by mad on 01/06/19.
//

#ifndef LAW_ENFORCER_PLAYER_H
#define LAW_ENFORCER_PLAYER_H


#include "Entity.h"
#include "Inputs.h"

class Player : public Entity {
private:
    int jump_time_left;
    int jump_time_max;
    int max_speed;
    int jump_speed;
    int contact_stun;
    void do_jump(bool input_jump, float32 &current_vspeed) override;
public:
    Player(b2World &world, b2Vec2 coordonnees, int pvmax);
    void draw(sf::RenderWindow &window) override;
    void update(const Inputs &inputs, WorldRules &worldRules) override;
    void dash(bool world_dash_rule, bool input_dash, b2Vec2& current_speed) override;
    int get_contact_stun() const;
};


#endif //LAW_ENFORCER_PLAYER_H
