#pragma once
#include "GameObject.h"
#include <vector>
#include <string>

class Scene {
protected:
	std::vector<GameObject*> objects;
	std::string nextScene;
	bool finished;

public:
	Scene() {
		nextScene = "Exit";
		finished = false;
	}

	virtual void OnEnter() { finished = false; }
	virtual void Update() {
		for (GameObject* o : objects) {
			o->Update();
		}
	}
	virtual void Render() {
		for (GameObject* o : objects) {
			o->Render();
		}
	}

	virtual void OnExit() {}

	bool IsFinished() const { return finished; }
	std::string GetNextScene() const { return nextScene; }
};