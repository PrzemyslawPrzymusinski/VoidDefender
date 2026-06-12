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

void wyniki(vector<int>& tabela, int score){
    //odczyt poprzednich wyników i sortowanie
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

    //zapis wyniku
    ofstream plikZ("wyniki.txt", ios::app);
    if(plikZ.is_open()){
        plikZ<<score<<'\n';
        plikZ.close();
    }
}

void end(sf::RenderWindow& window, int score){
    wEndu = true;
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("backgrounds/wygrana.png");
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(0.5,0.5);

    sf::Texture backgroundTexture2;
    backgroundTexture2.loadFromFile("backgrounds/przegrana.png");
    sf::Sprite backgroundSprite2(backgroundTexture2);
    backgroundSprite2.setScale(0.5,0.5);

    vector<int> tab_wyniki;

    wyniki(tab_wyniki, score);

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

    sf::Text Score;
    Score.setFont(czcionka);
    Score.setString(std::to_string(score));
    Score.setFillColor(sf::Color::White);
    Score.setCharacterSize(40);
    Score.setPosition(310, 410);
    
    przyciski* Przyciski[2];
    sf::Texture tekstury[2];
    tekstury[0].loadFromFile("buttons/przycisk4.png");
    tekstury[1].loadFromFile("buttons/przycisk5.png");
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

            if(!wEndu){
                break;
            }
        }

        if(!wEndu){
            break;
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

        window.draw(Score);

        window.display();
    }

    for(int i = 0; i < 2; ++i) {
        delete Przyciski[i];
    }
    if (window.isOpen()) {
        wPoziomie = false;
    }
}

void poziom1(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("backgrounds/poziom1.png")) {
        std::cout << "Blad ladowania tla poziomu 1!" << std::endl;
    }

    Game gra(window, poziomTexture, 1);
    while(window.isOpen() && wPoziomie){
        gra.run();
        end(window, gra.getScore());
    }
}

void poziom2(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("backgrounds/poziom2.png")) {
        std::cout << "Blad ladowania tla poziomu 2!" << std::endl;
    }

    Game gra(window, poziomTexture, 2);
    while(window.isOpen() && wPoziomie){
        gra.run();
        end(window, gra.getScore());
    }

}

void poziom3(sf::RenderWindow& window){
    wPoziomie = true;
    sf::Texture poziomTexture;
    if (!poziomTexture.loadFromFile("backgrounds/poziom3.png")) {
        std::cout << "Blad ladowania tla poziomu 3!" << std::endl;
    }

    Game gra(window, poziomTexture, 3);
    while(window.isOpen() && wPoziomie){
        gra.run();
        end(window, gra.getScore());
    }
}
