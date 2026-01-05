#include <cassert>
#include <iostream>
#include "LRUCache.h"

static void test_eviction() {
    LRUCache c(2);
    c.put(1, 10);
    c.put(2, 20);
    c.get(1);        // 1 becomes most recent
    c.put(3, 30);    // should evict 2

    assert(c.get(2) == -1);
    assert(c.get(1) == 10);
    assert(c.get(3) == 30);
}

static void test_update_moves_to_front() {
    LRUCache c(2);
    c.put(1, 10);
    c.put(2, 20);

    c.put(1, 99);    // update should mark 1 most recent
    c.put(3, 30);    // should evict 2

    assert(c.get(1) == 99);
    assert(c.get(2) == -1);
    assert(c.get(3) == 30);
}

static void test_get_makes_recent() {
    LRUCache c(2);
    c.put(1, 10);
    c.put(2, 20);

    c.get(2);        // now 2 is most recent
    c.put(3, 30);    // should evict 1

    assert(c.get(1) == -1);
    assert(c.get(2) == 20);
    assert(c.get(3) == 30);
}

int main() {
    test_eviction();
    test_update_moves_to_front();
    test_get_makes_recent();

    std::cout << "All tests passed.\n";
    return 0;
}
