#pragma once
#include "neuralnetwork.h"
#include <iostream>
class Fish {
public:
	NeuralNetwork network;

	Fish();
	void LoadContent();
	void Update(int gameTime);
	void Draw();
};

