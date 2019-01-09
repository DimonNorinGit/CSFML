#include "Button.h"



namespace csf {
	Button::Button()
	{
		m_textAutoScale = true;
		m_size = { 0,0 };
		addCallBackGroup("mouse_pressed");
		addCallBackGroup("mouse_moved");
		addCallBackGroup("mouse_released");
		addCallBackGroup("wheel_scrolled");
		addCallBackGroup("touch_began");
		addCallBackGroup("touch_moved");
		addCallBackGroup("touch_ended");
	}
	Button::Button(const sf::Text& text) {
		m_text = text;
		sf::FloatRect rect = m_text.getGlobalBounds();
		m_size = { static_cast<unsigned int>(rect.width) * 2  ,\
			static_cast<unsigned int>(rect.height) * 2 };
		m_ellips.setSize(m_size);
	}

	Button::Button(const sf::Texture& texture) {
		m_size = texture.getSize();
		m_ellips.setSize(m_size);
		m_ellips.setTexture(&texture);
	}

	Button::Button(const sf::Text& text, const sf::Texture& texture) {
		m_text = text;
		m_size = texture.getSize();
		m_ellips.setSize(m_size);
		m_ellips.setTexture(&texture);
	}

	Button::Button(const sf::Texture& texture, const sf::IntRect& rectangle) {
		m_size = texture.getSize();
		m_ellips.setSize(m_size);
		m_ellips.setTexture(&texture);
		m_ellips.setTextureRect(rectangle);
	}

	void Button::setBorderRadius(size_t radius, BorderRadiusType type) {
		m_ellips.setBorderRadius(radius, type);
	}


	void Button::setTextPosition(TextPosition position) {
		sf::Vector2f pos = { 0 , 0 };
		sf::FloatRect rect = m_text.getGlobalBounds();
		sf::Vector2f t_size = { rect.width , rect.height };

		switch (position) {

		case TextPosition::Center:
			pos = { (m_size.x - t_size.x) / 2  , (m_size.y - t_size.y) / 2 };
			break;

		case TextPosition::TopLeft:
			pos = { 0 , 0 };
			break;

		case TextPosition::TopCenter:
			pos = { (m_size.x - t_size.x) / 2 , 0 };
			break;
		case TextPosition::TopRight:
			pos = { m_size.x - t_size.x , 0 };
			break;
		case TextPosition::BottomLeft:
			pos = { 0 , m_size.y - t_size.y };
			break;
		case TextPosition::BotCenter:
			pos = { (m_size.x - t_size.x) / 2 , m_size.y - t_size.y };
			break;
		case TextPosition::BottomRight:
			pos = { m_size.x - t_size.x , m_size.y - t_size.y };
			break;
		}
		m_text.setPosition(pos);
	}

	void Button::setTextString(std::string string) {
		m_text.setString(string);
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
		m_ellips.setSize(size);
		if (m_textAutoScale) {
			m_text.scale(sf::Vector2f((static_cast<float>(size.x) / m_size.x),\
				static_cast<float>(size.y) / m_size.y));
		}
		m_size = size;
	}

	void Button::setSize(unsigned int x, unsigned int y) {
		m_ellips.setSize(sf::Vector2u(x , y));
		if (m_textAutoScale) {
			m_text.scale(sf::Vector2f((static_cast<float>(x) / m_size.x), \
				static_cast<float>(y) / m_size.y));
		}
		m_size = {x , y};
	}

	sf::Vector2u Button::getSize()const {
		return m_size;
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


	bool Button::mouseWheelScrolled(wheelScrolled w_scrolled) {
		if (collidePoint(w_scrolled.point))executeCallbacks("wheel_scrolled");
		return false;
	}

	bool Button::mousePressed(mouseTouch touch) {
		if (collidePoint(touch.point)) executeCallbacks("mouse_pressed");
		return false;
	}

	bool Button::mouseReleased(mouseTouch touch) {
		if (collidePoint(touch.point))executeCallbacks("mouse_released");
		return false;
	}

	bool Button::mouseMoved(mouseMove move) {
		if (collidePoint(move.point))executeCallbacks("mouse_moved");
		return false;
	}

	bool Button::touchBegan(sensorTouch touch) {
		if (collidePoint(touch.point))executeCallbacks("touch_began");
		return false;
	}

	bool Button::touchEnded(sensorTouch touch) {
		if (collidePoint(touch.point))executeCallbacks("touch_ended");
		return false;
	}

	bool Button::touchMoved(sensorTouch touch) {
		if (collidePoint(touch.point))executeCallbacks("touch_moved");
		return false;
	}

	Button::~Button()
	{
	}

}