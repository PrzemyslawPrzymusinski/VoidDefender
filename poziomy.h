#ifndef POZIOMY_H
#define POZIOMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

extern bool wPoziomie;
extern bool gameWon;
extern bool wEndu;

void wyniki(vector<int>& tabela, int& score, int nr_poziomu, bool& best_new);

void end(sf::RenderWindow& window, int score, int nr_poziomu);

void poziom1(sf::RenderWindow& window);

void poziom2(sf::RenderWindow& window);

void poziom3(sf::RenderWindow& window);



#endif // POZIOMY_H
