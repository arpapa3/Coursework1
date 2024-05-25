#pragma once
#include <SDL_ttf.h>

typedef struct Text
{
	SDL_Texture* str;
	int h, w;
	SDL_Rect* dstrect;
};

//Создание надписи из строки str шрифтом font с цветом color, будет отрисовываться в центре dstrect(при передаче NULL отрисовывает в левом верхнем углу)
Text* TextCreate(const char* str, SDL_Renderer* ren, SDL_Color color, TTF_Font* font, SDL_Rect* dstrect);
//Отрисовка надписи text на экрна
void TextRender(Text* text, SDL_Renderer* ren);
//Освобождение памяти из под надписи text
void TextDestroy(Text* text);