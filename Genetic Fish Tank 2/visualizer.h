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
	Node* nodeA;
	Node* nodeB;

	Vector2 pointA;
	Vector2 pointB;

	Connection(Node* nodeAParam, Node* nodeBParam) {
		nodeA = nodeAParam;
		nodeB = nodeBParam;

		pointA = nodeA->position;
		pointB = nodeB->position;
	}

	double weight;
};

struct NodeNetwork {
	std::vector<Node> nodes;
	std::vector<Connection> connections;
};

void SetupNodeNetwork(NeuralNetwork* network, NodeNetwork& nodeList);
void DrawNodeNetwork(NodeNetwork network, Vector2 position);