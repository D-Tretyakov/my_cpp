#include <random>
#include <iostream>

#include "gmock/gmock.h"
#include <gtest/gtest.h>

#include "lru_cache.h"

TEST(LRUCacheTest, InitZeroSize) 
{
    EXPECT_THROW(LRUCache<int> cache{0}, std::runtime_error);
}

TEST(LRUCacheTest, ValuesMoreThanSize)
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

TEST(LRUCacheTest, ValuesLessThanSize)
{
    LRUCache<int> cache{10};

    for (int i = 0; i < 4; i++)
        cache.update(i);
    
    using namespace testing;
    ASSERT_THAT(
        cache.get_state(), 
        ElementsAre(3, 2, 1, 0)
    );
}

TEST(LRUCacheTest, MillionValues)
{
    LRUCache<int> cache{10};
    std::minstd_rand gen(0);
    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 1000000; i++)
        cache.update(distrib(gen));
    
    using namespace testing;
    ASSERT_THAT(
        cache.get_state(), 
        ElementsAre(1, 1, 7, 9, 10, 2, 6, 4, 3, 8)
    );
}