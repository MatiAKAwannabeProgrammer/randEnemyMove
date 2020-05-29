#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "enemy.hpp"
#include <stdlib.h>

class Game
{
private:
    sf::RenderWindow window;
    sf::Event event;

    sf::Clock enemyClock;
    sf::Clock deltaClock;
    sf::Clock directionClock;
    sf::Time directionTime;
    sf::Time enemyTime;
    float deltaTime;
    
    float randomX;
    float randomY;

    std::vector<Enemy> enemyVector;
    Enemy * enemy;

public:
    Game();
    bool running();
    void pollEvents();
    void update();
    void render();
    void createEnemy();
    void updateEnemy();
    void renderEnemy();
    void randomDirections();

};
#endif
