#pragma once
#include <vector>
#include <time.h>

const double e = 2.71828182845904523536;

struct Synapse;

struct Neuron {
	double value = 0;
	std::vector<Synapse> synapseList;

	inline int hardlim() { if (value < 0) { return 0; } if (value >= 0) { return 1; } }
	inline int hardlims() { if (value < 0) { return -1; } if (value >= 0) { return 1; } }
	inline double purelin() { return value; }
	inline double satlin() { if (value < 0) { return 0; } if (value > 1) { return 0; } return value; }
	inline double satlins() { if (value < -1) { return -1; } if (value > 1) { return 1; } return value; }
	inline double logsig() { return 1 / (1 + std::pow(e, -value)); }
	inline double tansig() { return (std::pow(e, value) - std::pow(e, -value)) / (std::pow(e, value) + std::pow(e, -value)); }
	inline double poslin() { if (value < 0) { return 0; } return value; }
	inline double compet() { }
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