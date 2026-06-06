#include "game.h"
#include "BasicOpp.h"
#include <memory>
#include <algorithm>
#include <iostream>

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

    player.updateInvincibility();
    player.handleInput(deltaTime, window.getView().getSize());
    if (player.canShoot()) {
        spawnBullet();
    }

    for (auto& o : opponents) {
        o->movement(deltaTime);
    }

    for (auto& b : bullets) {
        b->movement(deltaTime);
    }

    // kolizje
    for (auto& b : bullets) {
        for (auto& o : opponents) {
            if (!b->isDestroyed() && !o->isDestroyed()) {
                if (b->getBounds().intersects(o->getBounds())) {
                    b->destroy();
                    o->destroy();
                }
            }
        }
    }

    for (auto& o : opponents) {
        if (!o->isDestroyed()) {
            if (player.getBounds().intersects(o->getBounds())) {
                player.destroy();
                o->destroy();
            }
        }
    }

    // usuwanie
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(), [](const std::unique_ptr<Bullet>& b) {
            return b->isOffScreen() || b->isDestroyed();
        }),
        bullets.end()
        );

    opponents.erase(
        std::remove_if(opponents.begin(), opponents.end(), [this](const std::unique_ptr<Opponent>& o) {
            bool isOffScreen = o->getBounds().top > window.getSize().y; // usuwa u spodu ekranu
            return o->isDestroyed() || isOffScreen;
        }),
        opponents.end()
        );

    if (player.isDestroyed()) {
        std::cout << "GAME OVER" << std::endl;
        // TODO
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