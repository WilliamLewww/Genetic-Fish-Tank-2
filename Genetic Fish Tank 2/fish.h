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
	double closestLeft = -1, closestRight = -1;

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

