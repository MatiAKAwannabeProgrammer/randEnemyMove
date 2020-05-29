#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
class Enemy
{
private:
    sf::CircleShape enemyModel;
    float randX;
    float randY;

public:
    Enemy();
    void updateEnemy(float& deltaTime);
    void drawEnemy(sf::RenderWindow& window);
    void getEnemyPosition();
    void setRandomDir(float& randomX, float& randomY);
    sf::Vector2f enemyPosition;

};
#endif
