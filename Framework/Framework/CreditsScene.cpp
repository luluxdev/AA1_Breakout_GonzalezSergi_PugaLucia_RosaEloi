#include "CreditsScene.h"

void CreditsScene::Update() {

	if (GetAsyncKeyState('R') != 0) {

		nextScene = "Menu";
		finished = true;
	}
}

void CreditsScene::Render() {

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << "\t\t  ___  ____  ____  ____  ____  ____  ___ " << std::endl;
	std::cout << "\t\t / __)(  _ \\( ___)(  _ \\(_  _)(_  _)/ __)" << std::endl;
	std::cout << "\t\t( (__  )   / )__)  )(_) )_)(_   )(  \\__ \\" << std::endl;
	std::cout << "\t\t \\___)(_)\\_)(____)(____/(____) (__) (___/" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ConsoleSetColor(MAGENTA, BLACK);
	std::cout << "\t\tLUCIA PUGA! <3" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ConsoleSetColor(BLUE, BLACK);
	std::cout << "\t\tSERGI GONZALEZ!!!!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ConsoleSetColor(GREEN, BLACK);
	std::cout << "\t\tELOI ROSA~~" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ConsoleSetColor(WHITE, BLACK);
	std::cout << "\tPress R to go back..." << std::endl;


}