#include <Windows.h>
#include <iostream>

#include <cstdlib>
#include <time.h>

#include "MenuScene.h"
#include "GameplayScene.h"
#include "RankingScene.h"
#include "CreditsScene.h"
#include <map>

int main(){
	srand(time(NULL));

	//Set the console to be a fixed size:
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;

	//Create the game manager and the ranking scene:
	RankingScene* rankingScene = new RankingScene();
	GameManager* gameManager = new GameManager();

	//Create the scenes
	//Scenes are created with the map, the game manager and the ranking scene:
	scenes.emplace("Menu", new MenuScene(scenes, gameManager, rankingScene));
	scenes.emplace("Gameplay", new GameplayScene(*gameManager, scenes, rankingScene));
	scenes.emplace("Ranking", rankingScene);
	scenes.emplace("Credits", new CreditsScene());

	//Select the starting scene, in this case, the main menu
	currentScene = scenes["Menu"];
	currentScene->OnEnter();

	while (true) {

		//UPDATE
		currentScene->Update();

		//RENDER
		system("cls");
		ConsoleSetColor(WHITE, BLACK);
		currentScene->Render();

		//SCENE TRANSITIONING
		if (currentScene->IsFinished()) { //Check if the scene is finished

			currentScene->OnExit(); //IF finished, exit the scene
			if (currentScene->GetNextScene() == "Exit") { //IF the scene wants to go to "Exit", end the game
				return 0; //End the game
			}
			currentScene = scenes[currentScene->GetNextScene()]; //Select the next scene in the map with the string
			currentScene->OnEnter(); //Start the next scene
		}

		//CONTROL TIME (FPS)
		Sleep(100); //100ms sleep, 10 FPS
	}
}