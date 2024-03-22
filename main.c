#include "agent.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdint.h>

int main(){

    sfVideoMode mode = {1000, 1000, 32};
    const char* title = "Artificial Agent";
    sfRenderWindow* window =sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    
    sfRenderWindow_setMouseCursorVisible(window, false);


    sfEvent event;
    sfFloatRect view_rectangle = {0, 0, 0, 0};
    sfView* new_view = sfView_createFromRect(view_rectangle);
    sfClock* ticks = sfClock_create();
    Agent* agent = initializeAgent(500, 500, 0.0, 10, 10, 100, 100, 0);
    Agent* agent2 = initializeAgent(10, 10, 0.0, 10, 10, 50, 50, 1);
    while (sfRenderWindow_isOpen(window)) {
        printf("%d\n", (int32_t) sfTime_asMilliseconds(sfClock_getElapsedTime(ticks)));
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type==sfEvtClosed) {
                sfRenderWindow_close(window);
            } else if (event.type == sfEvtResized) {
                view_rectangle.width = event.size.width;
                view_rectangle.height = event.size.height;
                sfView_reset(new_view, view_rectangle);
                sfRenderWindow_setView(window, new_view);
            } else if (event.type == sfEvtKeyPressed) {
                if(event.key.code == sfKeyZ){
                    
                } else if (event.key.code == sfKeyD){
                    rotate(agent, 10);
                }
            }
        }
    
        
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawCircleShape(window, agent->shape->circle, NULL);
        sfRenderWindow_drawCircleShape(window, agent2->shape->circle, NULL);
        sfRenderWindow_display(window);
    }
    
    freeAgent(agent);
    freeAgent(agent2);
    sfView_destroy(new_view);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
