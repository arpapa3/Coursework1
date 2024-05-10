#define _CRT_SECURE_NO_WARNINGS
#include "Textur.h"

#define FPS 60

Texture* ImageLoadTexture(SDL_Renderer* ren, const char* filename)
{
	char s[256] = "Texture\\";
	strcat(s, filename);
	Texture* rez = (Texture*)malloc(sizeof(Texture));
	FILE* file = fopen(s, "r");
	if (file == NULL)
	{
		printf("Ошибка открытия файла:%s\n", s);
		exit(-1);
	}
	fscanf(file, "%d %d\n%d %d\n%s", &rez->column, &rez->rows, &rez->w, &rez->h, s + 8);
	rez->dst = rez->src = { 0, 0, rez->w / rez->column, rez->h / rez->rows};
	SDL_Surface* image = IMG_Load(s);
	rez->text = SDL_CreateTextureFromSurface(ren, image);
	if (rez->text == NULL)
	{
		printf("Ошибка загрузки текстур:%s\n", SDL_GetError());
		exit(-1);
	}
	SDL_FreeSurface(image);
	fclose(file);
	rez->framex = rez->framey = rez->frametime = 0;
	return rez;
}

void NextFrame(Texture* text, int dtime, int speed)
{
	text->frametime += dtime;
	if (text->frametime >= 1000 / speed)
	{
		text->framex++;
		if (text->framex == text->column)
		{
			text->framex = 0;
			text->framey++;
			if (text->framey == text->rows)
				text->framey = 0;
		}
		text->src = { text->framex * text->w / text->column, text->framey * text->h / text->rows, text->src.w, text->src.h };
		text->frametime = 0;
	}
}

void ImageRenderCopy(SDL_Renderer* ren, Texture* text)
{
	if(SDL_RenderCopy(ren, text->text, &(text->src), &(text->dst)))
		printf("Ошибка отрисовки:%s\n", SDL_GetError());
}

void ImageRenderCopyExp(SDL_Renderer* ren, Texture* text, double angel, SDL_Point* center, SDL_RendererFlip flag)
{
	if (SDL_RenderCopyEx(ren, text->text, &(text->src), &(text->dst), angel, center, flag))
		printf("Ошибка отрисовки:%s\n", SDL_GetError());
}

void ImageFreeTexture(Texture* text)
{
	if(text != NULL)
	{
		SDL_DestroyTexture(text->text);
		free(text);
	}
}