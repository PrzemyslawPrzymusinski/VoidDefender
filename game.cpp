#include "game.h"
#include "BasicOpp.h"
#include <memory>

Game::Game() : window(sf::VideoMode(600, 900), "Void Defender") {
    window.setFramerateLimit(60);
    srand(time(0));

    if (!opponentTexture.loadFromFile("player.png")) {
        // TODO
    }

    if (!bulletTexture.loadFromFile("player.png")) { // zmienic
        // TODO
    }

    spawnOpponent();
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

    if (player.canShoot()) {
        spawnBullet();
    }

    for (auto& o : opponents) {
        o->movement(deltaTime);
    }

    for (auto& b : bullets) {
        b->movement(deltaTime);
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    for (auto& o : opponents) {
        o->draw(window);
    }

    for (auto& b : bullets) {
        b->draw(window);
    }

    player.draw(window);

    window.display();
}

void Game::spawnOpponent() {
    opponents.push_back(std::make_unique<BasicOpp>(opponentTexture));
}

void Game::spawnBullet() {
    bullets.push_back(std::make_unique<Bullet>(bulletTexture, player.getPosition()));
}