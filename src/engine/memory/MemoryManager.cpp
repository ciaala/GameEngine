//
// Created by crypt on 13/04/17.
//

#include <cstdlib>
#include "MemoryManager.h"

void *MemoryManager::allocate(const size_t blockSize) {
    MemoryBlock &memoryBlock = this->getBlock(blockSize);
    void *address = memoryBlock.start;
    //address += memoryBlock;
    memoryBlock.position += blockSize;
    if (memoryBlock.position == memoryBlock.size) {

        //    this->completedBlocks.push_back(MemoryBlock(memoryBlock));
    }
    return address;
}

MemoryBlock &MemoryManager::getBlock(const size_t size) {
    for (auto &&item : blocks) {
        if ((item.size - item.position) > size) {
            return item;
        }
    }
    blocks.emplace_back();
    MemoryBlock &block = blocks.back();
    block.size = _4MB;
    while (block.size < size) {
        block.size *= 2;
    }
    block.start = malloc(block.size);
    block.position = 0;
    return block;
}

MemoryManager::~MemoryManager() {
    for (auto &&item : completedBlocks) {
        free(item.start);
    }
    for (auto &&item : blocks) {
        free(item.start);
    }
}
