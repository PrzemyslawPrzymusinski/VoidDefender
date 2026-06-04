#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <player.h>
#include <opponent.h>
#include <memory>

class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;

    Player player;
    sf::Texture opponentTexture;
    std::vector<std::unique_ptr<Opponent>> opponents;

    // metody pomocnicze
    void processEvents();
    void update();
    void render();
    void spawnOpponent();
public:
    Game();
    void run();
};
#endif // GAME_H
