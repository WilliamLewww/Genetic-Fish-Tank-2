#pragma once
#include "spritebatch.h"
#include <vector>
class Food {
public:
	Vector2 position;
	int width, height;

	Food(Vector2 positionParam);
	Food(Vector2 positionParam, int widthParam, int heightParam);
	void Draw();
};
extern std::vector<Food> foodList;

void GenerateFood(int count);
void DrawFood();