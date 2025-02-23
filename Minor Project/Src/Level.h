#pragma once
#include <vector>
#include "./GameObjects/Block.h"
#include "./GameObjects/Ball.h"
#include "./GameObjects/Platform.h"

class Level {
public:
    Level(int numBlocksX, int numBlocksY);  // Constructor
    virtual void reset();  // Reset the blocks and level setup
    std::vector<Block>& getBlocks();  // Returns a reference to the blocks vector

protected:
    int numBlocksX;
    int numBlocksY;

    std::vector<Block> blocks;  // Vector of blocks
};
