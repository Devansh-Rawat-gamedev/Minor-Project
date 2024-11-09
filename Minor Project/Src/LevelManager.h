#pragma once

#include <vector>
#include "./GameObjects/Block.h"
#include "./GameObjects/Ball.h"
#include "./GameObjects/Platform.h"

class LevelManager {
public:
    void reset();
    void checkCollisions(Ball& ball, Platform& platform);
    const std::vector<Block>& getBlocks() const { return blocks; }

private:
    std::vector<Block> blocks;
    static constexpr int NUM_BLOCKS_X = 10;
    static constexpr int NUM_BLOCKS_Y = 5;
};