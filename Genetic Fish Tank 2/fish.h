#pragma once
#include "spritebatch.h"
#include "neuralnetwork.h"
#include "visualizer.h"
#include "food.h"
#include "input.h"

class Fish {
public:
	Vector2 position;
	int width, height; 
	double rotation;

	double range = 500;
	double closest = -1, closestLeft = -1, closestRight = -1;

	double fitnessDistance = -1;

	NeuralNetwork network;
	NodeNetwork nodeNetwork;

	Fish();
	Fish(Vector2 positionParam, int widthParam, int heightParam, double rotationParam);
	void LoadContent();
	void Update(int gameTime);
	void Draw();

	void GetClosestFood(std::vector<Food> foodList, double &left, double &right);
	double GetRelativePosition(Food food);
};

void GenerateFish(std::vector<Fish> &fishList, int count);
void DrawFish(std::vector<Fish> fishList);