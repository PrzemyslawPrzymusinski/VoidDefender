#include "game.h"
#include "basicopp.h"
#include "tankopp.h"
#include "poziomy.h"
#include <memory>
#include <algorithm>
#include <iostream>

Game::Game(sf::RenderWindow& windowRef, const sf::Texture& backgroundTex) : window(windowRef){
    srand(time(0));
    backgroundSprite.setTexture(backgroundTex);
    backgroundSprite.setScale(0.5, 0.5);

    score = 0;

    if (!opponentTexture.loadFromFile("basicopp.png")) {
        cout << "Blad basicopp.png" << endl;
    }

    if (!bulletTexture.loadFromFile("bullet.png")) {
       cout << "Blad bullet.png" << endl;
    }
    if (!tankTexture.loadFromFile("tank.png")) {
       cout << "Blad tank.png" << endl;
    }

    if (!font.loadFromFile("stan0753.ttf")) {
        cout << "Blad czcionki" << endl;
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("0");

    spawnBasicOpp(100.f);
    spawnTankOpp();

    spawnTimer = 0.f;
    spawnInterval = 1.5f;
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

    // spawnowanie
    spawnTimer += deltaTime;
    std::cout << "Timer: " << spawnTimer << " | Interval: " << spawnInterval << '\n';
    if (spawnTimer >= spawnInterval) {
        spawnBasicOpp();
        spawnTimer = 0.f;
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
                    if (o->isDestroyed()) {
                        score += o->getPoints();
                    }
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
            bool isOffScreen = (o->getBounds().top + o->getBounds().height) > window.getSize().y - 110.0; // usuwa u spodu ekranu
            return o->isDestroyed() || isOffScreen;
        }),
        opponents.end()
        );

    if (player.isDestroyed()) {
        std::cout << "GAME OVER" << std::endl;
        gameWon = false;
        end(window);
    }

    // obsluga wyswietlacza wyniku
    scoreText.setString(std::to_string(score));
    sf::FloatRect textBounds = scoreText.getLocalBounds();
    float xPos = 15.f;
    float yPos = window.getView().getSize().y - textBounds.height - 15.f;
    scoreText.setPosition(xPos, yPos);
}

void Game::render() {
    window.clear(sf::Color::Black);

    window.draw(backgroundSprite);

    for (auto& o : opponents) {
        o->draw(window);
    }

    for (auto& b : bullets) {
        b->draw(window);
    }

    player.draw(window);

    window.draw(scoreText);

    window.display();
}

void Game::spawnBasicOpp() {
    float windowWidth = window.getSize().x;
    float randomX = std::rand() % (int)(windowWidth - 100);

    opponents.push_back(std::make_unique<BasicOpp>(opponentTexture, randomX));
}

void Game::spawnTankOpp() {
    float windowWidth = window.getSize().x;
    float randomX = std::rand() % (int)(windowWidth - 100);

    opponents.push_back(std::make_unique<TankOpp>(tankTexture, randomX));
}


void Game::spawnBasicOpp(float x) {
    opponents.push_back(std::make_unique<BasicOpp>(opponentTexture, x));
}

void Game::spawnBullet() {
    bullets.push_back(std::make_unique<Bullet>(bulletTexture, player.getPosition()));
}
