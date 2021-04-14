#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"
namespace Pong {
	class Ball: public sf::Drawable, public Pong::Collidable
	{
	private:
		sf::RectangleShape rectangle;
		float vx;
		float vy;
	public:
		Ball(sf::RectangleShape rect);
		Ball(float x, float y, float size);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual std::vector<sf::RectangleShape> getHitboxes() const;
		void setVelocity(float vx, float vy);
		void setVX(float vx);
		void setVY(float vy);
		void nudgeVX(float x);
		void nudgeVY(float y);
		void invertVX();
		void invertVY();
		void setPosition(sf::Vector2f pos);
		void update();
	};
}

