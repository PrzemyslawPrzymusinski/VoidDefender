#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <player.h>
#include <opponent.h>
#include <bullet.h>

enum class GameState {
    PLAYING,
    UPGRADE_MENU,
};

class Game {
private:
    sf::RenderWindow& window;
    sf::Event event;
    sf::Clock clock;
    GameState state;
    int level;

    Player player;

    // tekstury
    sf::Texture opponentTexture;
    sf::Texture bulletTexture;
    sf::Texture tankTexture;
    sf::Texture heartTexture;

    sf::Sprite backgroundSprite;
    sf::Sprite heartSprite;

    sf::Font font;
    sf::Text scoreText;

    std::vector<std::unique_ptr<Opponent>> opponents;
    std::vector<std::unique_ptr<Bullet>> bullets;

    int score;
    int nextUpgrade;
    sf::Text upgradeMenuText;

    // spawn
    float spawnTimer;
    float spawnInterval;

    // metody pomocnicze
    void processEvents();
    void update();
    void render();

    void spawnOpponent();
    void spawnBasicOpp();
    void spawnTankOpp();
    void spawnBasicOpp(float x);

    void spawnBullet();
public:
    Game(sf::RenderWindow& window, const sf::Texture& backgroundTex, int _level);
    void run();
};
#endif // GAME_H
