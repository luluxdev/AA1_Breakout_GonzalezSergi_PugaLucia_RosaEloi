#include "EndScene.h"
#include <iostream>
#include <vector>
#include <algorithm>

void EndScene::Update() {
	system("cls");
	if (!askedName) {
		std::cout << "Introduce tu nombre de jugador: ";
		std::cin >> userName;

		userScore = gameManager.score;

		if (ranking)
			ranking->AddNewScore(userName, userScore);


		askedName = true;


	}
	else {
		// Esperar a que el jugador presione una tecla para continuar
		if (GetAsyncKeyState('R') != 0) {
			finished = true;
		}
	}
}

void EndScene::Render() {
	if (!askedName) {
		std::cout << "==== GAME OVER ====\n";
		std::cout << "Introduce tu nombre para guardar la puntuación.\n";
	}
	else {
		std::cout << "Gracias " << userName << ". Tu puntuación ha sido guardada.\n";
		std::cout << "Press R to go back to the menu;";

	}
}
