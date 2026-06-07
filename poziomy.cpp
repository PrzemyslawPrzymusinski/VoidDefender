#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "przyciski.h"
#include "poziomy.h"
#include "game.h"
#include <algorithm>


using namespace std;

bool wPoziomie = true;
bool gameWon = false;
bool wEndu = true;

void wyniki(vector<int>& tabela){
    ifstream plikO("wyniki.txt");
    if(plikO.is_open()){
        int linia;
        while(plikO >> linia){
            tabela.push_back(linia);
        }
        plikO.close();
    }

    if(!tabela.empty()){
        for(int k = 0; k<(int)tabela.size();k++){
            for(int h = 1; h<(int)tabela.size();h++){
                if(tabela[h-1]<tabela[h]){
                    swap(tabela[h-1], tabela[h]);
                }
            }
        }
    }


}

void end(sf::RenderWindow& window){
    wEndu = true;
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("wygrana.png");
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(0.5,0.5);

    sf::Texture backgroundTexture2;
    backgroundTexture2.loadFromFile("przegrana.png");
    sf::Sprite backgroundSprite2(backgroundTexture2);
    backgroundSprite2.setScale(0.5,0.5);

    vector<int> tab_wyniki;

    wyniki(tab_wyniki);

    vector<sf::Text> tekstyLiczb;
    float pozycjaY = 570;

    sf::Font czcionka;
    czcionka.loadFromFile("stan0753.ttf");
    int ileWyników = min(5, (int)tab_wyniki.size());
    for(int k =0; k<ileWyników; k++){
        sf::Text text;
        text.setFont(czcionka);
        text.setString(std::to_string(tab_wyniki[k]));
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(15);
        text.setPosition(300, pozycjaY);

        tekstyLiczb.push_back(text);
        pozycjaY += 30;
    }
    przyciski* Przyciski[2];
    sf::Texture tekstury[2];
    tekstury[0].loadFromFile("przycisk4.png");
    tekstury[1].loadFromFile("przycisk5.png");
    create_bottoms(Przyciski, tekstury, 2);

    while(window.isOpen() && wEndu){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){
                for(auto& p : Przyciski){
                    p->handleEvent(event,window);
                }
            }

        }

        window.clear();
        if(gameWon){
            window.draw(backgroundSprite);
        }else{
            window.draw(backgroundSprite2);
        }

        for(const auto& text : tekstyLiczb){
            window.draw(text);
        }

        for(const auto& p : Przyciski){
            window.draw(*p);
        }

        window.display();
    }

    for(int i = 0; i < 2; ++i) {
        delete Przyciski[i];
    }
}

void poziom1(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("poziom1.png")) {
        std::cout << "Blad ladowania tla poziomu 1!" << std::endl;
    }

    Game gra(window, poziomTexture);
    gra.run();
    end(window);
}

void poziom2(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("poziom2.png")) {
        std::cout << "Blad ladowania tla poziomu 2!" << std::endl;
    }

    Game gra(window, poziomTexture);
    gra.run();
    end(window);

}

void poziom3(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("poziom3.png")) {
        std::cout << "Blad ladowania tla poziomu 3!" << std::endl;
    }

    Game gra(window, poziomTexture);
    gra.run();
    end(window);

}