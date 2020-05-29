#include "enemy.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

Enemy::Enemy()
{
    enemyModel.setPosition(sf::Vector2f(300.f, 300.f));
    enemyModel.setFillColor(sf::Color::Cyan); 
    enemyModel.setRadius(20.f);
}

void Enemy::updateEnemy(float& deltaTime)
{
    if (enemyPosition.x <= 0 ||
        enemyPosition.x >= 800 ||
        enemyPosition.y <= 0 ||
        enemyPosition.y >= 600){
            randX *= -1;
            randY *= -1;
    }
    enemyModel.move(randX * deltaTime, randY * deltaTime);
}

void Enemy::drawEnemy(sf::RenderWindow& window)
{
    window.draw(enemyModel);
}

void Enemy::getEnemyPosition()
{
    enemyPosition = enemyModel.getPosition();
}

void Enemy::setRandomDir(float& randomX, float& randomY)
{
    this->randX = randomX;
    this->randY = randomY;
}
