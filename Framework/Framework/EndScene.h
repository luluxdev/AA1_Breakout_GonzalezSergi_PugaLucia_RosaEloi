#pragma once
#include "Scene.h"
#include "RankingScene.h"
#include "GameManager.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class EndScene : public Scene {
protected:

	// Variables:
	int userScore;
	std::string userName;
	RankingScene* ranking;
	// Bool to check if the user has already entered their name:
	bool askedName = false;


public:

	// Pointers:
	GameManager& gameManager;

	//Constructor:
	EndScene(RankingScene* rankingScene, std::string name, int score, GameManager& _gameManager)
		: ranking(rankingScene), userName(name), userScore(score), gameManager(_gameManager), askedName(false) {

		nextScene = "Menu";
	}

	//Destructor:
	~EndScene() = default;

	void Update() override;
	void Render() override;
};
