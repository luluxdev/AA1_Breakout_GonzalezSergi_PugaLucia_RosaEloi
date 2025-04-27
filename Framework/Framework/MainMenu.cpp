#include "MenuScene.h"
#include "defines.h"

void MenuScene::Update()
{
	// Check if the user pressed any of the options:

	if (GetAsyncKeyState(FIRST_OPTION) != 0) {
		nextScene = "Ranking";
		finished = true;
	}
	else if (GetAsyncKeyState(SECOND_OPTION) != 0) {
		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState(THIRD_OPTION) != 0) {
		nextScene = "Credits";
		finished = true;
	}
}

// Function to set the title text:
void Title_printer() {

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << ".-. .-')  _  .-')     ('-.   ('-.    .-. .-')                            .-') _    " << std::endl;
	std::cout << "\\  ( OO )( \\( -O )  _(  OO) ( OO ).-.\\  ( OO )                          (  OO) )   " << std::endl;
	ConsoleSetColor(MAGENTA, BLACK);
	std::cout << " ;-----."; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "\\"; ConsoleSetColor(MAGENTA, BLACK); std::cout << " ,------. "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "("; ConsoleSetColor(MAGENTA, BLACK); std::cout << ",------."; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "/"; ConsoleSetColor(MAGENTA, BLACK); std::cout << " . --. "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "/"; ConsoleSetColor(MAGENTA, BLACK); std::cout << ",--. ,--.  "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << ".-')"; ConsoleSetColor(MAGENTA, BLACK); std::cout << ",-----.  ,--. ,--. "; 	ConsoleSetColor(DARKYELLOW, BLACK); std::cout << " /     '._  " << std::endl;	ConsoleSetColor(MAGENTA, BLACK);
	std::cout << " | .-.  | |   /`. ' |  .---'"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "| \\"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "-.  \\ |  .'   / "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "( OO'"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "  .-.  ' |  | |  |  |"; 	ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "'--...__) " << std::endl;	ConsoleSetColor(MAGENTA, BLACK);
	std::cout << " | '-' /"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "_)"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "|  /  | | |  |  "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << ".-'-'"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "  |  ||      /"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << ", /  "; ConsoleSetColor(MAGENTA, BLACK); std::cout << " |  | |  | |  | | "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << ".-')"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "'--.  .--' " << std::endl;
	std::cout << " | .-. `. |  |_.' |"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "("; ConsoleSetColor(MAGENTA, BLACK); std::cout << "|  '--."; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "\\"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "| |_.'  ||     ' "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "_)\\_) "; ConsoleSetColor(MAGENTA, BLACK); std::cout << "|  |"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "\\"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "|  | |  |_|"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "( OO )"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "  |  |    " << std::endl;
	std::cout << " | |  \\  ||  .  '.' |  .--' |  .-.  ||  .   \\   "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << " \\ "; ConsoleSetColor(MAGENTA, BLACK); std::cout << "|  | |  | |  | | "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "`-' /"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "  |  |    " << std::endl;
	std::cout << " | '--'  /|  |\\  \\  |  `---.|  | |  ||  |\\   \\   "; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << " `"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "'  '-'  '"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "("; ConsoleSetColor(MAGENTA, BLACK); std::cout << "'  '-'"; ConsoleSetColor(DARKYELLOW, BLACK); std::cout << "(_.-'"; ConsoleSetColor(MAGENTA, BLACK); std::cout << "   |  |    " << std::endl;
	std::cout << " `------' `--' '--' `------'`--' `--'`--' '--'      `-----'   `-----'      `--'    " << std::endl;
	ConsoleSetColor(BLUE, BLACK);

}

// Function to set the menu text:
void MenuScene::Render()
{
	Title_printer();
	std::cout << "\n\tMENU:" << std::endl;

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << "\t1.";
	ConsoleSetColor(BLUE, BLACK);
	std::cout << "Ranking" << std::endl;

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << "\t2.";
	ConsoleSetColor(BLUE, BLACK);
	std::cout << "Game" << std::endl;

	ConsoleSetColor(DARKYELLOW, BLACK);
	std::cout << "\t3.";
	ConsoleSetColor(BLUE, BLACK);
	std::cout << "Credits" << std::endl;

}