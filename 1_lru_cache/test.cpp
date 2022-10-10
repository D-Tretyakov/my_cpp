#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include "lru_cache.h"

TEST(LRUCacheTest, InitZeroSize) 
{
    EXPECT_THROW(LRUCache<int> cache{0}, std::runtime_error);
}

TEST(LRUCacheTest, SimpleOne)
{
    LRUCache<int> cache{10};

    for (int i = 0; i <= 11; i++)
        cache.update(i);
    
    using namespace testing;
    ASSERT_THAT(
        cache.get_state(), 
        ElementsAre(11, 10, 9, 8, 7, 6, 5, 4, 3, 2)
    );
}