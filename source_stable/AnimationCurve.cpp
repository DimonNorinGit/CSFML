#include "AnimationCurve.h"

namespace csf {

	AnimationCurve::AnimationCurve(float x1, float y1, float x2, float y2)
	{
		create(x1, y1, x2, y2);
	}

	void AnimationCurve::create(float x1, float y1, float x2, float y2) {
		m_points[0] = { x1 , y1 };
		m_points[1] = { x2 , y2 };
		update();
	}


	void AnimationCurve::update() {
		m_factors[0] = (3.f * m_points[0].x - 3.f * m_points[1].x + 1.f);
		m_factors[1] = (3.f *m_points[1].x - 6.f * m_points[0].x);
		m_factors[2] = (3.f *m_points[0].x);

	}

	float AnimationCurve::getProgress(float time)const {
		float xi = 0.5f , xi_1 = 0.f , f = 0 , df = 0.f;
		while (std::fabs(xi - xi_1) > 0.001f) {
			f = m_factors[0] * (xi * xi * xi) + m_factors[1] * (xi * xi) + m_factors[2] * xi - time;
			df = m_factors[0] * 3.f * (xi * xi) + 2.f * m_factors[1] * xi + m_factors[2];
			xi_1 = xi - f / df;
			std::swap(xi, xi_1);
		}
		float rt = 1 - xi_1, t = xi_1;
		return 3.f * rt * rt * t * m_points[0].y + 3.f * rt * t * t * m_points[1].y + t * t * t;
	}
	

	void AnimationCurve::setType(AnimationFunction type) {	
		switch (type) {
			case AnimationFunction::linear:
				m_points[0] = {0.f,0.f};
				m_points[1] = {1.f,1.f};
				break;
			case AnimationFunction::ease:
				m_points[0] = { 0.25f , 0.1f };
				m_points[1] = { 0.25f , 0.1f };
				break;
			case AnimationFunction::ease_in:
				m_points[0] = { 0.42f, 0.f };
				m_points[1] = { 1.f,1 };
				break;
			case AnimationFunction::ease_out:
				m_points[0] = { 0.f,0.f };
				m_points[1] = { 0.58f,1.f };
				break;
		}
		update();
	}

	AnimationCurve::~AnimationCurve()
	{
	}

}