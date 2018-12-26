

#include "SuperEllipse.h"


namespace csf {


	SuperEllipse::SuperEllipse() :m_size({ 0,0 })
	{
		m_borderRadius[0] = 0;
		m_borderRadius[1] = 0;
		m_borderRadius[2] = 0;
		m_borderRadius[3] = 0;
		m_pointCount = 4;
		updateBoundary();
	}

	void SuperEllipse::updateBoundary() {
		m_boundary.clear();
		m_boundary.reserve(m_pointCount);
		
		updateBorderRadius(BorderRadiusType::TopLeft, m_borderRadius[0] * 2 + 1 );
		updateBorderRadius(BorderRadiusType::TopRight, m_borderRadius[1] * 2 + 1);
		updateBorderRadius(BorderRadiusType::BottomRight, m_borderRadius[2] * 2 + 1);
		updateBorderRadius(BorderRadiusType::BottomLeft, m_borderRadius[3] * 2 + 1);
		update();
	}


	const std::vector<sf::Vector2f>& SuperEllipse::getBoundary()const {
		return m_boundary;
	}

	void SuperEllipse::updateBorderRadius(BorderRadiusType type , size_t pcount) {
		static const float pi = 3.141592654f;
		size_t radius = m_borderRadius[type];
		//opt
		std::function<sf::Vector2f(float x , float y)> transform[4] = \
		{
			[&](float x , float y) {return sf::Vector2f(radius - x, radius - y); },
			[&](float x, float y) {return sf::Vector2f(m_size.x - radius + y , radius - x); },
			[&](float x, float y) {return sf::Vector2f((m_size.x - radius) + x, (m_size.y - radius) + y); },
			[&](float x, float y) {return sf::Vector2f(radius - y, (m_size.y - radius) + x); },
		};

		sf::Vector2f point;
		float  angle, x, y;

		for (size_t p = 0; p < pcount; ++p) {
			angle = (pi / 2) * p / pcount;
			x = std::cos(angle) * radius;
			y = std::sin(angle) * radius;
			m_boundary.push_back(transform[type](x, y));
		}
	}


	std::size_t SuperEllipse::getPointCount() const
	{
		return m_pointCount;
	}

	sf::Vector2f SuperEllipse::getPoint(std::size_t index) const
	{
		return m_boundary[index];
	}

	

	void SuperEllipse::setSize(const sf::Vector2u& size) {
		m_size = size;
		updateBoundary();
	}

	sf::Vector2u SuperEllipse::getSize()const {
		return m_size;
	}

	void SuperEllipse::setSize(unsigned int x, unsigned int y) {
		m_size.x = x;
		m_size.y = y;
		updateBoundary();
	}

	void SuperEllipse::setBorderRadius(size_t radius, BorderRadiusType type) {

		if (radius > (m_size.x / 2) || radius > (m_size.y / 2)) {
			radius = m_size.x < m_size.y ? (m_size.x / 2) : (m_size.y / 2);
		}

		if (type == BorderRadiusType::All) {
			m_borderRadius[0] = radius;
			m_borderRadius[1] = radius;
			m_borderRadius[2] = radius;
			m_borderRadius[3] = radius;
			m_pointCount = radius * 2 * 4;
		}
		else {
			m_pointCount -= (m_borderRadius[type] * 2 + 1);
			m_pointCount += (radius * 2 + 1);
			m_borderRadius[type] = radius;
		}
		updateBoundary();
	}


	SuperEllipse::~SuperEllipse()
	{
	}

}