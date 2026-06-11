#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class animation : public sf::Sprite{
public:
    void animate(const sf::Time& elapsed, std::vector<sf::IntRect>& rectangles);
    void add_animation_frame(const sf::IntRect& rect, std::vector<sf::IntRect>& rectangles);
private:
    int animation_fps =10;
    float time=0;
    int n=0;
};

#endif // ANIMATION_H