#include "visualizer.h"

void DrawNetwork(NeuralNetwork network, Vector2 position) {
	//cloudOriginalPosition[x] = x * (window.innerWidth / cloudCount) - 60;
	for (int x = 0; x < network.inputLayer.size(); x++) {
		DrawCircle(Vector2(
			-100 + (int)position.x, ((x + 1) * (250 / (network.inputLayer.size() + 1)) - 125) + (int)position.y
			), 20);
	}

	for (int x = 0; x < network.hiddenLayer.size(); x++) {
		DrawCircle(Vector2(
			(int)position.x, (x + 1) * (250 / (network.hiddenLayer.size() + 1)) - 125 + (int)position.y
			), 20);
	}

	for (int x = 0; x < network.outputLayer.size(); x++) {
		DrawCircle(Vector2(
			100 + (int)position.x, (x + 1) * (250 / (network.outputLayer.size() + 1)) - 125 + (int)position.y
		), 20);
	}
}