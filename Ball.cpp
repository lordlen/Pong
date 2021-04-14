#include "Ball.h"

Pong::Ball::Ball(sf::RectangleShape rect)
{
	this->rectangle = rect;
}

Pong::Ball::Ball(float x, float y, float size)
{
	rectangle = sf::RectangleShape(sf::Vector2f(size, size));
	rectangle.setPosition(x, y);
}

void Pong::Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rectangle, states);
}

std::vector<sf::RectangleShape> Pong::Ball::getHitboxes() const
{
	return std::vector<sf::RectangleShape>{this->rectangle};
}

void Pong::Ball::setVelocity(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Pong::Ball::setVX(float vx)
{
	this->vx = vx;
}

void Pong::Ball::setVY(float vy)
{
	this->vy = vy;
}

void Pong::Ball::nudgeVX(float x)
{
	if (vx > 0)
		this->vx += x;
	else
		this->vx -= x;
}

void Pong::Ball::nudgeVY(float y)
{
	this->vy += y;
}

void Pong::Ball::invertVX()
{
	this->vx = -vx;
}

void Pong::Ball::invertVY()
{
	this->vy = -vy;
}

void Pong::Ball::setPosition(sf::Vector2f pos)
{
	this->rectangle.setPosition(pos);
}


void Pong::Ball::update()
{
	// bounce off upper and lower bounds
	if (this->collideUpper()) {
		vy = -vy;
	}

	if (this->collideLower()) {
		vy = -vy;
	}

	this->rectangle.move(vx, vy);
}
