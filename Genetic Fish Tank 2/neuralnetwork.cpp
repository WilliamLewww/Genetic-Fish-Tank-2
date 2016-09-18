#include "neuralnetwork.h"

void SetupLayer(std::vector<Neuron>& layer, int count) {
	for (int x = 0; x < count; x++) {
		layer.push_back(Neuron());
	}
}

void SetupConnectionsRandom(NeuralNetwork& network) {
	srand(time(NULL));
	for (int x = 0; x < network.inputLayer.size(); x++) {
		for (int y = 0; y < network.hiddenLayer.size(); y++) {
			network.inputLayer[x].synapseList.push_back(Synapse(&network.hiddenLayer[y], double(rand() % 9 + 1) / 10));
		}
	}

	for (int x = 0; x < network.hiddenLayer.size(); x++) {
		for (int y = 0; y < network.outputLayer.size(); y++) {
			network.hiddenLayer[x].synapseList.push_back(Synapse(&network.outputLayer[y], double(rand() % 9 + 1) / 10));
		}
	}
}

void UpdateNetwork(NeuralNetwork& network) {
	for (int x = 0; x < network.inputLayer.size(); x++) {
		for (int y = 0; y < network.inputLayer[x].synapseList.size(); y++) {
			network.inputLayer[x].synapseList[y].connectedNeuron->value += double(network.inputLayer[x].synapseList[y].weight * network.inputLayer[x].value);
		}
	}

	for (int x = 0; x < network.hiddenLayer.size(); x++) {
		for (int y = 0; y < network.hiddenLayer[x].synapseList.size(); y++) {
			network.hiddenLayer[x].synapseList[y].connectedNeuron->value += double(network.hiddenLayer[x].synapseList[y].weight * network.hiddenLayer[x].Sigmoid());
		}
	}
}

void SetNeuron(NeuralNetwork& network, Neuron& neuron, double value) {
	neuron.value = value;
	UpdateNetwork(network);
}