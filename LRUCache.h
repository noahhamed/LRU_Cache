#pragma once

#include <list>
#include <unordered_map>
#include <utility>

// LRUCache provides O(1) get and put operations using a hash map
// and a doubly linked list to track usage order.
class LRUCache {
public:
    explicit LRUCache(size_t capacity);

    int get(int key);          // returns value or -1 if not found
    void put(int key, int value);
    void print() const;


private:
    size_t cap_;

    // Front = most recent, back = least recent
    std::list<std::pair<int, int>> dll_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;

    void touch(std::list<std::pair<int,int>>::iterator it);
    void evictIfNeeded();
};


#ifndef LRU_CACHE_LRUCACHE_H
#define LRU_CACHE_LRUCACHE_H

#endif //LRU_CACHE_LRUCACHE_H