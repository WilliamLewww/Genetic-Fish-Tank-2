#include "spritebatch.h"

void DrawTriangle(Vector2 position, int width, int height) {
	Vector2 vectors[3]{
		Vector2(0, 0),
		Vector2(.5, 1),
		Vector2(1, 0),
	};

	glBegin(GL_TRIANGLES);
	glColor4f(0, 0, 0, 1);
	for (int x = 0; x < 3; x++) {
		vectors[x].x *= width;
		vectors[x].y *= height;
		vectors[x] += Vector2(position.x, position.y);
		vectors[x] -= Vector2(SCREENWIDTH / 2, SCREENHEIGHT / 2);

		glVertex2d(vectors[x].x, vectors[x].y);
	}
	glEnd();
}

void DrawTriangle(Vector2 position, int width, int height, double angle) {
	Vector2 vectors[3]{
		Vector2(0, 0),
		Vector2(.5, 1),
		Vector2(1, 0),
	};

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(position.x + (width / 2) - (SCREENWIDTH / 2), position.y + (height / 2) - (SCREENHEIGHT / 2), 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-(position.x + (width / 2) - (SCREENWIDTH / 2)), -(position.y + (height / 2) - (SCREENHEIGHT / 2)), 0);
	glBegin(GL_TRIANGLES);
	glColor4f(0, 0, 0, 1);
	for (int x = 0; x < 3; x++) {
		vectors[x].x *= width;
		vectors[x].y *= height;
		vectors[x] += Vector2(position.x, position.y);
		vectors[x] -= Vector2(SCREENWIDTH / 2, SCREENHEIGHT / 2);

		glVertex2d(vectors[x].x, vectors[x].y);
	}
	glEnd();
	glPopMatrix();
}