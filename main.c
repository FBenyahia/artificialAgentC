#include "agent.h"


int main(){

    sfVideoMode mode = {1000, 1000, 32};
    const char* title = "Artificial Agent";
    sfRenderWindow* window =sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    
    sfRenderWindow_setMouseCursorVisible(window, false);

    
    sfEvent event;
    sfFloatRect view_rectangle = {0, 0, 0, 0};
    sfView* new_view = sfView_createFromRect(view_rectangle);


    sfClock* ticks = sfClock_create();
    

    Agent* agent = initializeAgent(500, 500, 0.0, 0.7, 1, 50, 50, 0);
    Agent* agent2 = initializeAgent(10, 10, 0.0, 10, 10, 50, 50, 1);
    while (sfRenderWindow_isOpen(window)) {
        //printf("%d\n", (int32_t) sfTime_asSeconds(sfClock_getElapsedTime(ticks)));
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
                move(agent);
            } if (sfKeyboard_isKeyPressed(sfKeyQ)) {
                rotateLeft(agent);
            } if (sfKeyboard_isKeyPressed(sfKeyD)) {
                rotateRight(agent);
            }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type==sfEvtClosed) {
                sfRenderWindow_close(window);
            } else if (event.type == sfEvtResized) {
                view_rectangle.width = event.size.width;
                view_rectangle.height = event.size.height;
                sfView_reset(new_view, view_rectangle);
                sfRenderWindow_setView(window, new_view);
            } 
        }
    
        
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawCircleShape(window, agent->shape->circle, NULL);
        sfRenderWindow_drawRectangleShape(window, agent->shape->rectangle , NULL);
        sfRenderWindow_drawCircleShape(window, agent2->shape->circle, NULL);
        sfRenderWindow_drawRectangleShape(window, agent2->shape->rectangle , NULL);
        sfRenderWindow_display(window);
    }
    
    freeAgent(agent);
    freeAgent(agent2);
    sfView_destroy(new_view);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
