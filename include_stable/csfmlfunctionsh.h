#pragma once
#ifndef CSF_HELPER_FUNCTIONS_HPP
#define CSF_HELPER_FUNCTIONS_HPP


#include"SFML/System/Vector2.hpp"
#include"SFML/Graphics/VertexArray.hpp"

namespace csf {
	bool containPoint(const  sf::VertexArray& v, const sf::Vector2f& p);

	bool containPoint(const sf::Vertex* v, size_t v_count, const sf::Vector2f& p);

	bool containPoint(const std::vector<sf::Vector2f>& v, size_t v_count, const sf::Vector2f& p);
}



#endif // !CSF_HELPER_FUNCTIONS_HPP