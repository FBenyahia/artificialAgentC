#include "shape.h"


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
    sfVector2f rectSize = {(float) 100, (float) 100};
    sfRectangleShape_setScale(rectangle, rectSize);
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setRotation(rectangle, direction);
    shape->rectangle = rectangle;
    return shape;
}