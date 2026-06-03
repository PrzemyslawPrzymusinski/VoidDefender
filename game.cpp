#include "game.h"

Game::Game() : window(sf::VideoMode(600, 900), "Void Defender") {
    window.setFramerateLimit(60);

    opponents.emplace_back(Opponent());
    opponents.emplace_back(Opponent());
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

    for (auto o : opponents) {
        o.movement(deltaTime);
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    player.draw(window);

    for (auto o : opponents) {
        o.draw(window);
    }

    window.display();
}
