#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y) {
    TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("Connect4+",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int rows = 6, cols = 7, winNeed = 4;
    Game game(rows, cols, winNeed);
    bool quit = false;
    bool gameOver = false;
    int selectedCol = 0;

    const int cellSize = 80;
    const int offsetX = (SCREEN_WIDTH - cols * cellSize) / 2;
    const int offsetY = (SCREEN_HEIGHT - rows * cellSize) / 2;

    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    if (!gameOver) selectedCol = std::max(0, selectedCol - 1);
                    break;
                case SDLK_RIGHT:
                    if (!gameOver) selectedCol = std::min(cols - 1, selectedCol + 1);
                    break;
                case SDLK_RETURN:
                case SDLK_SPACE:
                    if (!gameOver) {
                        game.play(selectedCol);
                        if (game.getCurrentPlayer() == PLAYER_2 && game.status() == ONGOING) {
                            SDL_Delay(300);
                            game.aiMove();
                        }
                        gameOver = (game.status() != ONGOING);
                    }
                    break;
                case SDLK_r:
                    game = Game(rows, cols, winNeed);
                    gameOver = false;
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && !gameOver) {
                int col = (e.button.x - offsetX) / cellSize;
                if (col >= 0 && col < cols) {
                    game.play(col);
                    if (game.getCurrentPlayer() == PLAYER_2 && game.status() == ONGOING) {
                        SDL_Delay(300);
                        game.aiMove();
                    }
                    gameOver = (game.status() != ONGOING);
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        game.draw(renderer, cellSize, offsetX, offsetY);

        // Selector
        if (!gameOver) {
            SDL_Rect selector = { offsetX + selectedCol * cellSize, offsetY - 10, cellSize, 10 };
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &selector);
        }

        if (gameOver) {
            std::string msg;
            switch (game.status()) {
            case WIN_PLAYER_1: msg = "Player 1 (Red) Wins! Press R."; break;
            case WIN_PLAYER_2: msg = "AI (Blue) Wins! Press R."; break;
            case DRAW: msg = "Draw! Press R."; break;
            default: break;
            }
            renderText(renderer, msg, 50, 20);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
