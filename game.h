#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <player.h>
#include <opponent.h>

class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;

    Player player;
    std::vector<Opponent> opponents;

    // metody pomocnicze
    void processEvents();
    void update();
    void render();
public:
    Game();
    void run();
};
#endif // GAME_H
