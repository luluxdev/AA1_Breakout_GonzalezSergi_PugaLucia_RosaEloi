#include "RankingScene.h"

void RankingScene::LoadFromFile() {
    fileHandler.open("scores.bin", std::ios::binary | std::ios::in);
    if (fileHandler) {
        size_t total;
        fileHandler.read((char*)&total, sizeof(size_t));

        for (size_t i = 0; i < total; i++) {
            size_t len;
            fileHandler.read((char*)&len, sizeof(size_t));

            std::string name;
            name.resize(len);
            fileHandler.read(&name[0], len);

            int points;
            fileHandler.read((char*)&points, sizeof(int));

            scores.push_back(std::make_pair(name, points));
        }
        fileHandler.close();
    }
}

void RankingScene::SaveToFile() {
    fileHandler.open("scores.bin", std::ios::binary | std::ios::out | std::ios::trunc);
    if (fileHandler) {
        size_t count = scores.size();
        fileHandler.write((const char*)&count, sizeof(size_t));

        for (const auto& player : scores) {
            size_t nameLen = player.first.length();
            fileHandler.write((const char*)&nameLen, sizeof(size_t));
            fileHandler.write(player.first.c_str(), nameLen);
            fileHandler.write((const char*)&player.second, sizeof(int));
        }
        fileHandler.close();
    }
}

void RankingScene::OrderScores(std::vector<std::pair<std::string, int>>& list) {
    bool changed;
    do {
        changed = false;
        for (size_t i = 0; i < list.size() - 1; i++) {
            if (list[i].second < list[i + 1].second) {
                auto temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                changed = true;
            }
        }
    } while (changed);
}

void RankingScene::AddNewScore(std::string playerName, int points) {
    newScore.first = playerName;
    newScore.second = points;
    scores.push_back(newScore);
    OrderScores(scores);
    SaveToFile();
}

void RankingScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void RankingScene::Render()
{
    for (const auto& entry : scores) {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
	std::cout << "Press R to go back to the menu;";
}
