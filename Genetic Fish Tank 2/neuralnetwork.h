#pragma once
#include <vector>
#include <time.h>

const double e = 2.71828182845904523536;

struct Synapse;

struct Neuron {
	double value = 0;
	std::vector<Synapse> synapseList;
};

struct Synapse {
	Neuron* connectedNeuron;
	double weight;

	Synapse(Neuron* neuron, double weightParam) {
		connectedNeuron = neuron;
		weight = weightParam;
	}
};


struct NeuralNetwork {
	std::vector<Neuron> inputLayer;
	std::vector<Neuron> hiddenLayer;
	std::vector<Neuron> outputLayer;
};

void SetupLayer(std::vector<Neuron>& layer, int count);
void SetupConnectionsRandom(NeuralNetwork& network);
void UpdateNetwork(NeuralNetwork& network);