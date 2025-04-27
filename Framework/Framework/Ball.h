#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "GameManager.h"
#include "Scene.h"
#include "GameplayScene.h"

#include <vector>

class Ball : public GameObject {
protected:
	Vector2 direction;
	std::vector<GameObject*> objects;
	GameManager& gameManager;

	Vector2 CalculateCollision(GameObject* other);

public:

	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects, GameManager& gm)
		: GameObject(_pos, '@', c), objects(_objects), direction(Vector2(1, 1)), gameManager(gm) {
		this->objects = objects;
	}
	void Update() override;
};
