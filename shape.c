#include "shape.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

agentShape* initializeShape(sfColor color, int radius, sfVector2f position){
    agentShape* shape = (agentShape*) malloc(sizeof(agentShape));
    shape->color = color;
    shape->radius = radius;
    sfCircleShape* circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, shape->color);
    sfCircleShape_setRadius(circle, shape->radius);
    sfCircleShape_setPosition(circle, position);
    shape->circle = circle;
    return shape;
}