#ifndef BASICOPP_H
#define BASICOPP_H

#include "opponent.h"

class BasicOpp : public Opponent
{
public:
    BasicOpp(const sf::Texture& texture);
    BasicOpp(const sf::Texture& texture, float _x);

    void movement(float deltaTime) override;
};

#endif // BASICOPP_H
