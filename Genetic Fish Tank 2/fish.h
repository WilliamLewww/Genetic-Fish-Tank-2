#pragma once
#include "spritebatch.h"
#include "neuralnetwork.h"
#include "visualizer.h"

class Fish {
public:
	Vector2 position;
	int width, height; 
	double rotation;

	NeuralNetwork network;
	NodeNetwork nodeNetwork;

	Fish();
	Fish(Vector2 positionParam, int widthParam, int heightParam, double rotationParam);
	void LoadContent();
	void Update(int gameTime);
	void Draw();
};

