#include "visualizer.h"

void SetupNodeNetwork(NeuralNetwork* network, NodeNetwork& nodeNetwork) {
	Node tempNode;

	for (int x = 0; x < network->inputLayer.size(); x++) {
		tempNode.neuron = &network->inputLayer[x];
		tempNode.position = Vector2(
			-100, (x + 1) * (250 / (network->inputLayer.size() + 1))
		);

		nodeNetwork.nodes.push_back(tempNode);
	}

	for (int x = 0; x < network->hiddenLayer.size(); x++) {
		for (int y = 0; y < network->hiddenLayer[x].size(); y++) {
			tempNode.neuron = &network->hiddenLayer[x][y];
			tempNode.position = Vector2(
				0, (y + 1) * (250 / (network->hiddenLayer[x].size() + 1))
			);

			nodeNetwork.nodes.push_back(tempNode);
		}
	}

	for (int x = 0; x < network->outputLayer.size(); x++) {
		tempNode.neuron = &network->outputLayer[x];
		tempNode.position = Vector2(
			100, (x + 1) * (250 / (network->outputLayer.size() + 1))
		);

		nodeNetwork.nodes.push_back(tempNode);
	}

	int incrementNode = 0;
	for (int x = 0; x < nodeNetwork.nodes.size(); x++) {
		while (incrementNode < nodeNetwork.nodes[x].neuron->synapseList.size()) {
			for (int y = 0; y < nodeNetwork.nodes.size(); y++) {
				if (nodeNetwork.nodes[x].neuron->synapseList[incrementNode].connectedNeuron == nodeNetwork.nodes[y].neuron) {
					nodeNetwork.connections.push_back(Connection(&nodeNetwork.nodes[x], &nodeNetwork.nodes[y], nodeNetwork.nodes[x].neuron->synapseList[incrementNode].weight));
				}
			}
			incrementNode += 1;
		}

		incrementNode = 0;
	}
}

double* GetVisualColor(double value) {
	double color[3];
	color[0] = ConvertColor((1.0 - value) * 255);
	color[1] = ConvertColor(value * 255);
	color[2] = 0;

	return color;
}

void DrawNodeNetwork(NodeNetwork network, Vector2 position) {
	for (int x = 0; x < network.nodes.size(); x++) {
		double color[3];
		color[0] = *GetVisualColor(network.nodes[x].neuron->value);
		color[1] = *(GetVisualColor(network.nodes[x].neuron->value) + 1);
		color[2] = *(GetVisualColor(network.nodes[x].neuron->value) + 2);
		DrawCircle(network.nodes[x].position + position - Vector2(0, 125), network.nodes[x].radius, color);
	}

	//Color based on Weight
	for (int x = 0; x < network.connections.size(); x++) {
		double color[3];
		color[0] = *GetVisualColor(network.connections[x].weight);
		color[1] = *(GetVisualColor(network.connections[x].weight) + 1);
		color[2] = *(GetVisualColor(network.connections[x].weight) + 2);
		DrawLine(network.connections[x].pointA + position - Vector2(-network.connections[x].nodeA->radius, 125), network.connections[x].pointB + position - Vector2(network.connections[x].nodeB->radius, 125), color);
	}
}