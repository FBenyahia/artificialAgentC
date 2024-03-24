#include "agent.h"



void move(Agent* agent){
    sfVector2f vec = {agent->speed * cos(agent->direction*2*M_PI/180), agent->speed * sin(agent->direction*2*M_PI/180)};                 
    sfCircleShape_move(agent->shape->circle, vec);
    sfRectangleShape_move(agent->shape->rectangle, vec);
}

void rotateLeft(Agent* agent){

    agent->direction-= agent->angularSpeed;
    if (agent->direction>360){
        agent->direction -=360;
    }
}


void rotateRight(Agent* agent){

    agent->direction+= agent->angularSpeed;
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
    else color = sfBlack;
    int radius = width/2;
    agent->shape = initializeShape(color, radius, agent->position, agent->direction);
    return agent;
}

void freeAgent(Agent* agent){
    sfCircleShape_destroy(agent->shape->circle);
    sfRectangleShape_destroy(agent->shape->rectangle);
    free(agent->shape);
    free(agent);
}