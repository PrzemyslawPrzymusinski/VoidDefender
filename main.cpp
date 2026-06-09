#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "przyciski.h"

int main() {
    przyciski* Przyciski[4];
    sf::Texture tekstury[4];
    tekstury[0].loadFromFile("buttons/przycisk1.png");
    tekstury[1].loadFromFile("buttons/przycisk2.png");
    tekstury[2].loadFromFile("buttons/przycisk3.png");
    tekstury[3].loadFromFile("buttons/przycisk4.png");
    create_bottoms(Przyciski, tekstury, 1);

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("backgrounds/start2.png");
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(0.5,0.5);

    sf::RenderWindow window(sf::VideoMode(660, 1056), "Void defender");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                for(auto &p: Przyciski){
                    p->handleEvent(event, window);
                }
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        for(const auto &p: Przyciski){
            window.draw(*p);
        }
        window.display();
    }

    for(int i = 0; i < 4; ++i) {
        delete Przyciski[i];
    }

    return 0;
}
