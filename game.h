#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <player.h>

class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;

    Player player;

    // metody pomocnicze
    void processEvents();
    void update();
    void render();
public:
    Game();
    void run();
};
#endif // GAME_H
