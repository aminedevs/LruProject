#include <LruCache.hpp>
#include <catch.hpp>

TEST_CASE("ZeroCapacityTest", "LruCacheTest")
{
    Lru lruCache(0);
    lruCache.put(1, 100);
    auto result = lruCache.get(1);
    REQUIRE(result == -1);
}

TEST_CASE("PutOneElementTest", "LruCacheTest")
{
    Lru lruCache(2);
    lruCache.put(1, 100);
    auto result = lruCache.get(1);
    REQUIRE(result == 100);
}

TEST_CASE("EvictionTest", "LruCacheTest")
{
    Lru lruCache(2);
    lruCache.put(1, 100);
    lruCache.put(2, 200);
    lruCache.put(3, 300);

    auto result = lruCache.get(1);
    REQUIRE(result == -1);
}

TEST_CASE("RemplaceExistingKey", "LruCacheTest")
{
    Lru lruCache(2);
    lruCache.put(1, 100);
    lruCache.put(2, 200);
    lruCache.put(2, 300);

    auto result = lruCache.get(2);
    REQUIRE(result == 300);
}

TEST_CASE("GetWithoutPut", "LruCacheTest")
{
    Lru lruCache(2);
    auto result = lruCache.get(1);
    REQUIRE(result == -1);
}

TEST_CASE("PutNegativeKey", "LruCacheTest")
{
    Lru lruCache(2);
    lruCache.put(-1, -299);
    auto result = lruCache.get(-1);
    REQUIRE(result == -299);
}

TEST_CASE("MissingKey", "LruCacheTest")
{
    Lru lruCache(2);
    lruCache.put(-1, -299);
    auto result = lruCache.get(1);
    REQUIRE(result == -1);
}

TEST_CASE("RotateTheKey", "LruCacheTest")
{
    Lru lruCache(5);
    lruCache.put(1, 100);
    lruCache.put(2, -200);
    lruCache.put(3, -300);
    lruCache.put(4, -400);
    lruCache.put(1, 200);
    lruCache.put(5, 200);
    lruCache.put(6, 200);

    auto result = lruCache.get(2);
    REQUIRE(result == -1);
}

TEST_CASE("MassiveInsertion", "LruCacheTest")
{
    auto n = 10000;
    auto capacity = n;
    Lru lruCache(capacity);

    for (int index = 1; index < n + 1; index++)
    {
        lruCache.put(index, index);
    }

    auto result = lruCache.get(n);

    REQUIRE(result == n);
}

TEST_CASE("MassiveInsertionWithEviction", "LruCacheTest")
{
    auto n = 10000;         // 100        100-10= 90
    auto capacity = n / 10; // 10
    Lru lruCache(capacity);

    for (int index = 1; index < n + 1; index++)
    {
        lruCache.put(index, index);
    }
    auto idx = 1;
    for (idx = 1; idx < n - capacity + 1; idx++)
    {
        auto result = lruCache.get(idx);
        REQUIRE(result == -1);
    }

    auto result = lruCache.get(idx);
    REQUIRE(result == idx);
}