#ifndef AGENT_H
#define AGENT_H 0

#include "shape.h"



struct Agent {
    sfVector2f position;
    double direction;
    double angularSpeed;
    double speed;
    int width;
    int height;
    int type;
    agentShape* shape;
};

typedef struct Agent Agent;

void move(Agent* agent);
void rotateLeft(Agent* agent);
void rotateRight(Agent* agent);

Agent* initializeAgent(double positionX, double positionY, double direction, double angularSpeed, double speed, int width, int height,int type);
void freeAgent(Agent* agent);



#endif