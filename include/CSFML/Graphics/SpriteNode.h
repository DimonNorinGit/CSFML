#pragma once



#ifndef SCF_SPRITE_NODE_HPP
#define SCF_SPRITE_NODE_HPP

#include"SFML/Graphics/Sprite.hpp"

#include"CSFML/Graphics/Node.h"


namespace csf {

	class SpriteNode : public Node
	{

	public:

		SpriteNode();

		SpriteNode(const sf::Sprite& sprite);

		void setSprite(const sf::Sprite& sprite);

		const sf::Sprite& getSprite()const;

		~SpriteNode();

	protected:

		virtual bool onEvent(sf::Event event);
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite m_sprite;
	};


}
#endif // !SCF_SPRITE_NODE_HPP
