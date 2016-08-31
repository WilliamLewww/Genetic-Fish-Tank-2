#include "vector2.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(double xArgs, double yArgs) {
	x = xArgs;
	y = yArgs;
}

void Vector2::Normalize() {
	// | a | = sqrt((ax * ax) + (ay * ay) + (az * az))
	// x = ax / | a |
	// y = ay / | a |
	// z = az / | a |
	int magnitude = abs(sqrt((x * x) + (y * y)));

	if (magnitude != 0) {
		x = x / magnitude;
		y = y / magnitude;
	}
}

Vector2 Vector2::operator*(Vector2 vector) {
	Vector2 newVector(x *= vector.x, y *= vector.y);
	return newVector;
}

Vector2 Vector2::operator*(double value) {
	Vector2 newVector(x *= value, y *= value);
	return newVector;
}

Vector2 Vector2::operator+(Vector2 vector) {
	Vector2 newVector(x += vector.x, y += vector.y);
	return newVector;
}

Vector2 Vector2::operator+=(Vector2 vector) {
	Vector2 newVector(x += vector.x, y += vector.y);
	return newVector;
}

Vector2 Vector2::operator-=(Vector2 vector) {
	Vector2 newVector(x -= vector.x, y -= vector.y);
	return newVector;
}

bool Vector2::operator==(Vector2 vector) {
	if (x == vector.x && y == vector.y) return true;
	return false;
}

bool Vector2::operator!=(Vector2 vector) {
	if (x != vector.x || y != vector.y) return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, Vector2 const &m) {
	return os << m.x << "," << m.y;
}