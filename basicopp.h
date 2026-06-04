#ifndef BASICOPP_H
#define BASICOPP_H

#include "opponent.h"

class BasicOpp : public Opponent
{
public:
    BasicOpp(const sf::Texture& texture);

    void movement(float deltaTime) override;
};

#endif // BASICOPP_H
