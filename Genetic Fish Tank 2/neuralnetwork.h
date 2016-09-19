#pragma once
#include <vector>
#include <time.h>

const double e = 2.71828182845904523536;

struct Synapse;

struct Neuron {
	double value = 0;
	std::vector<Synapse> synapseList;

	inline double Sigmoid() {
		return 1 / (1 + std::pow(e, -value));
	}
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
	std::vector<std::vector<Neuron>> hiddenLayer;
	std::vector<Neuron> outputLayer;
};

void SetupLayer(std::vector<Neuron>& layer, int count);
void SetupHiddenLayer(std::vector<std::vector<Neuron>>& layer, int layerCount, int neuronCount);
void SetupConnectionsRandom(NeuralNetwork& network);
void UpdateNetwork(NeuralNetwork& network);
void SetNeuron(NeuralNetwork& network, Neuron& neuron, double value);