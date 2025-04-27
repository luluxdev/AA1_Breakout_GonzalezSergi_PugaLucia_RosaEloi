#pragma once  
#include "Scene.h"  
#include <map>  
#include "Wall.h"  
#include "Brick.h"  
#include "Pad.h"  
#include "Ball.h"  
#include "GameManager.h"  
#include "EndScene.h"  
#include "RankingScene.h"  

#define MAP_SIZE 15  

class GameplayScene : public Scene {  
protected:  
GameManager& gameManager;  
std::map<std::string, Scene*>& scenes;  
RankingScene* rankingScene;  

public:  
GameplayScene(GameManager& _gameManager, std::map<std::string, Scene*>& _scenes, RankingScene* _rankingScene)  
	: gameManager(_gameManager), scenes(_scenes), rankingScene(_rankingScene) {}  

virtual void OnEnter() override;  
virtual void Update() override;  
virtual void Render() override;  
virtual void OnExit() override;  
};
