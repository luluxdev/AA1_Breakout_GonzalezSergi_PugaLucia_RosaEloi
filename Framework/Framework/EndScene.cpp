#include "EndScene.h"
#include "defines.h"

void EndScene::Update() {
	system("cls");

	if (!askedName) {

		// Ask the user for their name:
		std::cout << "Enter your name, player: ";
		std::cin >> userName;
		userScore = gameManager.score;

		// Add the score to the ranking:
		if (ranking)
			ranking->AddNewScore(userName, userScore);

		askedName = true;
	}
	else {

		// Check if the user pressed R to go back to the menu:
		if (GetAsyncKeyState(RETURN) != 0) {
			finished = true;
		}
	}
}

void EndScene::Render() {

	// If the user has not entered their name, show the prompt:
	if (!askedName) {
		std::cout << "GAME OVER :c\n";
		std::cout << "Enter your name, player.\n";
		std::cout << "Your score is: " << gameManager.score << "\n";
	}
	// Then, show the score and go back to the menu:
	else {
		std::cout << "Thanks " << userName << ". Your score has been saved.\n";
		std::cout << "Your score is: " << gameManager.score << "\n";
		std::cout << "Press R to go back to the menu;";

	}
}
