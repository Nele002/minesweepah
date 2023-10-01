#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	SDL_Texture* tex = NULL;

	SDL_Surface* tmpSurface = IMG_Load(filename);
	if (!tmpSurface) {
		std::cout << "Unable to load image! Error: " << IMG_GetError() << std::endl;
	}
	else {
		tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
		if (!tex) {
			std::cout << "Unable to load texture! Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(tmpSurface);
	}

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

