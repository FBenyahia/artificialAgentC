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

void rotate(Agent* agent, double tick);

Agent* initializeAgent(double positionX, double positionY, double direction, double angularSpeed, double speed, int width, int height,int type);
void freeAgent(Agent* agent);



#endif