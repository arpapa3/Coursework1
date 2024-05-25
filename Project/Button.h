#pragma once
#include <SDL.h>
#include "Text.h"

typedef struct Button
{
	SDL_Texture* image;
	SDL_Rect* rectImage, * rect, * rectText;
	Text* text;
	SDL_Color color;
};

Button* ButtonCreateText(SDL_Rect* rect);

Button* ButtonCreateTextImage(SDL_Rect);

Button* ButtomCreateImage(SDL_Rect);