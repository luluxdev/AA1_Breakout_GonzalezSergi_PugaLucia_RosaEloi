#pragma once
#include "Scene.h"
#include <fstream>

class RankingScene : public Scene {
protected:
    //Vector of pairs-> 1st is a string a 2nd is the score
    //If you don't undestand std::pair<>, you can use another approach
    std::vector<std::pair<std::string, int>> scores;
    std::pair<std::string, int> newScore;
    std::fstream fileHandler;

    void OrderScores(std::vector<std::pair<std::string, int>>& list);

public:
    void AddNewScore(std::string playerName, int points);

    void LoadFromFile();
    void SaveToFile();

    RankingScene() {
        nextScene = "Menu";
        LoadFromFile();
    }

    ~RankingScene() {   SaveToFile();   }

    void Update() override;
    void Render() override;
};