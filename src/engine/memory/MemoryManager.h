//
// Created by crypt on 13/04/17.
//

#ifndef GAMEENGINE_MEMORY_H
#define GAMEENGINE_MEMORY_H


static const int _4MB = 4*1024*1024;

#include <cstddef>
#include <vector>
#include <cstdint>

struct MemoryBlock {
    void *start;
    uint32_t size;
    uint32_t position;
};

class MemoryManager {
private:
    const std::vector<MemoryBlock> completedBlocks;
    std::vector<MemoryBlock> blocks;

    MemoryBlock &getBlock(const size_t size);

public:
    ~MemoryManager();
    void *allocate(const size_t blockSize);

};


#endif //GAMEENGINE_MEMORY_H
