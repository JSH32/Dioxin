#include "game.h"

#include "iostream"

Game::Game(const std::string& name, const Content& content) : content(content) {
    this->window.setTitle(name);

    this->shape.setFillColor(sf::Color::Red);
    window.setView(view);
}

void Game::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::D) {
                view.move(-10, 0);
                window.setView(view);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        view.move(-1, 0);
        window.setView(view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        view.move(1, 0);
        window.setView(view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        view.move(0, 1);
        window.setView(view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view.move(0, -1);
        window.setView(view);
    }

    window.clear();
    window.draw(this->shape);
    window.display();
}

void Game::gameLoop() {
    while (window.isOpen()) 
        update();
}