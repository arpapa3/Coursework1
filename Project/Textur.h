#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

/*
	* text - ссылка на текстуру
	* w, h - ширина и высота текстуры
	* rows, column - количество кадров в одной строке и коллчиество строк
	* src - область текстуры которую собираемся отрисвоать
	* dst - область окна в которую нужно отрисовать структуру
*/
struct Texture {
	SDL_Texture* text;
	int w, h, rows, column, framex, framey, frametime;
	SDL_Rect src, dst;
};
//Загружает текстуру из файла filename передается название в папке Texture
Texture* ImageLoadTexture(SDL_Renderer* ren, const char* filename);
//Считает нужно ли поменять кадр в анимации speed - сколько кадров должно быть в секунл=ду
void NextFrame(Texture* text, int dtime, int speed);
//Обертка на RenderCopy
void ImageRenderCopy(SDL_Renderer* ren, Texture* text);
//Обертка на RenderCopyExp
void ImageRenderCopyExp(SDL_Renderer* ren, Texture* text, double angel, SDL_Point* center, SDL_RendererFlip flag);
//Удаляет текстуру
void ImageFreeTexture(Texture* text);