#include "animation.h"
#include <SFML/Graphics.hpp>

void animation:: animate(const sf::Time& elapsed, std::vector<sf::IntRect>& rectangles){
    if (rectangles.empty())
        return;

    time += elapsed.asSeconds();
    if (time > 1./animation_fps) {
        time = 0;

        setTextureRect(rectangles[n]);
        if (++n >= rectangles.size())
            n = 0;
    }
}


void animation:: add_animation_frame(const sf::IntRect& rect, std::vector<sf::IntRect>& rectangles){
    rectangles.push_back(rect);
}