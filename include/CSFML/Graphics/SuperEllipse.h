#pragma once




#ifndef CSF_SUPERELLIPSE_HPP
#define CSF_SUPERELLIPSE_HPP

#include"SFML/Graphics/Shape.hpp"

#include<iostream>
#include<functional>


namespace csf {

	enum BorderRadiusType{TopLeft = 0 , TopRight = 1 , BottomRight = 2 ,  BottomLeft = 3 , All = 4};

	class SuperEllipse : public sf::Shape
	{
	public:

		SuperEllipse();

		virtual std::size_t getPointCount() const;

		virtual sf::Vector2f getPoint(std::size_t index) const;

		void setBorderRadius(size_t radius , BorderRadiusType type = BorderRadiusType::All);

		const std::vector<sf::Vector2f>& getBoundary()const;

		void setSize(const sf::Vector2u& size);

		void setSize(unsigned int x , unsigned int y);

		sf::Vector2u getSize()const;

		virtual ~SuperEllipse();

	private:

		void updateBorderRadius(BorderRadiusType type, size_t pcount);

		void updateBoundary();

		size_t m_pointCount;
		sf::Vector2u m_size;
		size_t m_borderRadius[4];
		std::vector<sf::Vector2f> m_boundary;
	};

}
#endif
