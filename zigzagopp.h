#ifndef ZIGZAGOPP_H
#define ZIGZAGOPP_H

#include "opponent.h"

class ZigZagOpp : public Opponent
{
protected:
    float speedHorizontal;
    float windowWidth;
public:
    ZigZagOpp(const sf::Texture& texture, float _x, float _windowWidth);

    void movement(float deltaTime) override;
};

#endif // ZIGZAGOPP_H
