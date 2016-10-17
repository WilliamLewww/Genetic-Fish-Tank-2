#pragma once
#include <vector>
#include <time.h>

const double e = 2.71828182845904523536;

struct Synapse;

struct Neuron {
	int transferValue = -1;
	double value = 0, bias = 0;
	std::vector<Synapse> synapseList;

	Neuron() { }
	Neuron(int transfer, double biasParam) { transferValue = transfer; bias = biasParam; }

	inline double TransferFunction(int type) {
		switch (type) {
			case -1:
				return value;
			case 0:
				///Hard Limit
				if (value < 0) { return 0; }
				if (value >= 0) { return 1; }
			case 1:
				///Symmetrical Hard Limit
				if (value < 0) { return -1; }
				if (value >= 0) { return 1; }
			case 2:
				///Linear
				return value;
			case 3:
				///Saturating Linear
				if (value < 0) { return 0; }
				if (value > 1) { return 0; }
				return value;
			case 4:
				///Symmetric Saturating Linear
				if (value < -1) { return -1; }
				if (value > 1) { return 1; }
				return value;
			case 5:
				///Log-Sigmoid
				return 1 / (1 + std::pow(e, -value));
			case 6:
				///Hyperbolic Tangent Sigmoid
				return (std::pow(e, value) - std::pow(e, -value)) / (std::pow(e, value) + std::pow(e, -value));
			case 7:
				///Positive Linear
				if (value < 0) { return 0; }
				return value;
			case 8:
				break;
				///Competitive
		}
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

void SetupLayer(std::vector<Neuron>& layer, int count, int transfer[], double bias[]);
void SetupLayer(std::vector<Neuron>& layer, int count, int transfer, double bias);
void SetupHiddenLayer(std::vector<std::vector<Neuron>>& layer, int layerCount, int neuronCount, int transfer[], double bias[]);
void SetupHiddenLayer(std::vector<std::vector<Neuron>>& layer, int layerCount, int neuronCount, int transfer, double bias);
void SetupConnectionsRandom(NeuralNetwork& network);
void UpdateNetwork(NeuralNetwork& network);
void SetNeuron(NeuralNetwork& network, Neuron& neuron, double value);