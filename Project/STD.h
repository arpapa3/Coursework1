#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

/*�������������� SDL*/
void Init(SDL_Window*& win, SDL_Renderer*& ren);
/*���������������� SDL, ��������� ��� ������*/
void DeInit(SDL_Window* win, SDL_Renderer* ren, int error);
/*���������� ��������� ����� ����� �� a �� b*/
int random(int, int);
/*���������� ��������� ������������ ����� �� a, b*/
double randomd(double a, double b);
/*������� �������������� ���������� coord, ���������� ������ ������� coord0, ������ scale � � ���������� rez ���������� ���������� � ����*/
void WinCoord(SDL_Point coord, SDL_Point coord0, double scale, SDL_Point& rez);