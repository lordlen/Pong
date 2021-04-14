#include "Paddle.h"
#include <vector>

namespace Pong {
	Paddle::Paddle(sf::RectangleShape rect)
	{
		rectangle = rect;
	}

	Paddle::Paddle(float x, float y, float size)
	{
		rectangle = sf::RectangleShape(sf::Vector2f(5, size));
		rectangle.setPosition(x, y);
	}

	void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(this->rectangle, states);
	}

	std::vector<sf::RectangleShape> Paddle::getHitboxes() const
	{
		return std::vector<sf::RectangleShape>{rectangle};
	}


	bool Paddle::isColliding(Pong::Collidable& coll) const
	{
		float top1, top2;
		float bot1, bot2;
		float left1, left2;
		float right1, right2;
		// check if boxes are colliding
		std::vector<sf::RectangleShape> boxes1 = this->getHitboxes();
		std::vector<sf::RectangleShape> boxes2 = coll.getHitboxes();


		for(sf::RectangleShape rect1: boxes1)
			for (sf::RectangleShape rect2 : boxes2) {
				top1 = rect1.getPosition().y;
				left1 = rect1.getPosition().x;
				top2 = rect2.getPosition().y;
				left2 = rect2.getPosition().x;

				right1 = left1 + rect1.getSize().x;
				bot1 = top1 + rect1.getSize().y;
				right2 = left2 + rect2.getSize().x;
				bot2 = top2 + rect2.getSize().y;

				if (bot1 > top2&&
					bot2 > top1&&
					right1 > left2&&
					right2 > left1) {
					return true;
				}
			}
		return false;
	}

	void Paddle::move(float offsetX, float offsetY)
	{
		this->rectangle.move(offsetX, offsetY);
	}

	void Paddle::move(sf::Vector2f v)
	{
		this->rectangle.move(v);
	}
	sf::Vector2f Paddle::getPosition()
	{
		return rectangle.getPosition();
	}
}