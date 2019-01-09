#include "TextNode.h"


namespace csf {

	TextNode::TextNode(sf::Text& target) :m_target(target) {
	
	}

	bool TextNode::onEvent(sf::Event event) {
		return false;
	}

	void TextNode::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_target, states);
	}


	TextNode::~TextNode()
	{
	}
}