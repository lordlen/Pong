#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace Pong {
	class Collidable {
	private:
		unsigned int upperBorder;
		unsigned int lowerBorder;
		unsigned int leftBorder;
		unsigned int rightBorder;
	public:
		virtual ~Collidable();
		bool isColliding(Pong::Collidable& coll);
		virtual std::vector<sf::RectangleShape> getHitboxes() const = 0;
		void setUpperBorder(unsigned int border);
		void setLowerBorder(unsigned int border);
		void setLeftBorder(unsigned intborder);
		void setRightBorder(unsigned int border);
		bool collideUpper();
		bool collideLower();
		bool collideLeft();
		bool collideRight();
	};
}