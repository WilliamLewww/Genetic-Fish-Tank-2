#pragma once
#include "vector2.h"
#include "spritebatch.h"
#include "neuralnetwork.h"

struct Node {
	Neuron* neuron;
	Vector2 position;
	
	int value;
	int radius = 20, layer = -1;
};

struct Connection {
	Vector2 pointA;
	Vector2 pointB;

	double weight;
};

struct NodeNetwork {
	std::vector<Node> nodes;
	std::vector<Connection> connections;
};

void SetupNodeNetwork(NeuralNetwork network, NodeNetwork& nodeList);
void DrawNodeNetwork(NodeNetwork network, Vector2 position);