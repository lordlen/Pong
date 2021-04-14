#include "Collidable.h"

Pong::Collidable::~Collidable()
{

}

bool Pong::Collidable::isColliding(Pong::Collidable& coll)
{
	float top1, top2;
	float bot1, bot2;
	float left1, left2;
	float right1, right2;
	// check if boxes are colliding
	std::vector<sf::RectangleShape> boxes1 = this->getHitboxes();
	std::vector<sf::RectangleShape> boxes2 = coll.getHitboxes();


	for (sf::RectangleShape rect1 : boxes1)
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

void Pong::Collidable::setUpperBorder(unsigned int border)
{
	this->upperBorder = border;
}

void Pong::Collidable::setLowerBorder(unsigned int border)
{
	this->lowerBorder = border;
}

void Pong::Collidable::setLeftBorder(unsigned int border)
{
	this->leftBorder = border;
}

void Pong::Collidable::setRightBorder(unsigned int border)
{
	this->rightBorder = border;
}

bool Pong::Collidable::collideUpper()
{
	for (auto rect : this->getHitboxes()) {
		if (rect.getPosition().y <= upperBorder)
			return true;
	}
	return false;
}

bool Pong::Collidable::collideLower()
{
	for (auto rect : this->getHitboxes()) {
		if (rect.getPosition().y + rect.getSize().y >= lowerBorder)
			return true;
	}
	return false;
}

bool Pong::Collidable::collideLeft()
{
	for (auto rect : this->getHitboxes()) {
		if (rect.getPosition().x <= leftBorder)
			return true;
	}
	return false;
}

bool Pong::Collidable::collideRight()
{
	for (auto rect : this->getHitboxes()) {
		if (rect.getPosition().x + rect.getSize().x >= rightBorder)
			return true;
	}

	return false;
}
