#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << cache.get(1) << "\n"; // expect 10 (1 becomes most recent)

    cache.put(3, 30);                  // cache full, should evict key 2

    std::cout << cache.get(2) << "\n"; // expect -1 (evicted)
    std::cout << cache.get(3) << "\n"; // expect 30

    cache.put(1, 99);                  // update existing key 1
    std::cout << cache.get(1) << "\n"; // expect 99

    return 0;
}
