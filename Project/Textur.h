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
	* framex, framey - кадр по счету в столбце и строке
	* frametime - время текущего кадра
	* speed - скорость смены кадра в кадрах в секунду
*/
struct Textur {
	SDL_Texture* text;
	int w, h, rows, column;
	int framex, framey, frametime, speed;
	SDL_Rect *src, *dst;
};
//Загружает текстуру из файла filename передается название в папке Texture
Textur* Textur_Load(SDL_Renderer* ren, const char* filename);
//Считает нужно ли поменять кадр в анимации speed - сколько кадров должно быть в секунл=ду
void Textur_NextFrame(Textur* text, int dtime);
//Обертка на RenderCopy
void Textur_RenderCopy(SDL_Renderer* ren, Textur* text);
//Обертка на RenderCopyExp
void Textur_RenderCopyExp(SDL_Renderer* ren, Textur* text, double angel, SDL_Point* center, SDL_RendererFlip flag);
//Удаляет текстуру
void Textur_Free(Textur* text);