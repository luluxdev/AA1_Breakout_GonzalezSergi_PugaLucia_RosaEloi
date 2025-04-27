#pragma once
#include "Pad.h"
#include "Wall.h"
#include "Brick.h"
#include "Scene.h"
#include "defines.h"
#include "GameObject.h"
#include "GameManager.h"
#include "GameplayScene.h"

#include <vector>

class Ball : public GameObject {
protected:
	Vector2 direction;
	std::vector<GameObject*> objects;

	// GameManager reference to manage game state:
	GameManager& gameManager;

	Vector2 CalculateCollision(GameObject* other);

public:

	// Included gameManager reference to manage game state:
	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects, GameManager& gm)
		: GameObject(_pos, BALL, YELLOW), objects(_objects), direction(Vector2(1, 1)), gameManager(gm) {

		// Objects are passed by reference to avoid copying:
		this->objects = objects;
	}
	void Update() override;
};
