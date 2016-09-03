#include "visualizer.h"

void SetupNodeNetwork(NeuralNetwork* network, NodeNetwork& nodeNetwork) {
	Node tempNode;

	for (int x = 0; x < network->inputLayer.size(); x++) {
		tempNode.layer = 0;
		tempNode.neuron = &network->inputLayer[x];
		tempNode.position = Vector2(
			-100, (x + 1) * (250 / (network->inputLayer.size() + 1))
		);

		nodeNetwork.nodes.push_back(tempNode);
	}

	for (int x = 0; x < network->hiddenLayer.size(); x++) {
		tempNode.layer = 1;
		tempNode.neuron = &network->hiddenLayer[x];
		tempNode.position = Vector2(
			0, (x + 1) * (250 / (network->hiddenLayer.size() + 1))
		);

		nodeNetwork.nodes.push_back(tempNode);
	}

	for (int x = 0; x < network->outputLayer.size(); x++) {
		tempNode.layer = 2;
		tempNode.neuron = &network->outputLayer[x];
		tempNode.position = Vector2(
			100, (x + 1) * (250 / (network->outputLayer.size() + 1))
		);

		nodeNetwork.nodes.push_back(tempNode);
	}

	Connection connection;

	int incrementNode = 0;
	for (int x = 0; x < nodeNetwork.nodes.size(); x++) {
		connection.pointA = nodeNetwork.nodes[x].position;
		while (incrementNode < nodeNetwork.nodes[x].neuron->synapseList.size()) {
			for (int y = 0; y < nodeNetwork.nodes.size(); y++) {
				if (nodeNetwork.nodes[x].neuron->synapseList[incrementNode].connectedNeuron == nodeNetwork.nodes[y].neuron) {
					connection.pointB = nodeNetwork.nodes[y].position;
					nodeNetwork.connections.push_back(connection);
				}
			}
			incrementNode += 1;
		}

		incrementNode = 0;
	}
}

void DrawNodeNetwork(NodeNetwork network, Vector2 position) {
	for (int x = 0; x < network.nodes.size(); x++) {
		DrawCircle(network.nodes[x].position + position - Vector2(0, 125), network.nodes[x].radius);
	}

	for (int x = 0; x < network.connections.size(); x++) {
		DrawLine(network.connections[x].pointA + position - Vector2(0, 125), network.connections[x].pointB + position - Vector2(0, 125));
	}
}