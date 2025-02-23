#include "Level.h"
#include <cmath>
#include "LevelManager.h"
#include "Game.h"

Level::Level(int numBlocksX, int numBlocksY)
    : numBlocksX(numBlocksX), numBlocksY(numBlocksY) {
}

void Level::reset() {
    blocks.clear();  // Clear any existing blocks
    float blockWidth = WINDOW_WIDTH / numBlocksX;
    float blockHeight = 20.0f;
    for (int i = 0; i < numBlocksY; ++i) {
        for (int j = 0; j < numBlocksX; ++j) {
            Block block;
            block.setX(j * blockWidth + blockWidth / 2);
            block.setY(i * blockHeight + blockHeight / 2 + 50);
            blocks.push_back(block);
        }
    }
}

std::vector<Block>& Level::getBlocks() {
    return blocks;  
}
