//
// Created by mad on 01/06/19.
//

#ifndef LAW_ENFORCER_PLAYER_H
#define LAW_ENFORCER_PLAYER_H


#include "Entity.h"
#include "Inputs.h"

enum SpriteState {
    player_idle,
    player_walk,
    player_jump,
    player_fall,
    player_dash,
    player_attack,
    player_hurt
};

class Player : public Entity {
private:
    int jump_time_left;
    int jump_time_max;
    int max_speed;
    int contact_stun;
	enum SpriteState anim;
	int sprite_size;
	int walk_time;
	int change_walk_time;
    void do_jump(bool input_jump, float32 &current_vspeed) override;
    void do_dash(bool input_dash, b2Vec2& current_speed) override;
public:
    Player(b2World &world, b2Vec2 coordonnees, int pvmax);
    Player(b2World &world, pugi::xml_node node);
    void draw(sf::RenderWindow &window) override;
    void update(const Inputs &inputs, WorldRules &worldRules) override;
	void setJump(bool) override;
	void take_damage(int damage, int time_without_control, b2Vec2 ejection_speed) override;
    int get_contact_stun() const;
};

#endif //LAW_ENFORCER_PLAYER_H
