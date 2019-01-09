#include "SpriteNode.h"


namespace csf {

	SpriteNode::SpriteNode(sf::Sprite& target):m_target(target) {
	}

	bool SpriteNode::onEvent(sf::Event event) {
		return false;
	}

	void SpriteNode::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_target, states);
	}

	SpriteNode::~SpriteNode()
	{
	}
}