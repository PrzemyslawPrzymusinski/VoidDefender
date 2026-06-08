#include "tankopp.h"

TankOpp::TankOpp(const sf::Texture& texture, float _x) : BasicOpp(texture, _x)
{
    speed = 100.f;
    points = 5;
    lifes = 5;
}
