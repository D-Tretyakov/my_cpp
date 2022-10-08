#include <iostream>
#include "lru_cache.h"

LRUCache::LRUCache()
{
    std::cout << "LRUCache created" << std::endl;
}

int main()
{
    LRUCache<int> cache;
    return 0;
}