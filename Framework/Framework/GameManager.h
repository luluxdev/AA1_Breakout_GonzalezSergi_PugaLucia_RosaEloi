#pragma once
#include "defines.h"

class GameManager {
public:
	// GameManager class to manage the game state:
    int score;
    int multiplier;
    int attempts;
    char name[];

	// Constructor to initialize the game state:
    GameManager() {
        score = 0;
        multiplier = 0;
        attempts = 0;
    }
    
	// Function to add points to the score:
    void AddPoints() {
        score += POINTS + multiplier;
        multiplier += MULTIPLIER;
    }

	// Function to reset multiplier:
    void ResetMultiplier() {
        multiplier = 0;
    }

    // Lifes:
    void Attempts() {
        attempts++;
    }
};