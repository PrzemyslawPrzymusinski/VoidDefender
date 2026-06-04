#include "opponent.h"
#include <cmath>
#include <cstdlib>

Opponent::Opponent(const sf::Texture& texture) {
    srand(time(0));
    speed = rand() % 200; // zrobic zeby  bylo zmienne

    sprite.setTexture(texture);

    // temp
    sprite.setScale(0.5, 0.5);
    // sprite.rotate(180);

    sprite.setPosition(300.0, 50.0);
}

void Opponent::movement(float deltaTime) {
    sprite.move(0.f, speed * deltaTime);
}


void Opponent::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
