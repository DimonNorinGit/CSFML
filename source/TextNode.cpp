#include "TextNode.h"


namespace csf {
	TextNode::TextNode()
	{
	}

	TextNode::TextNode(const sf::Text& text) {
		m_text = text;
	}

	bool TextNode::onEvent(sf::Event event) {
		return false;
	}

	void TextNode::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_text, states);
	}

	void TextNode::setText(const sf::Text& text) {
		m_text = text;
	}

	const sf::Text& TextNode::getText()const {
		return m_text;
	}

	TextNode::~TextNode()
	{
	}
}