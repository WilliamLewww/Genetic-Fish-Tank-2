#include "fish.h"

Fish::Fish(){

}

void Fish::LoadContent() {
	SetupLayer(network.inputLayer, 2);
	SetupLayer(network.hiddenLayer, 3);
	SetupLayer(network.outputLayer, 1);
	SetupConnectionsRandom(network);
}

void Fish::Update(int gameTime) {

}

void Fish::Draw() {

}