#pragma once
#include "neuralnetwork.h"
#include "spritebatch.h"
#include <iostream>
class Fish {
public:
	Vector2 position;
	int width, height; 
	double rotation;

	NeuralNetwork network;

	Fish();
	Fish(Vector2 positionParam, int widthParam, int heightParam, double rotationParam);
	void LoadContent();
	void Update(int gameTime);
	void Draw();
};

