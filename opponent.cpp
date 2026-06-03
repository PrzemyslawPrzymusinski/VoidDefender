#include "opponent.h"
#include <cmath>

Opponent::Opponent() {
    srand(time(0));
    speed = rand() % 200; // zrobic zeby  bylo zmienne

    if (!texture.loadFromFile("player.png")) {
        //
    }
    sprite.setTexture(texture);

    // temp
    sprite.setScale(0.5, 0.5);
    //sprite.rotate(180);

    sprite.setPosition(300.0, 50.0);
}

void Opponent::movement(float deltaTime) {
    sf::Vector2f velocity(0.0, -200.0);
    sprite.move(velocity * speed * deltaTime);
}


void Opponent::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
