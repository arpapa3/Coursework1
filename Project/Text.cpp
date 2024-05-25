#include "Text.h"

Text* TextCreate(const char* str, SDL_Renderer* ren, SDL_Color color, TTF_Font* font, SDL_Rect* dstrect)
{
	SDL_Surface* syrf = TTF_RenderUTF8_Blended(font, str, color);
	Text* rez = (Text*)malloc(sizeof(Text));
	rez->dstrect = (SDL_Rect*)malloc(sizeof(SDL_Rect));

	rez->h = syrf->h;
	rez->w = syrf->w;
	rez->str = SDL_CreateTextureFromSurface(ren, syrf);
	SDL_FreeSurface(syrf);

	if (dstrect == NULL)
		*(rez->dstrect) = { 0, 0, rez->w, rez->h };
	else
		*(rez->dstrect) = { dstrect->x + dstrect->w / 2 - rez->w / 2, dstrect->y + dstrect->h / 2 - rez->h / 2, rez->w, rez->h };
	return rez;
}

void TextRender(Text* text, SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, text->str, NULL, text->dstrect);
}

void TextDestroy(Text* text)
{
	SDL_DestroyTexture(text->str);
	free(text->dstrect);
	free(text);
}