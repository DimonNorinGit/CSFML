

#pragma once


#ifndef CSF_WIDGET_HPP
#define CSF_WIDGET_HPP

#include"SFML/Graphics/Texture.hpp"
#include<vector>


#include"Node.h"
#include"csfmlfunctionsh.h"

namespace csf {
	////////////////////////////////////////////////////////////
	///	/brief graphic primitive with its own Transform , color,
	///		   texture , uses for base block in drawable hierarhy
	////////////////////////////////////////////////////////////
	class Widget : public sf::Drawable , public Node
	{
	public:

		Widget();
		////////////////////////////////////////////////////////////
		///	/brief set texture  , widget will get texture size
		////////////////////////////////////////////////////////////
		explicit Widget(const sf::Texture& texture);

		////////////////////////////////////////////////////////////
		///	/brief set texture  and it's rect
		////////////////////////////////////////////////////////////
		Widget(const sf::Texture& texture, const sf::IntRect& rectangle);


		////////////////////////////////////////////////////////////
		///	/brief set texture  and it's rect
		/// /param size to define widget size
		////////////////////////////////////////////////////////////
		Widget(const sf::Texture& texture, const sf::IntRect& rectangle , const sf::Vector2u& size);


		////////////////////////////////////////////////////////////
		///	/brief set texture 
		/// /param updateSize true: the widget size will be resized
		///  to texture size
		////////////////////////////////////////////////////////////
		void setTexture(const sf::Texture& texture , bool updateSize = false);


		////////////////////////////////////////////////////////////
		///	/brief set texture rect
		////////////////////////////////////////////////////////////
		void setTextureRect(const sf::IntRect& rectangle);


		////////////////////////////////////////////////////////////
		///	/brief set new color
		/// /default white
		////////////////////////////////////////////////////////////
		void setColor(const sf::Color& color);
		
		//
		void setSize(const sf::Vector2u& size);

		//
		void setSize(unsigned int width, unsigned int height);

		//
		const sf::IntRect& getTextureRect()const;
		//
		const sf::Texture* getTexture()const;
		//
		const sf::Color& getColor()const;
		//
		sf::Vector2u getSize()const;

		bool collidePoint(const sf::Vector2f& point)const;
	
		virtual ~Widget();

	protected:

		virtual bool onEvent(sf::Event event);
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states)const;

	private:


		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void updatePositions();// update vertices positions 

		void updateTextCoords(); // update vertices text coordinates



		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////

		sf::Vertex m_vertices[4]; ///< Vertices defining the sprite's geometry
		const sf::Texture* m_texture; ///< Texture of the widget
		sf::Vector2u m_size;	/// widget world size
		sf::IntRect m_textureRect; ///< Rectangle defining the area of the source texture to display
	};
}

#endif // !CSF_WIDGET_HPP

