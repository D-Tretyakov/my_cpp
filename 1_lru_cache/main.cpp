#include "lru_cache.h"
#include <vector>

int main()
{
    std::vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    LRUCache<int> cache {10};
    for (const auto& value : values)
        cache.update(value);

    cache.debug_print();

    return 0;
}
