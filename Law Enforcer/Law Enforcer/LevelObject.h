//
// Created by mad on 01/06/19.
//

#ifndef LAW_ENFORCER_LEVELOBJECT_H
#define LAW_ENFORCER_LEVELOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <pugixml.hpp>
#include "Inputs.h"
#include "global_definitions.h"

class LevelObject {
protected:
    b2Vec2 coordonnees;
    b2Body *body;
    sf::Vector2f coordonnees_sfml;
public:
    LevelObject(b2Vec2 coordonnees);
    LevelObject(pugi::xml_node node);
    virtual void draw(sf::RenderWindow &window)=0;
    virtual void update(const Inputs &inputs, WorldRules &worldRules) =0;
    b2Vec2 get_coordinates() const;
};


#endif //LAW_ENFORCER_LEVELOBJECT_H
