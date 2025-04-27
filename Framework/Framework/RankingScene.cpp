#include "RankingScene.h"
#include "defines.h"

// Load the scores from a binary file ("scores.bin"):
void RankingScene::LoadFromFile() {

    fileHandler.open("scores.bin", std::ios::binary | std::ios::in);

    if (fileHandler) {
        size_t total;

        // Read the total number of scores:
		fileHandler.read((char*)&total, sizeof(size_t));

        for (size_t i = 0; i < total; i++) {
			// Read the length of the player's name
            size_t len;
            fileHandler.read((char*)&len, sizeof(size_t));

            std::string name;
            name.resize(len);
            fileHandler.read(&name[0], len);

			// Read the player's name
            int points;
            fileHandler.read((char*)&points, sizeof(int));

            // Add the player name and points to the scores vector
			scores.push_back(std::make_pair(name, points));
        }
        fileHandler.close();
    }
}

// Save the current scores to a binary file ("scores.bin"):
void RankingScene::SaveToFile() {
    fileHandler.open("scores.bin", std::ios::binary | std::ios::out | std::ios::trunc);

    if (fileHandler) {
        size_t count = scores.size();

        // Write the total number of scores:
		fileHandler.write((const char*)&count, sizeof(size_t));

        for (const auto& player : scores) {
            size_t nameLen = player.first.length();

            // Write the length of the player's name
			fileHandler.write((const char*)&nameLen, sizeof(size_t));

            // Write the player's name
			fileHandler.write(player.first.c_str(), nameLen);

			// Write the player's points
			fileHandler.write((const char*)&player.second, sizeof(int));
        }
        fileHandler.close();
    }
}

// Sort the scores in descending order based on the points:
void RankingScene::OrderScores(std::vector<std::pair<std::string, int>>& list) {

    bool changed;

    do {
        changed = false;

		// Compare each pair of adjacent elements in the list:
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

// Add a new score to 'scores' vector:
void RankingScene::AddNewScore(std::string playerName, int points) {

    newScore.first = playerName;
    newScore.second = points;

    scores.push_back(newScore);

    OrderScores(scores);
    SaveToFile();
}

// Update the scene state:
void RankingScene::Update()
{
    if (GetAsyncKeyState(RETURN) != 0) {
        finished = true;
    }
}

// Render the scores to the console:
void RankingScene::Render()
{
    ConsoleSetColor(DARKYELLOW, BLACK);
    std::cout << "\t\t  _____            _   _ _  _______ _   _  _____ " << std::endl;
    std::cout << "\t\t |  __ \\     /\\   | \\ | | |/ /_   _| \\ | |/ ____|" << std::endl;
    std::cout << "\t\t | |__) |   /  \\  |  \\| | ' /  | | |  \\| | |  __ " << std::endl;
    std::cout << "\t\t |  _  /   / /\\ \\ | . ` |  <   | | | . ` | | |_ |" << std::endl;
    std::cout << "\t\t | | \\ \\  / ____ \\| |\\  | . \\ _| |_| |\\  | |__| |" << std::endl;
    std::cout << "\t\t |_|  \\_\\/_/    \\_\\_| \\_|_|\\_\\_____|_| \\_|\\_____|" << std::endl << std::endl;

    ConsoleSetColor(WHITE, BLACK);
    for (const auto& entry : scores) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    std::cout << std::endl << "Press R to go back to the menu;";
}


