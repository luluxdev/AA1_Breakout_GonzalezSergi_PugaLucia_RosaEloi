#include "MenuScene.h"

void MenuScene::Update()
{
	if (GetAsyncKeyState('1') != 0) {
		nextScene = "Ranking"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
	else if (GetAsyncKeyState('2') != 0) {
		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState('3') != 0) {
		nextScene = "Exit";
		finished = true;
	}
	else {
		for (int key = 0x30; key <= 0x5A; key++) { // 0x30 - 0x5A cubre números y letras
			if (GetAsyncKeyState(key) & 0x8000) {
				std::cout << "Tecla presionada: " << (char)key << std::endl;
			}
		}
		Sleep(100);
	}
}
void Title_printer() {

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << ".-. .-')  _  .-')     ('-.   ('-.    .-. .-')                            .-') _    " << std::endl;
	std::cout << "\\  ( OO )( \\( -O )  _(  OO) ( OO ).-.\\  ( OO )                          (  OO) )   " << std::endl;
	ConsoleSetColor(MAGENTA, BLACK);
	std::cout << " ;-----.\\ ,------. (,------./ . --. /,--. ,--.  .-'),-----.  ,--. ,--.  /     '._  " << std::endl;
	std::cout << " | .-.  | |   /`. ' |  .---'| \\-.  \\ |  .'   / ( OO'  .-.  ' |  | |  |  |'--...__) " << std::endl;
	std::cout << " | '-' /_)|  /  | | |  |  .-'-'  |  ||      /, /   |  | |  | |  | | .-')'--.  .--' " << std::endl;
	std::cout << " | .-. `. |  |_.' |(|  '--.\\| |_.'  ||     ' _)\\_) |  |\\|  | |  |_|( OO )  |  |    " << std::endl;
	std::cout << " | |  \\  ||  .  '.' |  .--' |  .-.  ||  .   \\    \\ |  | |  | |  | | `-' /  |  |    " << std::endl;
	std::cout << " | '--'  /|  |\\  \\  |  `---.|  | |  ||  |\\   \\    `'  '-'  '('  '-'(_.-'   |  |    " << std::endl;
	std::cout << " `------' `--' '--' `------'`--' `--'`--' '--'      `-----'   `-----'      `--'    " << std::endl;
	ConsoleSetColor(WHITE, BLACK);
}


void MenuScene::Render()
{
	Title_printer();
	std::cout << "MENU:" << std::endl;
	std::cout << "1.Ranking" << std::endl;
	std::cout << "2.Game" << std::endl;
	std::cout << "3.Credits" << std::endl;

}