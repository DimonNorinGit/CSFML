#pragma once





#ifndef CSF_BUTTON_HPP
#define CSF_BUTTON_HPP


#include"SFML/Graphics/Text.hpp"
#include"Node.h"
#include"SuperEllipse.h"
#include"csfmlfunctionsh.h"

namespace csf {


	////////////////////////////////////////
	//mouse_pressed
	//mouse_moved
	//mouse_released
	//wheel_scrolled
	//touch_began
	//touch_moved
	//touch_ended
	////////////////////////////////////////
	enum class TextPosition{ TopLeft = 0, TopRight = 1, BottomRight = 2,\
		BottomLeft = 3 , Center = 4 , TopCenter = 5 , BotCenter = 6};

	class Button : public Node , public sf::Drawable
	{
	public:

		Button();

		explicit Button(const sf::Text& text);

		explicit Button(const sf::Texture& texture);

		Button(const sf::Text& text, const sf::Texture& texture);

		Button(const sf::Texture& texture , const sf::IntRect& rectangle);


		void setBackgroundColor(const sf::Color& color);

		void setTextPosition(TextPosition position);

		void setTextString(std::string string);

		void setTextAutoScale(bool scalable);

		void setSize(const sf::Vector2u size);

		void setSize(unsigned int x, unsigned int y);

		void setText(const sf::Text& text);

		void setBorderRadius(size_t radius, BorderRadiusType type = BorderRadiusType::All);

		bool getTextAutoScale()const;

		const sf::Color& getColor()const;

		sf::Vector2u getSize()const;

		const sf::Text& getText() const;

		bool collidePoint(const sf::Vector2f& point);


		virtual bool mouseWheelScrolled(wheelScrolled w_scrolled);

		virtual bool mousePressed(mouseTouch touch);

		virtual bool mouseReleased(mouseTouch touch);

		virtual bool mouseMoved(mouseMove move);

		virtual bool touchBegan(sensorTouch touch);

		virtual bool touchEnded(sensorTouch touch);

		virtual bool touchMoved(sensorTouch touch);

		virtual ~Button();

	protected:

		virtual bool onEvent(sf::Event event);

		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states)const;

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Text m_text;

		SuperEllipse m_ellips;

		sf::Vector2u m_size;

		bool m_textAutoScale;
	};

}

#endif // !CSF_BUTTON_HPP