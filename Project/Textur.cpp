#define _CRT_SECURE_NO_WARNINGS
#include "Textur.h"

Textur* Textur_Load(SDL_Renderer* ren, const char* filename, SDL_Rect* dstrect)
{
	char s[256] = "Texture\\";
	strcat(s, filename);
	Textur* rez = (Textur*)malloc(sizeof(Textur));
	FILE* file = fopen(s, "r");
	if (file == NULL)
	{
		printf("Ошибка открытия файла:%s\n", s);
		exit(-1);
	}
	fscanf(file, "%d %d\n%d\n%s", &rez->column, &rez->rows, &rez->speed, s + 8);
	fclose(file);

	SDL_Surface* image = IMG_Load(s);
	if (image == NULL)
	{
		printf("Ошибка загрузки текстуры: %s\n", SDL_GetError());
		exit(-1);
	}
	rez->text = SDL_CreateTextureFromSurface(ren, image);
	if (image == NULL)
	{
		printf("Ошибка создания текстуры: %s\n", SDL_GetError());
		exit(-1);
	}

	rez->w = image->w;
	rez->h = image->h;
	*rez->src = { 0, 0, rez->w / rez->column, rez->h / rez->rows};
	if (dstrect)
		*rez->dst = *rez->src;
	else
		*rez->dst = { dstrect->x, dstrect->y, rez->src->w, rez->src->h };
	SDL_FreeSurface(image);

	rez->framex = rez->framey = rez->frametime = 0;
	return rez;
}

void Textur_NextFrame(Textur* text, int dtime)
{
	text->frametime += dtime;
	if (text->frametime >= 1000 / text->speed)
	{
		text->framex++;
		if (text->framex == text->column)
		{
			text->framex = 0;
			text->framey++;
			if (text->framey == text->rows)
				text->framey = 0;
		}
		*text->src = { text->framex * text->w / text->column, text->framey * text->h / text->rows, text->src->w, text->src->h };
		text->frametime = 0;
	}
}

void Textur_RenderCopy(SDL_Renderer* ren, Textur* text)
{
	if(SDL_RenderCopy(ren, text->text, text->src, text->dst))
		printf("Ошибка отрисовки:%s\n", SDL_GetError());
}

void Textur_RenderCopyExp(SDL_Renderer* ren, Textur* text, double angel, SDL_Point* center, SDL_RendererFlip flag)
{
	if (SDL_RenderCopyEx(ren, text->text, text->src, text->dst, angel, center, flag))
		printf("Ошибка отрисовки:%s\n", SDL_GetError());
}

void Textur_Free(Textur* text)
{
	SDL_DestroyTexture(text->text);
	free(text);
}