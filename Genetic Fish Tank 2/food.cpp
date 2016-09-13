#include "food.h"

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

}