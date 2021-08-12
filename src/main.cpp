#include <iostream>

#include <SFML/Graphics.hpp>
#include "content.h"

#include "game.h"

int main() {
    Content content;

    for (auto it = content.itemMap.begin(); it != content.itemMap.end(); it++) {
        std::cout << (*it).first << std::endl;
    }

    Game game("Animism", content);
    game.gameLoop();

    return 0;
}