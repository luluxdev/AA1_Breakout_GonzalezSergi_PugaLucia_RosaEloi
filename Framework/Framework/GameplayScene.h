#pragma once  
#include "Scene.h"  
#include "Wall.h"  
#include "Brick.h"  
#include "Pad.h"  
#include "Ball.h"  
#include "defines.h"
#include "EndScene.h"
#include "GameManager.h"
#include "RankingScene.h"  

#include <map>  


class GameplayScene : public Scene {  
protected:

	// Game objects:
	GameManager& gameManager;  
	std::map<std::string, Scene*>& scenes;  
	RankingScene* rankingScene;  

public:
	// Constructor:
	GameplayScene(GameManager& _gameManager, std::map<std::string, Scene*>& _scenes, RankingScene* _rankingScene)  
		: gameManager(_gameManager), scenes(_scenes), rankingScene(_rankingScene) {}  

	virtual void OnEnter() override;  
	virtual void Update() override;  
	virtual void Render() override;  
	virtual void OnExit() override;  
};
