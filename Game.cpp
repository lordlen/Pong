#include "Game.h"
#include <string>

Pong::Game::Game(sf::RenderWindow& wind):
    window(wind),
    paddle1(0, 366, paddleSize),
    paddle2(1019, 366, paddleSize),
    ball(10, 366, 5)
{
    paddle1.setUpperBorder(0);
    paddle1.setLowerBorder(window.getSize().y);
    paddle2.setUpperBorder(0);
    paddle2.setLowerBorder(window.getSize().y);
    ball.setUpperBorder(0);
    ball.setLowerBorder(window.getSize().y);
    ball.setLeftBorder(0);
    ball.setRightBorder(window.getSize().x);

    ball.setVelocity(initSpeed, 0);
    
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }

    scoreText1.setFont(font);
    scoreText2.setFont(font);

    scoreText1.setCharacterSize(24);
    scoreText2.setCharacterSize(24);
    
    scoreText1.setPosition(0, 0);
    scoreText2.setPosition(900, 0);
}

void Pong::Game::eventHandler()
{
    sf::Event event;


    while (window.pollEvent(event))
    {
        switch (event.type) {
        case(sf::Event::Closed):
            window.close();
            break;
        case(sf::Event::GainedFocus):
            isPaused = false;
            break;
        case(sf::Event::LostFocus):
            isPaused = true;
            break;
        default:
            break;
        }
    }
}

void Pong::Game::update()
{
    bool isColliding = false;
    // update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !paddle1.collideUpper()) {
        paddle1.move(0, -paddleSpeed);
        if (ball.isColliding(paddle1)) {
            isColliding = true;
            ball.nudgeVY(-paddleChange);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !paddle1.collideLower()) {
        paddle1.move(0, paddleSpeed);
        if (ball.isColliding(paddle1)) {
            isColliding = true;
            ball.nudgeVY(paddleChange);
        }
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !paddle2.collideUpper()) {
        paddle2.move(0, -paddleSpeed);
        if (ball.isColliding(paddle2)) {
            isColliding = true;
            ball.nudgeVY(-paddleChange);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !paddle2.collideLower()) {
        paddle2.move(0, paddleSpeed);
        if (ball.isColliding(paddle2)) {
            isColliding = true;
            ball.nudgeVY(paddleChange);
        }
    }

    if (ball.isColliding(paddle1) || ball.isColliding(paddle2)) {
        isColliding = true;
    }

    if (isColliding) {
        ball.invertVX();
        ball.nudgeVX(speedIncrement);
    }


    ball.update();

    if (isHolding1) {
        // ball should follow paddle1
        ball.setPosition(paddle1.getPosition() + sf::Vector2f(8, 10));
        ball.setVelocity(-initSpeed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            isHolding1 = false;
        }
    } else if (isHolding2) {
        // ball should follow paddle1
        ball.setPosition(paddle2.getPosition() + sf::Vector2f(-8, 10));
        ball.setVelocity(initSpeed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            isHolding2 = false;
        }
    }

    // check if someone wins
    if (ball.collideRight()) {
        score1++;
        isHolding2 = true;
    }
    else if (ball.collideLeft()) {
        score2++;
        isHolding1 = true;
    }

    scoreText1.setString(std::to_string(score1));
    scoreText2.setString(std::to_string(score2));
}

void Pong::Game::render()
{
    window.clear();

    window.draw(paddle1);
    window.draw(paddle2);
    window.draw(ball);
    
    window.draw(scoreText1);
    window.draw(scoreText2);

    window.display();
}

void Pong::Game::run()
{
    while (window.isOpen()) {
        eventHandler();
        if (!isPaused) {
            update();
            render();
        }
    }
}
