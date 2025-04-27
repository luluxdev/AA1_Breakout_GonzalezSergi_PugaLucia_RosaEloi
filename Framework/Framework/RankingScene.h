#pragma once
#include "Scene.h"
#include <fstream>

class RankingScene : public Scene {
protected:
    std::vector<std::pair<std::string, int>> scores;

	// The new score to be added:
    std::pair<std::string, int> newScore;
	// The file name where the scores are saved:
    std::fstream fileHandler;

    // Function to sort the scores:
    void OrderScores(std::vector<std::pair<std::string, int>>& list);

public:
	// Function to add a new score:
    void AddNewScore(std::string playerName, int points);
	// Function to load scores from a file:
    void LoadFromFile();
	// Function to save scores to a file:
    void SaveToFile();

    RankingScene() {
        nextScene = "Menu";
		// Function to load scores from a file:
        LoadFromFile();
    }

	// Destructor:
    ~RankingScene() {   SaveToFile();   }

    void Update() override;
    void Render() override;
};