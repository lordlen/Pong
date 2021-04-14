#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"
#include <vector>

namespace Pong {
	class Paddle : public sf::Drawable, sf::Transformable, public Pong::Collidable{
	private:
		sf::RectangleShape rectangle;
	public:
		Paddle(sf::RectangleShape rect);
		Paddle(float x, float y, float size);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual std::vector<sf::RectangleShape> getHitboxes() const;
		virtual bool isColliding(Pong::Collidable& coll) const;
		void move(float offsetX, float offsetY);
		void move(sf::Vector2f);
		sf::Vector2f getPosition();
	};
}