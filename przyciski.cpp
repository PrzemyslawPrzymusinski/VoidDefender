#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "poziomy.h"
#include "przyciski.h"

void przycisk1:: handleEvent(const sf::Event& event, sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)){
                poziom1(window);
            }
        }
    }
}

void przycisk2:: handleEvent(const sf::Event& event, sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)){
                poziom2(window);
            }
        }
    }
}

void przycisk3:: handleEvent(const sf::Event& event, sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)){
                poziom3(window);
            }
        }
    }
}

void wyjscie:: handleEvent(const sf::Event& event, sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)){
                window.close();
            }
        }
    }
}

void kolejna_gra:: handleEvent(const sf::Event& event, sf::RenderWindow& window){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)){
                wEndu = false;
                wPoziomie = false;
            }
        }
    }
}

void create_bottoms (przyciski* Przyciski[],const sf::Texture tekstury[], int n){
    switch (n) {
    case 1:
        Przyciski[0] = new przycisk1(tekstury[0]);
        Przyciski[1] = new przycisk2(tekstury[1]);
        Przyciski[2] = new przycisk3(tekstury[2]);
        Przyciski[3] = new wyjscie(tekstury[3]);

        Przyciski[0]->setPosition(215, 400);
        Przyciski[0]->setScale(0.5, 0.5);
        Przyciski[1]->setPosition(215, 520);
        Przyciski[1]->setScale(0.5, 0.5);
        Przyciski[2]->setPosition(215, 640);
        Przyciski[2]->setScale(0.5, 0.5);
        Przyciski[3]->setPosition(215, 770);
        Przyciski[3]->setScale(0.5, 0.5);
        break;
    case 2:
        Przyciski[0] = new wyjscie(tekstury[0]);
        Przyciski[0]->setScale(0.5, 0.5);
        Przyciski[0]->setPosition(45, 800);
        Przyciski[1] = new kolejna_gra(tekstury[1]);
        Przyciski[1]->setScale(0.5, 0.5);
        Przyciski[1]->setPosition(375, 800);
    default:
        break;
    }
}








