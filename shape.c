#include "shape.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

agentShape* initializeShape(sfColor color, int radius, sfVector2f position, float direction){
    agentShape* shape = (agentShape*) malloc(sizeof(agentShape));
    shape->color = color;
    shape->radius = radius;

    sfCircleShape* circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, shape->color);
    sfCircleShape_setRadius(circle, shape->radius);
    sfCircleShape_setPosition(circle, position);
    shape->circle = circle;

    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, shape->color);
    sfVector2f rectSize = {(float) shape->radius/10, (float) shape->radius*2};
    sfRectangleShape_setScale(rectangle, rectSize);
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setRotation(rectangle, direction);
    shape->rectangle = rectangle;
    return shape;
}