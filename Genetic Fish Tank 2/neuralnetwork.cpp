#include "neuralnetwork.h"

void SetupLayer(std::vector<Neuron>& layer, int count) {
	for (int x = 0; x < count; x++) {
		layer.push_back(Neuron());
	}
}

void SetupConnectionsRandom(NeuralNetwork& network) {
	for (int x = 0; x < network.inputLayer.size(); x++) {
		for (int y = 0; y < network.hiddenLayer.size(); y++) {
			network.inputLayer[x].synapseList.push_back(Synapse(network.hiddenLayer[y], double(rand() % 9 + 1) / 10));
		}
	}

	for (int x = 0; x < network.hiddenLayer.size(); x++) {
		for (int y = 0; y < network.outputLayer.size(); y++) {
			network.hiddenLayer[x].synapseList.push_back(Synapse(network.outputLayer[y], double(rand() % 9 + 1) / 10));
		}
	}
}