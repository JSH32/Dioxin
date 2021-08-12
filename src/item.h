#include <string>
#include <optional>

#include <SFML/Graphics.hpp>

class Item {
public:
    Item(std::string id, std::string name, std::string description, bool placeable, std::optional<std::string> block, sf::Texture texture) :
        id(id), name(name), description(description), texture(texture), placeable(placeable), block(block) {};

    const std::string id;
    const std::string name;
    const std::string description;
    const sf::Texture texture;
    const bool placeable;
    const std::optional<std::string> block;
};