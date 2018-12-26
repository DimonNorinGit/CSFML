#pragma once

#ifndef CSF_SCREEN_HPP
#define CSF_SCREEN_HPP


#include"SFML/Graphics/RenderTexture.hpp"
#include"SFML/Graphics/Drawable.hpp"
#include"SFML/Graphics/Sprite.hpp"

#include"CSFML/Graphics/Node.h"

namespace csf {
	////////////////////////////////////////////////////////////
	///	/brief drawable and transformable represantation of RenderTexture
	////////////////////////////////////////////////////////////

	class Screen : public sf::Drawable ,  public sf::RenderTexture, public Node
	{
	public:
		Screen();
		virtual ~Screen();
	protected:
		////////////////////////////////////////////////////////////
		///	/brief	define Node's virtual method 
		///			can be can be overridden
		/// /return false  , it means that event passes further by hierarchy
		////////////////////////////////////////////////////////////
		virtual bool onEvent(sf::Event event);

		////////////////////////////////////////////////////////////
		///	/brief	define Node's virtual method 
		///			draw RenderTexture's texture
		////////////////////////////////////////////////////////////
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		////////////////////////////////////////////////////////////
		///	/brief override sf::Drawable::draw
		///		   draw itself and all childrens in the hierarchy
		////////////////////////////////////////////////////////////
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};

}

#endif // !CSF_SCREEN_HPP