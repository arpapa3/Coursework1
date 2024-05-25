#include "STD.h"

void Init(SDL_Window*& win, SDL_Renderer*& ren)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("Инициализация SDL прошла с ошибками:%s\n", SDL_GetError());
		exit(-1);
	}

	win = SDL_CreateWindow("The best Vampire Survivors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		printf("Ошибка создания окна:%s\n", SDL_GetError());
		DeInit(win, ren, -2);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		printf("Ошибка создания рендера:%s\n", SDL_GetError());
		DeInit(win, ren, -3);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
	{
		printf("Инициализация SDL_Image прошла с ошибками:%s\n", IMG_GetError());
		DeInit(win, ren, -4);
	}

	if (Mix_OpenAudio(48000, AUDIO_U8, 1, 2048))
	{
		printf("Ошибка инициализации аудио системы: %s\n", Mix_GetError());
		DeInit(win, ren, -5);
	}

	if (TTF_Init() != NULL)
	{
		printf("Ошибка инициализации ttf:%s\n", TTF_GetError());
		DeInit(win, ren, -6);
	}
}

void DeInit(SDL_Window* win, SDL_Renderer* ren, int error)
{
	if (ren) SDL_DestroyRenderer(ren);
	if (win) SDL_DestroyWindow(win);
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	exit(error);
}

int random(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

double randomd(double a, double b)
{
	return a + (b - a) / RAND_MAX * rand();
}

void WinCoord(SDL_Point coord, SDL_Point coord0, double scale, SDL_Point& rez)
{
	rez = { (int)(coord0.x + coord.x * scale), (int)(coord0.y - coord.y * scale) };
}