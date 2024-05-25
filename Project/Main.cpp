#define _CRT_SECURE_NO_WARNINGS
#include "STD.h"

#define FPS 60

const Uint8* keyboard;

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

int SDL_main(int argc, char** argv)
{
	SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
	system("chcp 1251>nul");
	Init(win, ren);

	TTF_Font* fond = TTF_OpenFont("Font/arial.ttf", 40);

	//Запуск музыки
	Mix_Music* music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music, -1);

	keyboard = SDL_GetKeyboardState(NULL);

	int newtime, oldtime = 0, deltime = 0, frametime = 0;
	int volume = 100;
	bool run = true;
	SDL_Event ev;
	Textur* text = Textur_Load(ren, "text.text");

	while (run)
	{
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				run = false;
				break;
			//case SDL_KEYDOWN:
			//	switch (ev.key.keysym.scancode)
			//	{
			//	case SDL_SCANCODE_SPACE:
			//	{
			//		if (!Mix_PausedMusic())
			//			Mix_PauseMusic();
			//		else
			//			Mix_ResumeMusic();
			//	}
			//	break;
			//	case SDL_SCANCODE_KP_PLUS:
			//		if (volume < 100) volume++;
			//		break;
			//	case SDL_SCANCODE_KP_MINUS:
			//		if (volume > 0) volume--;
			//		break;
			//	}
			}
		}

		//Подсчет времени
		newtime = SDL_GetTicks();
		deltime = newtime - oldtime;
		oldtime = newtime;
		frametime += deltime;

		Textur_NextFrame(text, deltime);

		//Установка громкости музыки
		Mix_VolumeMusic(128 * volume / 100);

		//Нужна ли отрисовка
		if(frametime >= 1000 / FPS)
		{
			Textur_RenderCopy(ren, text);
			SDL_RenderPresent(ren);
			frametime = 0;
		}
	}
	Mix_FreeMusic(music);
	DeInit(win, ren, 0);
	return 0;
}