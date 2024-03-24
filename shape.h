#ifndef SHAPE_H
#define SHAPE_H 0

//define Pi 
#ifndef M_PI
 #define M_PI 3.14159265358979323846
#endif


#include <stdint.h>
#include <math.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>


#include <SFML/Graphics/Color.h>
struct agentShape{
    sfColor color;
    int radius;
    sfCircleShape* circle;
    sfRectangleShape* rectangle;
};

typedef struct agentShape agentShape ;

agentShape* initializeShape(sfColor color, int radius, sfVector2f position, float direction);

#endif