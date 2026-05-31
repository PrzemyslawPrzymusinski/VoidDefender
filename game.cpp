#include "game.h"

Game::Game() : window(sf::VideoMode(600, 900), "Void Defender") {
    window.setFramerateLimit(60);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();

    player.handleInput(deltaTime);
}

void Game::render() {
    window.clear(sf::Color::Black);

    player.draw(window);

    window.display();
}
