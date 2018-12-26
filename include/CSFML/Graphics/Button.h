#pragma once

#ifndef CSF_BUTTON_HPP
#define CSF_BUTTON_HPP


#include"SFML/Graphics/Text.hpp"

#include"CSFML/Graphics/Node.h"
#include"CSFML/Graphics/SuperEllipse.h"
#include"CSFML/Graphics/csfmlfunctionsh.h"

namespace csf {

	class Button : public Node , public sf::Drawable
	{
	public:

		Button();

		explicit Button(const sf::Text& text);

		explicit Button(const sf::Texture& texture);

		Button(const sf::Text& text, const sf::Texture& texture);

		Button(const sf::Texture& texture , const sf::IntRect& rectangle);


		void setBackgroundColor(const sf::Color& color);

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

		virtual ~Button();

	protected:

		virtual bool onEvent(sf::Event event);

		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states)const;

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Text m_text;

		SuperEllipse m_ellips;

		bool m_textAutoScale;
	};

}

#endif // !CSF_BUTTON_HPP