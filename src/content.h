#include <vector>

#include <SFML/Graphics.hpp>

#include "item.h"
#include "block.h"

class Content {
public:
    Content();

    std::map<std::string, sf::Texture> textureMap;
    std::map<std::string, Item> itemMap;
    std::map<std::string, Block> blockMap;
};