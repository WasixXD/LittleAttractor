#include <iostream>
#include <SDL2/SDL.h>
#include "Rect.hpp"

const int WIDTH = 800, HEIGTH = 600;

void clear_screen(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
    SDL_RenderClear(renderer);
}




int main( int argc, char *argv[]) {
    
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGTH,
                                          0);

    if(NULL == window) {
        std::cout << "Could not create window: " << SDL_GetError();
        return 1;   
    }

    SDL_Event windowEvent;
    SDL_Renderer *window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(window_renderer, 40, 40, 40, 0);
    SDL_RenderPresent(window_renderer);

    int mouseX, mouseY;

    Rect mrect(200, 200, 50, 50);


    //game loop
    while(true) {
        mrect.update(mouseX, mouseY);
        mrect.draw(window_renderer);
        
        if(SDL_PollEvent( &windowEvent )) {
            if( SDL_QUIT == windowEvent.type) {
                break;
            } else if(windowEvent.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mouseX, &mouseY);
            }
        }
        


        SDL_Delay(100/30);
        SDL_RenderPresent(window_renderer);
        
        clear_screen(window_renderer);



    }

    SDL_DestroyWindow(window);
    SDL_Quit();

   
    return 0;
}