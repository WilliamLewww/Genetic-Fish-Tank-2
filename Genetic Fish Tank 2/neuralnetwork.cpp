#include "neuralnetwork.h"
#include <iostream>

void SetupLayer(std::vector<Neuron>& layer, int count, int transfer[]) {
	for (int x = 0; x < count; x++) {
		layer.push_back(Neuron(transfer[x]));
	}
}

void SetupLayer(std::vector<Neuron>& layer, int count, int transfer) {
	for (int x = 0; x < count; x++) {
		layer.push_back(Neuron(transfer));
	}
}

void SetupHiddenLayer(std::vector<std::vector<Neuron>>& layer, int layerCount, int neuronCount, int transfer[]) {
	for (int x = 0; x < layerCount; x++) {
		std::vector<Neuron> tempLayer;
		for (int y = 0; y < neuronCount; y++) {
			tempLayer.push_back(Neuron(transfer[(x * neuronCount) + y]));
		}
		layer.push_back(tempLayer);
	}
}

void SetupHiddenLayer(std::vector<std::vector<Neuron>>& layer, int layerCount, int neuronCount, int transfer) {
	for (int x = 0; x < layerCount; x++) {
		std::vector<Neuron> tempLayer;
		for (int y = 0; y < neuronCount; y++) {
			tempLayer.push_back(Neuron(transfer));
		}
		layer.push_back(tempLayer);
	}
}

void SetupConnectionsRandom(NeuralNetwork& network) {
	srand(time(NULL));
	for (int x = 0; x < network.inputLayer.size(); x++) {
		for (int y = 0; y < network.hiddenLayer[0].size(); y++) {
			network.inputLayer[x].synapseList.push_back(Synapse(&network.hiddenLayer[0][y], double(rand() % 19 + (-9)) / 10));
		}
	}

	for (int z = 0; z < network.hiddenLayer.size() - 1; z++) {
		for (int x = 0; x < network.hiddenLayer[z].size(); x++) {
			for (int y = 0; y < network.hiddenLayer[z + 1].size(); y++) {
				network.hiddenLayer[z][x].synapseList.push_back(Synapse(&network.hiddenLayer[z + 1][y], double(rand() % 19 + (-9)) / 10));
			}
		}
	}

	for (int x = 0; x < network.hiddenLayer[network.hiddenLayer.size() - 1].size(); x++) {
		for (int y = 0; y < network.outputLayer.size(); y++) {
			network.hiddenLayer[network.hiddenLayer.size() - 1][x].synapseList.push_back(Synapse(&network.outputLayer[y], double(rand() % 19 + (-9)) / 10));
		}
	}
}

void UpdateNetwork(NeuralNetwork& network) {
	for (int x = 0; x < network.inputLayer.size(); x++) {
		for (int y = 0; y < network.inputLayer[x].synapseList.size(); y++) {
			network.inputLayer[x].synapseList[y].connectedNeuron->value = 0;
			network.inputLayer[x].synapseList[y].connectedNeuron->value += double(network.inputLayer[x].synapseList[y].weight * network.inputLayer[x].value);
			network.inputLayer[x].synapseList[y].connectedNeuron->value = network.inputLayer[x].synapseList[y].connectedNeuron->TransferFunction(network.inputLayer[x].synapseList[y].connectedNeuron->transferValue);
		}
	}

	for (int z = 0; z < network.hiddenLayer.size(); z++) {
		for (int x = 0; x < network.hiddenLayer[z].size(); x++) {
			for (int y = 0; y < network.hiddenLayer[z][x].synapseList.size(); y++) {
				network.hiddenLayer[z][x].synapseList[y].connectedNeuron->value = 0;
				network.hiddenLayer[z][x].synapseList[y].connectedNeuron->value += double(network.hiddenLayer[z][x].synapseList[y].weight * network.hiddenLayer[z][x].value);
				network.hiddenLayer[z][x].synapseList[y].connectedNeuron->value = network.hiddenLayer[z][x].synapseList[y].connectedNeuron->TransferFunction(network.hiddenLayer[z][x].synapseList[y].connectedNeuron->transferValue);
			}
		}
	}
}

void SetNeuron(NeuralNetwork& network, Neuron& neuron, double value) {
	neuron.value = value;
	UpdateNetwork(network);
}