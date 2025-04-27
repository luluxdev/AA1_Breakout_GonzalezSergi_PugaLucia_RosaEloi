#include "Pad.h"
#include "defines.h"

// Function to set the pad's position: 
void Pad::Update() {

	// Check for key presses and move the pad accordingly:
	if (GetAsyncKeyState(LEFT) != 0 || GetAsyncKeyState(VK_LEFT) & 0x8000) {
		bool isOutside = position.x - width <= 1;
		if (!isOutside)
			position.x--;
	}
	if (GetAsyncKeyState(RIGHT) != 0 || GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		bool isOutside = position.x + width >= mapSize - 2;
		if (!isOutside)
			position.x++;
	}
}

// Function to show the pad on the screen:
void Pad::Render() {

	GameObject::Render();
	
	for (int i = 1; i <= width; i++) {

		ConsoleXY(position.x + i, position.y);
		std::cout << charToPrint;

		ConsoleXY(position.x - i, position.y);
		std::cout << charToPrint;
	}
}
