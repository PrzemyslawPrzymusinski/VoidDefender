#ifndef PRZYCISKI_H
#define PRZYCISKI_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class przyciski : public sf::Sprite{
public:
    przyciski(const sf::Texture& obraz){setTexture(obraz);}
    ~przyciski() = default;
    virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) = 0;
};

class przycisk1 : public przyciski{
public:
    przycisk1(const sf::Texture& obraz):przyciski(obraz){}
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

class przycisk2 : public przyciski{
public:
    przycisk2(const sf::Texture& obraz) :  przyciski(obraz){}
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

class przycisk3 : public przyciski{
public:
    przycisk3(const sf::Texture& obraz) : przyciski(obraz){}
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

class wyjscie : public przyciski{
public:
    wyjscie(const sf::Texture& obraz) : przyciski(obraz){}
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

class kolejna_gra : public przyciski{
public:
    kolejna_gra(const sf::Texture& obraz) : przyciski(obraz){}
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

void create_bottoms (przyciski* Przyciski[], const  sf::Texture tekstury[], int n);


#endif // PRZYCISKI_H
