#include <string>
#include <optional>

#include <SFML/Graphics.hpp>

class Block {
public:
    Block(std::string id, std::optional<std::string> item, sf::Texture texture) :
        id(id), texture(texture), destructible(destructible), item(item) {};

    const std::string id;
    const sf::Texture texture;
    const bool destructible;
    const std::optional<std::string> item;
};