#include "food.h"

std::vector<Food> foodList;

Food::Food(Vector2 positionParam) {
	position = positionParam;
	width = 10;
	height = 10;
}

Food::Food(Vector2 positionParam, int widthParam, int heightParam) {
	position = positionParam;
	width = widthParam;
	height = heightParam;
}

void Food::Draw() {
	DrawRect(position, width, height);
}

void GenerateFood(int count) {
	foodList.push_back(Food(Vector2(rand() % (SCREENWIDTH - 10), rand() % (SCREENHEIGHT - 10))));
}

void DrawFood() {
	for (auto& food : foodList) {
		food.Draw();
	}
}