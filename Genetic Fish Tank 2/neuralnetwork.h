#pragma once
#include <vector>
#include <cstdio>
#include <iostream>

struct Synapse;

struct Neuron {
	int value;
	std::vector<Synapse> synapseList;
};

struct Synapse {
	Neuron* connectedNeuron;
	double weight;

	Synapse(Neuron neuron, double weightParam) {
		connectedNeuron = &neuron;
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