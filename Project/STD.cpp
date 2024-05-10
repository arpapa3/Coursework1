#include "STD.h"

void Init(SDL_Window*& win, SDL_Renderer*& ren)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("Инициализация SDL прошла с ошибками:%s\n", SDL_GetError());
		exit(-1);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
	{
		printf("Инициализация SDL_Image прошла с ошибками:%s\n", SDL_GetError());
		DeInit(win, ren, -2);
	}

	SDL_DisplayMode DM;
	if (SDL_GetCurrentDisplayMode(0, &DM) != 0)
	{
		printf("Получение размера дисплея прошла с ошибками:%s\n", SDL_GetError());
		DeInit(win, ren, -5);
	}

	win = SDL_CreateWindow("The best Vampire Survivors", 0, 0, DM.w, DM.h, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		printf("Ошибка создания окна:%s\n", SDL_GetError());
		DeInit(win, ren, -3);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		printf("Ошибка создания рендера:%s\n", SDL_GetError());
		DeInit(win, ren, -4);
	}
}

void DeInit(SDL_Window* win, SDL_Renderer* ren, int error)
{
	if (ren) SDL_DestroyRenderer(ren);
	if (win) SDL_DestroyWindow(win);
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