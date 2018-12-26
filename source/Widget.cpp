
#include "Widget.h"


namespace csf {

	Widget::Widget()
	{
		
	}

	Widget::Widget(const sf::Texture& texture){
		m_texture = &texture;
		sf::Vector2u t_size = m_texture->getSize();
		m_size = t_size;
		setTextureRect(sf::IntRect(0, 0, t_size.x, t_size.y));
		updatePositions();
		updateTextCoords();
	}



	Widget::Widget(const sf::Texture& texture, const sf::IntRect& rectangle)
	{
		m_texture = &texture;
		m_textureRect = rectangle;
		m_size = sf::Vector2u(m_textureRect.width, m_textureRect.height);
		updatePositions();
		updateTextCoords();
	}


	Widget::Widget(const sf::Texture& texture, const sf::IntRect& rectangle, const sf::Vector2u& size){
		m_texture = &texture;
		m_textureRect = rectangle;
		m_size = size;
		updatePositions();
		updateTextCoords();
	}

	inline bool Widget::onEvent(sf::Event event) {
		return false;
	}
	
	inline void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		Node::draw(target, states);
	}


	void Widget::onDraw(sf::RenderTarget& target, sf::RenderStates states)const {
		// apply the texture
		states.texture = m_texture;

		// you may also override states.shader or states.blendMode if you want

		// draw the vertex array
		target.draw(m_vertices, 4 , sf::Quads , states);
	}




	void Widget::setTextureRect(const sf::IntRect& rectangle) {
		m_textureRect = rectangle;
		updateTextCoords();
	}

	const sf::IntRect& Widget::getTextureRect()const {
		return m_textureRect;
	}


	void Widget::setTexture(const sf::Texture& texture , bool updateSize) {
		m_texture = &texture;
		sf::Vector2u t_size = m_texture->getSize();
		m_size = t_size;
		setTextureRect(sf::IntRect(0, 0, t_size.x, t_size.y));
		if(updateSize) updatePositions();
		updateTextCoords();
	}

	const sf::Texture* Widget::getTexture()const {
		return m_texture;
	}

	void Widget::setColor(const sf::Color& color) {
		for (int i = 0; i < 4; ++i) {
			m_vertices[i].color = color;
		}
	}

	const sf::Color& Widget::getColor()const {
		return m_vertices->color;
	}

	void Widget::setSize(const sf::Vector2u& size) {
		m_size = size;
		updatePositions();
	}

	void Widget::setSize(unsigned int width, unsigned int height) {
		m_size.x = width;
		m_size.y = height;
		updatePositions();
	}

	sf::Vector2u Widget::getSize()const {
		return m_size;
	}

	void Widget::updatePositions() {
		m_vertices[0].position = sf::Vector2f(0 , 0);
		m_vertices[1].position = sf::Vector2f(m_size.x , 0);
		m_vertices[2].position = sf::Vector2f(m_size.x, m_size.y);
		m_vertices[3].position = sf::Vector2f(0, m_size.y);
	}

	void Widget::updateTextCoords() {
		m_vertices[0].texCoords = sf::Vector2f(m_textureRect.left, m_textureRect.top);
		m_vertices[1].texCoords = sf::Vector2f( m_textureRect.left + m_textureRect.width, m_textureRect.top);
		m_vertices[2].texCoords = sf::Vector2f(m_textureRect.left + m_textureRect.width,\
												m_textureRect.top + m_textureRect.height);
		m_vertices[3].texCoords = sf::Vector2f(m_textureRect.left , m_textureRect.top + m_textureRect.height);
	}


	bool Widget::collidePoint(const sf::Vector2f& point)const{
		return csf::containPoint(m_vertices , 4 ,  point);
	}

	Widget::~Widget()
	{
	}
}