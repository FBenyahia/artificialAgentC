#include "agent.h"
#include "shape.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

void rotate(Agent* agent, double tick){

    agent->direction+= agent->angularSpeed*tick;
    if (agent->direction>360){
        agent->direction -=360;
    }
}

Agent* initializeAgent(double positionX, double positionY, double direction, double angularSpeed, double speed, int width, int height, int type){
    Agent* agent = (Agent*) malloc(sizeof(Agent));
    agent->position.x = positionX;
    agent->position.y = positionY;
    agent->direction = direction;
    agent->angularSpeed = angularSpeed;
    agent->speed = speed;
    agent->width = width;
    agent->height = height;
    agent->type = type;
    sfColor color;
    if (type==0) color= sfGreen;
    else if (type==1) color = sfRed;
    int radius = width/2;
    agent->shape = initializeShape(color, radius, agent->position);
    return agent;
}

void freeAgent(Agent* agent){
    sfCircleShape_destroy(agent->shape->circle);
    free(agent->shape);
    free(agent);
}