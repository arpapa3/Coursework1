#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

/*
	* text - ������ �� ��������
	* w, h - ������ � ������ ��������
	* rows, column - ���������� ������ � ����� ������ � ����������� �����
	* src - ������� �������� ������� ���������� ����������
	* dst - ������� ���� � ������� ����� ���������� ���������
*/
struct Texture {
	SDL_Texture* text;
	int w, h, rows, column, framex, framey, frametime;
	SDL_Rect src, dst;
};
//��������� �������� �� �����
Texture* ImageLoadTexture(SDL_Renderer* ren, const char* filename);
//������� ����� �� �������� ���� � ��������
void NextFrame(Texture* text, int dtime, int speed);
//������� �� RenderCopy
void ImageRenderCopy(SDL_Renderer* ren, Texture* text);
//������� �� RenderCopyExp
void ImageRenderCopyExp(SDL_Renderer* ren, Texture* text, double angel, SDL_Point* center, SDL_RendererFlip flag);
//������� ��������
void ImageFreeTexture(Texture* text);