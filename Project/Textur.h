#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

/*
	* text - ссылка на текстуру
	* w, h - ширина и высота текстуры
	* rows, column - количество кадров в одной строке и коллчиество строк
	* src - область текстуры которую собираемс€ отрисвоать
	* dst - область окна в которую нужно отрисовать структуру
*/
struct Texture {
	SDL_Texture* text;
	int w, h, rows, column, framex, framey, frametime;
	SDL_Rect src, dst;
};
//«агружает текстуру из файла
Texture* ImageLoadTexture(SDL_Renderer* ren, const char* filename);
//—читает нужно ли помен€ть кадр в анимации
void NextFrame(Texture* text, int dtime, int speed);
//ќбертка на RenderCopy
void ImageRenderCopy(SDL_Renderer* ren, Texture* text);
//ќбертка на RenderCopyExp
void ImageRenderCopyExp(SDL_Renderer* ren, Texture* text, double angel, SDL_Point* center, SDL_RendererFlip flag);
//”дал€ет текстуру
void ImageFreeTexture(Texture* text);