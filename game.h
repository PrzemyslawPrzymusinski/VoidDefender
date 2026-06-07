#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <player.h>
#include <opponent.h>
#include <bullet.h>

class Game {
private:
    sf::RenderWindow& window;
    sf::Event event;
    sf::Clock clock;

    Player player;

    sf::Texture opponentTexture;
    sf::Texture bulletTexture;

    sf::Sprite backgroundSprite;

    std::vector<std::unique_ptr<Opponent>> opponents;
    std::vector<std::unique_ptr<Bullet>> bullets;

    // metody pomocnicze
    void processEvents();
    void update();
    void render();
    void spawnOpponent();
    void spawnBullet();
public:
    Game(sf::RenderWindow& window, const sf::Texture& backgroundTex);
    void run();
};
#endif // GAME_H
