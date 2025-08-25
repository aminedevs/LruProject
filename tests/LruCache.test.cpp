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