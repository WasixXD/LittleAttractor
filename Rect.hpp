#ifndef Rect_hpp
#define Rect_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>


class Rect {
    public: 
        SDL_Rect rect;
        float xvel = 1, yvel = 1;
        float xacc = 0.01, yacc = 0.01;


        Rect(int x, int y, int w, int h) {
            this->rect.x = x;
            this->rect.y = y;
            this->rect.w = w;
            this->rect.h = h;
        }


        void update(int mousePosX, int mousePosY) {


            // this.acc = this.pos.sub(mouseLocation)
            this->xacc = static_cast<float>(mousePosX - this->rect.x);
            this->yacc = static_cast<float>(mousePosY - this->rect.y);
        

            // setMag(0.1)
            float c = 0.07f;
            float mag = sqrt(pow(this->xacc, 2) + pow(this->yacc, 2));
            // normalizando e depois ampliando
            this->xacc = (this->xacc / mag) * c;
            this->yacc = (this->yacc / mag) * c;


            // this.vel.add(this.acc)
            this->xvel += this->xacc;
            this->yvel += this->yacc;

            // this.pos.add(this.vel)
            this->rect.x += this->xvel;
            this->rect.y += this->yvel;
        }

        void draw(SDL_Renderer *renderer) {
            SDL_SetRenderDrawColor(renderer, 251, 73, 52, 0);
            SDL_RenderFillRect(renderer, &this->rect);
            SDL_RenderPresent(renderer);
        }
};





#endif