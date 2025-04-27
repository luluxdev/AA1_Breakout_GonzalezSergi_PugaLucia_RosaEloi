#pragma once  
#include "Scene.h"  
#include "GameManager.h"  
#include "RankingScene.h"  
#include <map>  

class MenuScene : public Scene {  
protected:

   // Attributes:
   std::map<std::string, Scene*>& scenes;  

   // New gameManager and rankingScene references:
   GameManager* gameManager;  
   RankingScene* rankingScene;  

public:  
	// Constructor:
   MenuScene(std::map<std::string, Scene*>& _scenes, GameManager* _gameManager, RankingScene* _rankingScene)  
       : scenes(_scenes), gameManager(_gameManager), rankingScene(_rankingScene) {}  

   void Update() override;  
   void Render() override;  
};