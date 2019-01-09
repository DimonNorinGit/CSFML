#pragma once



#ifndef SCF_SPRITE_NODE_HPP
#define SCF_SPRITE_NODE_HPP

#include"SFML/Graphics/Sprite.hpp"
#include"Node.h"


namespace csf {

	class SpriteNode : public Node
	{

	public:

		SpriteNode(sf::Sprite& target);

		~SpriteNode();

	protected:

		virtual bool onEvent(sf::Event event);
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite& m_target;
	};


}
#endif // !SCF_SPRITE_NODE_HPP
