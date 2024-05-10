#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "STD.h"
#include "Textur.h"

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

int SDL_main(int argc, char** argv)
{
	system("chcp 1251>nul");
	Init(win, ren);
	Texture* image = ImageLoadTexture(ren, "text.text");
	Texture* fire = ImageLoadTexture(ren, "fire.text");
	fire->dst.x = 800;
	fire->dst.y = 800;
	SDL_Surface* surf = IMG_Load("Texture/bac.jpg");
	SDL_Texture* background = SDL_CreateTextureFromSurface(ren, surf);
	SDL_FreeSurface(surf);

	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	int newtime, oldtime = 0, deltime = 0;
	bool desp = true;
	bool run = true;
	SDL_Event ev;

	while (run)
	{
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				run = false;
			default:
				break;
			}
		}

		newtime = SDL_GetTicks();
		deltime = newtime - oldtime;
		oldtime = newtime;

		NextFrame(image, deltime, 1);
		NextFrame(fire, deltime, 10);

		if (keyboard[SDL_SCANCODE_D] && !keyboard[SDL_SCANCODE_A])
		{
			image->dst.x++;
			desp = true;
		}
		if (!keyboard[SDL_SCANCODE_D] && keyboard[SDL_SCANCODE_A])
		{
			image->dst.x--;
			desp = false;
		}
		if (keyboard[SDL_SCANCODE_W] && !keyboard[SDL_SCANCODE_S]) image->dst.y--;
		if (!keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_S]) image->dst.y++;

		SDL_RenderCopy(ren, background, NULL, NULL);
		ImageRenderCopy(ren, fire);
		if (desp)
			ImageRenderCopyExp(ren, image, 0, NULL, SDL_FLIP_HORIZONTAL);
		else
			ImageRenderCopy(ren, image);
		SDL_RenderPresent(ren);
	}
	ImageFreeTexture(image);
	SDL_DestroyTexture(background);
	DeInit(win, ren, 0);
	return 0;
}