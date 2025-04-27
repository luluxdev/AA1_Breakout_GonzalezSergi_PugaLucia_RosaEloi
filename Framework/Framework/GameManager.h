#pragma once

#define POINTS 15
class GameManager {
public:
    int score;
    int multiplier;
    int attempts;
    char name[];

    GameManager() {
        score = 0;
        multiplier = 0;
        attempts = 0;
    }
    void AddPoints() {
        score += POINTS + multiplier;
        multiplier += 5;
    }
    void ResetMultiplier() {
        multiplier = 0;
    }
    void Attempts() {
        attempts++;
    }
};