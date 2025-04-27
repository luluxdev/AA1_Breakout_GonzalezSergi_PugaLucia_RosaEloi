#pragma once
#include "GameObject.h"
#include "defines.h"

class Wall : public GameObject {
protected:
	bool isBottom;
public:
	Wall(Vector2 pos, ConsoleColor c, bool b)
		: GameObject(pos, WALL, DARKYELLOW), isBottom(b) {}

	bool GetIsBottom()  { return isBottom; }
};

