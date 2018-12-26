#include "SpriteNode.h"


namespace csf {
	SpriteNode::SpriteNode()
	{
	}

	SpriteNode::SpriteNode(const sf::Sprite& sprite) {
		m_sprite = sprite;
	}

	bool SpriteNode::onEvent(sf::Event event) {
		return false;
	}

	void SpriteNode::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_sprite, states);
	}

	void SpriteNode::setSprite(const sf::Sprite& sprite) {
		m_sprite = sprite;
	}

	const sf::Sprite& SpriteNode::getSprite()const {
		return m_sprite;
	}

	SpriteNode::~SpriteNode()
	{
	}
}