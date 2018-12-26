#pragma once


#ifndef CSF_TEXT_NODE_HPP
#define CSF_TEXT_NODE_HPP

#include"SFML/Graphics/Text.hpp"

#include"CSFML/Graphics/Node.h"

namespace csf {
	class TextNode : public Node
	{

	public:

		TextNode();

		TextNode(const sf::Text& text);

		void setText(const sf::Text& text);

		const sf::Text& getText()const;

		~TextNode();


	protected:
		virtual bool onEvent(sf::Event event);
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Text m_text;
	};

}
#endif // !CSFM_TEXT_NODE_HPP