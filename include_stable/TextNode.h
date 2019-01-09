#pragma once


#ifndef CSF_TEXT_NODE_HPP
#define CSF_TEXT_NODE_HPP

#include"SFML/Graphics/Text.hpp"
#include"Node.h"

namespace csf {
	class TextNode : public Node
	{

	public:

		TextNode(sf::Text& target);

		virtual ~TextNode();


	protected:
		virtual bool onEvent(sf::Event event);
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Text& m_target;
	};

}
#endif // !CSFM_TEXT_NODE_HPP