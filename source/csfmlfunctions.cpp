
#include"csfmlfunctionsh.h"

namespace csf {

	bool containPoint(const  sf::VertexArray& v, const sf::Vector2f& p) {
		size_t v_count = v.getVertexCount();
		if (v_count < 3) return true;
		for (int i = 0; i < v_count; ++i) {
			float vmulti = (p.x - v[i].position.x) * (v[(i + 1) % v_count].position.y - v[i].position.y) - \
				(p.y - v[i].position.y) * (v[(i + 1) % v_count].position.x - v[i].position.x);
			if (vmulti > 0) return false;
		}
		return true;
	}


	bool containPoint(const sf::Vertex* v, size_t v_count, const sf::Vector2f& p) {
		if (v_count < 3) return true;
		for (int i = 0; i < v_count; ++i) {
			float vmulti = (p.x - v[i].position.x) * (v[(i + 1) % v_count].position.y - v[i].position.y) - \
				(p.y - v[i].position.y) * (v[(i + 1) % v_count].position.x - v[i].position.x);
			if (vmulti > 0) return false;
		}
		return true;
	}


	bool containPoint(const std::vector<sf::Vector2f>& v, size_t v_count, const sf::Vector2f& p) {
		if (v_count < 3) return true;
		for (int i = 0; i < v_count; ++i) {
			float vmulti = (p.x - v[i].x) * (v[(i + 1) % v_count].y - v[i].y) - \
				(p.y - v[i].y) * (v[(i + 1) % v_count].x - v[i].x);
			if (vmulti > 0) return false;
		}
		return true;
	}
}