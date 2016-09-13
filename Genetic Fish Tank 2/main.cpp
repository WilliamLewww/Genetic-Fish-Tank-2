#include "main.h"

void Quit();
void LoadContent();
void Update(int gameTime);
void Render(SDL_Window* window, SDL_GLContext context);

Fish testFish;
Food testFood(Vector2(0, 0));

SDL_Event event;
SDL_GLContext context;

bool isRunning = true;
int frameStart, frameEnd, deltaTime = 0;
int main(int argc, char *argv[]) {
	displayWindow = SDL_CreateWindow("Genetic Fish Tank 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(displayWindow);
	glOrtho(-SCREENWIDTH / 2, SCREENWIDTH / 2, SCREENHEIGHT / 2, -SCREENHEIGHT / 2, 0, 1);

	LoadContent();

	while (isRunning) {
		RemoveInitialPress();
		leftButtonPress = false;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				isRunning = false;

			GetKeys(event);
			GetButtons(event);
		}

		if (deltaTime < 1 / 60) {
			frameStart = SDL_GetTicks();
			SDL_Delay(1);
			frameEnd = SDL_GetTicks();
			deltaTime = frameEnd - frameStart;
		}
		frameStart = SDL_GetTicks();
		Update(deltaTime);
		Render(displayWindow, context);
		frameEnd = SDL_GetTicks();
		deltaTime = frameEnd - frameStart;
	}

	Quit();

	return 0;
}

void Quit() {
	SDL_Quit();
}

void LoadContent() {
	testFish.LoadContent();
}

void Update(int gameTime) {
	testFish.Update(gameTime);
}

void Render(SDL_Window* window, SDL_GLContext context) {
	SDL_GL_MakeCurrent(window, context);
	glClearColor(ConvertColor(0), ConvertColor(0), ConvertColor(0), 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);

	testFish.Draw();
	testFood.Draw();

	SDL_GL_SwapWindow(window);
}

float ConvertColor(int rgbValue) {
	return (float)rgbValue / 255;
}