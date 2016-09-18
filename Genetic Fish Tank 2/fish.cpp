#include "fish.h"

int GetLine(double rotation);
double GetSlope(double rotation);

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
	SetNeuron(network, network.inputLayer[0], 1);
}

void Fish::Update(int gameTime) {
	float deltaTimeS = (float)(gameTime) / 1000;

	if (rotation >= 360) rotation -= 360;

	if (position.x > SCREENWIDTH) position.x = 0 - width;
	if (position.x + width < 0) position.x = SCREENWIDTH;
	if (position.y > SCREENHEIGHT) position.y = 0 - height;
	if (position.y + height < 0) position.y = SCREENHEIGHT;
	
	if (network.outputLayer[0].Sigmoid() >= 0.5) {
		Vector2 direction = Vector2((float)cos((-rotation * M_PI) / 180), sin((-rotation * M_PI) / 180));
		direction.Normalize();
		position += (direction * deltaTimeS) * 75;
	}

	if (network.outputLayer[1].Sigmoid() >= 0.5 && network.outputLayer[2].Sigmoid() < network.outputLayer[1].Sigmoid()) rotation += 75 * deltaTimeS;
	if (network.outputLayer[2].Sigmoid() >= 0.5 && network.outputLayer[1].Sigmoid() < network.outputLayer[2].Sigmoid()) rotation -= 75 * deltaTimeS;

	GetClosestFood(foodList, closestLeft, closestRight);

	///Theoretical Movement
	//if (network.inputLayer[0].value == 1) rotation += 75 * deltaTimeS;
	//if (network.inputLayer[1].value == 1) rotation -= 75 * deltaTimeS;
}

void Fish::Draw() {
	DrawTriangle(position, width, height, rotation);
	DrawNodeNetwork(nodeNetwork, Vector2(400, 400));
}

void Fish::GetClosestFood(std::vector<Food> foodList, double &left, double &right) {
	if (foodList.size() > 0) {
		double minDistanceLeft = -1, minDistanceRight = -1;
		switch (GetLine(rotation)) {
			case -1:
				for (int x = 0; x < foodList.size(); x++) {
					if (foodList[x].position.x < position.x) {
						if (minDistanceLeft < 0 || GetRelativePosition(foodList[0]) < minDistanceLeft) {
							left = minDistanceLeft;
						}
					}

					if (foodList[x].position.x > position.x) {
						if (minDistanceRight < 0 || GetRelativePosition(foodList[0]) < minDistanceRight) {
							right = minDistanceRight;
						}
					}
				}
				break;
			case 1:
				for (int x = 0; x < foodList.size(); x++) {
					if (foodList[x].position.y < position.y) {
						if (minDistanceLeft < 0 || GetRelativePosition(foodList[0]) < minDistanceLeft) {
							left = minDistanceLeft;
						}
					}

					if (foodList[x].position.y > position.y) {
						if (minDistanceRight < 0 || GetRelativePosition(foodList[0]) < minDistanceRight) {
							right = minDistanceRight;
						}
					}
				}
				break;
			case 0:
				break;
		}
	}
}

double Fish::GetRelativePosition(Food food) {
	Vector2 newPosition(position.x, position.y);
	Vector2 relativeSlope = (newPosition - food.position).Abs();

	return sqrt(pow(relativeSlope.x, 2) + pow(relativeSlope.y, 2));
}

int GetLine(double rotation) {
	if (rotation == 0 || (int)rotation % 180 == 0) return 1;
	if ((int)rotation % 90 == 0) return -1;

	return 0;
}

double GetSlope(double rotation) {
	if (rotation == 0 || (int)rotation % 90 == 0) return 0;
	return tan((rotation + 180) * M_PI / 180);
}