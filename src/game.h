#include <SFML/Graphics.hpp>

class Content;
class Game {
public:
    Game(const std::string& name, const Content& content);

    /**
     * @brief Continues running until window exits
     * Calls updates at 60fps
     */
    void gameLoop();
private:
    void update();

    const Content& content;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1280, 720), "Game");

    // Internal game
    sf::View view;
    sf::CircleShape shape = sf::CircleShape(100.f);
};