#include "fish.h"

Fish::Fish() {
	srand(time(NULL));
	position = Vector2(rand() % SCREENWIDTH, rand() % SCREENHEIGHT);
	width = 25; height = 25;
	rotation = rand() % 360;
}

Fish::Fish(Vector2 positionParam, int widthParam, int heightParam, double rotationParam) {
	position = positionParam;
	width = widthParam;
	height = heightParam;
	rotation = rotationParam;
}

void Fish::LoadContent() {
	SetupLayer(network.inputLayer, 2);
	SetupLayer(network.hiddenLayer, 3);
	SetupLayer(network.outputLayer, 1);
	SetupConnectionsRandom(network);
	UpdateNetwork(network);
}

void Fish::Update(int gameTime) {
	if (position.x > SCREENWIDTH) position.x = 0 - width;
	if (position.x + width < 0) position.x = SCREENWIDTH;
	if (position.y > SCREENHEIGHT) position.y = 0 - height;
	if (position.y + height < 0) position.y = SCREENHEIGHT;
}

void Fish::Draw() {
	DrawTriangle(position, width, height, rotation);
}