#include "fish.h"

Fish::Fish() {
	srand(time(NULL));
	position = Vector2(rand() % SCREENWIDTH, rand() % SCREENHEIGHT);
	position = Vector2(50, 50);
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
	SetupLayer(network.hiddenLayer, 4);
	SetupLayer(network.outputLayer, 3);
	SetupConnectionsRandom(network);
	UpdateNetwork(network);
	SetupNodeNetwork(&network, nodeNetwork);
}

void Fish::Update(int gameTime) {
	if (position.x > SCREENWIDTH) position.x = 0 - width;
	if (position.x + width < 0) position.x = SCREENWIDTH;
	if (position.y > SCREENHEIGHT) position.y = 0 - height;
	if (position.y + height < 0) position.y = SCREENHEIGHT;

	Vector2 direction = Vector2((float)cos((rotation * M_PI) / 180), sin((rotation * M_PI) / 180));
	direction.Normalize();
	position += direction;
}

void Fish::Draw() {
	DrawTriangle(position, width, height, rotation);
	DrawNodeNetwork(nodeNetwork, Vector2(400, 400));
}