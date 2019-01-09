#pragma once


#ifndef CSF_ANIMATION_CURVE_HPP
#define CSF_ANIMATION_CURVE_HPP

#include"SFML/System/Vector2.hpp"
#include<iostream>
#include<vector>

namespace csf {

	enum class AnimationFunction { linear, ease , ease_in , ease_out , ease_in_out};

	class AnimationCurve
	{
	public:
		AnimationCurve(float x1 , float y1 , float x2 , float y2);

		void setType(AnimationFunction type);

		void create(float x1, float y1, float x2, float y2);

		float getProgress(float time)const;//0 ... 1

		virtual ~AnimationCurve();
		
	private:
		void update();
		sf::Vector2f m_points[2];
		float m_step;
		float m_factors[3];
	};

}

#endif // !CSF_ANIMATION_CURVE_HPP

