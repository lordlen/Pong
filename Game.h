#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
namespace Pong{
	class Game
	{
	private:
		sf::RenderWindow& window;
		sf::Text scoreText1;
		sf::Text scoreText2;
		sf::Font font;
		bool isPaused = false;
		bool isHolding1 = false;
		bool isHolding2 = true;
		float paddleSpeed = .5f;
		float speedIncrement = .05f;
		float paddleChange = .1f;
		float paddleSize = 40;
		float initSpeed = 0.5f;
		Pong::Paddle paddle1;
		Pong::Paddle paddle2;
		Pong::Ball ball;

		unsigned int score1 = 0;
		unsigned int score2 = 0;

		void eventHandler();
		void update();
		void render();
	public:
		Game(sf::RenderWindow& wind);
		void run();
	};
}

