#include <iostream>
#include <sstream>
#include <string>
#include "LRUCache.h"
#include <limits>

int main() {
    std::cout << "LRU Cache Interactive Demo\n";
    std::cout << "Enter capacity: ";

    int cap = 0;
    std::cin >> cap;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (cap <= 0) {
        std::cout << "Capacity must be > 0\n";
        return 1;
    }

    LRUCache cache(static_cast<size_t>(cap));

    std::cout << "\nCommands:\n";
    std::cout << "  put <key> <value>\n";
    std::cout << "  get <key>\n";
    std::cout << "  print\n";
    std::cout << "  help\n";
    std::cout << "  quit\n\n";

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "quit" || cmd == "exit") {
            break;
        } else if (cmd == "help") {
            std::cout << "Commands: put <k> <v>, get <k>, print, help, quit\n";
        } else if (cmd == "print") {
            cache.print();
        } else if (cmd == "put") {
            int k, v;
            if (!(iss >> k >> v)) {
                std::cout << "Usage: put <key> <value>\n";
                continue;
            }
            cache.put(k, v);
            std::cout << "OK\n";
        } else if (cmd == "get") {
            int k;
            if (!(iss >> k)) {
                std::cout << "Usage: get <key>\n";
                continue;
            }
            int val = cache.get(k);
            if (val == -1) std::cout << "Not found\n";
            else std::cout << val << "\n";
        } else if (cmd.empty()) {
            continue;
        } else {
            std::cout << "Unknown command. Type 'help'.\n";
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
