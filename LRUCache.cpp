#include "LRUCache.h"
#include <stdexcept>

LRUCache::LRUCache(size_t capacity) : cap_(capacity) {
    if (cap_ == 0) {
        throw std::invalid_argument("Capacity must be greater than 0");
    }
}

int LRUCache::get(int key) {
    auto it = map_.find(key);
    if (it == map_.end()) {
        return -1;
    }

    touch(it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = map_.find(key);

    if (it != map_.end()) {
        it->second->second = value;
        touch(it->second);
        return;
    }

    dll_.push_front({key, value});
    map_[key] = dll_.begin();

    evictIfNeeded();
}

void LRUCache::touch(std::list<std::pair<int,int>>::iterator it) {
    dll_.splice(dll_.begin(), dll_, it);
}

void LRUCache::evictIfNeeded() {
    if (dll_.size() <= cap_) return;

    auto lru = dll_.back();
    map_.erase(lru.first);
    dll_.pop_back();
}
