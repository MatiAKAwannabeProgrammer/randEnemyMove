#include "game.hpp"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

Game::Game()
{
    window.create(sf::VideoMode(800.f, 600.f), "Test");
    window.setFramerateLimit(60);
}

bool Game::running()
{
    return window.isOpen();
}

void Game::pollEvents()
{
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
    // Setting the clocks.
    deltaTime = deltaClock.restart().asSeconds();
    enemyTime = enemyClock.getElapsedTime();
    directionTime = directionClock.getElapsedTime();

    if (enemyTime.asSeconds() >= 2){
        enemyClock.restart();
        createEnemy();
    }
    if (directionTime.asSeconds() >= 1){
        directionClock.restart();
        randomDirections();
    }
    updateEnemy();
}

void Game::render()
{
    window.clear();

    renderEnemy();

    window.display();
}

void Game::createEnemy()
{
    enemy = new Enemy();
    enemyVector.push_back(*enemy);
}

void Game::updateEnemy()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        enemyVector[i].updateEnemy(deltaTime);
        enemyVector[i].getEnemyPosition();
    }
}

void Game::renderEnemy()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        enemyVector[i].drawEnemy(window);
    }
}

void Game::randomDirections()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        randomX = (rand() % 400) - 400;     
        randomY = (rand() % 400) - 400;
        enemyVector[i].setRandomDir(randomX, randomY);
    }
}
