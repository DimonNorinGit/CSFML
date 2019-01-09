#include "Screen.h"

namespace csf {

	Screen::Screen()
	{

	}

	bool Screen::onEvent(sf::Event event) {
		return false;
	}

	void Screen::onDraw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(sf::Sprite(getTexture()), states);
	}

	void Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		Node::draw(target, states);
	}

	Screen::~Screen()
	{

	}
}