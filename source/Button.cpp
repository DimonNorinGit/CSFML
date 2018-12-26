#include "Button.h"



namespace csf {
	Button::Button()
	{
		m_textAutoScale = true;
	}
	Button::Button(const sf::Text& text) {
		m_text = text;
		sf::FloatRect rect = m_text.getGlobalBounds();
		m_ellips.setSize(rect.width * 2, rect.height * 2);
	}

	Button::Button(const sf::Texture& texture) {
		m_ellips.setSize(texture.getSize());
		m_ellips.setTexture(&texture);
	}

	Button::Button(const sf::Text& text, const sf::Texture& texture) {
		m_text = text;
		m_ellips.setSize(texture.getSize());
		m_ellips.setTexture(&texture);
	}

	Button::Button(const sf::Texture& texture, const sf::IntRect& rectangle) {
		m_ellips.setSize(texture.getSize());
		m_ellips.setTexture(&texture);
		m_ellips.setTextureRect(rectangle);
	}

	void Button::setBorderRadius(size_t radius, BorderRadiusType type) {
		m_ellips.setBorderRadius(radius, type);
	}

	void Button::setBackgroundColor(const sf::Color& color) {
		m_ellips.setFillColor(color);
	}

	const sf::Color& Button::getColor()const {
		return m_ellips.getFillColor();
	}

	void Button::setTextAutoScale(bool scalable) {
		m_textAutoScale = scalable;
	}
	bool Button::getTextAutoScale()const {
		return m_textAutoScale;
	}

	void Button::setSize(const sf::Vector2u size) {
		sf::Vector2u m_size = m_ellips.getSize();
		m_ellips.setSize(size);
		if (m_textAutoScale) {
			m_text.scale(sf::Vector2f((static_cast<float>(size.x) / m_size.x),\
				static_cast<float>(size.y) / m_size.y));
		}
	}

	void Button::setSize(unsigned int x, unsigned int y) {
		sf::Vector2u m_size = m_ellips.getSize();
		m_ellips.setSize(sf::Vector2u(x , y));
		if (m_textAutoScale) {
			m_text.scale(sf::Vector2f((static_cast<float>(x) / m_size.x), \
				static_cast<float>(y) / m_size.y));
		}
	}

	inline sf::Vector2u Button::getSize()const {
		return m_ellips.getSize();
	}

	void Button::setText(const sf::Text& text) {
		m_text = text;
	}


	const sf::Text& Button::getText() const {
		return m_text;
	}

	bool Button::collidePoint(const sf::Vector2f& point){
		return csf::containPoint(m_ellips.getBoundary() , m_ellips.getPointCount() ,  point);
	}

	bool Button::onEvent(sf::Event event) {
		return false;
	}

	void Button::onDraw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(m_ellips ,  states);
		target.draw(m_text, states);
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		Node::draw(target, states);
	}

	Button::~Button()
	{
	}

}