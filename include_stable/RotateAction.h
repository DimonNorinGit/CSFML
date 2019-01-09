#pragma once


#ifndef CSF_ROTATE_ACTION_HPP
#define CSF_ROTATE_ACTION_HPP


#include"SFML/Graphics/Transformable.hpp"
#include"Action.h"
#include"AnimationCurve.h"

namespace csf {

	class RotateAction : public Action
	{
	public:
		RotateAction(sf::Transformable& target , float angle , float duration = 1.f , \
			ActionMode mode = ActionMode::ONCE);

		virtual void update(float elapsed);

		void setAnimationCurve(const AnimationCurve& curve);

		void create(float angle, float duration, ActionMode mode = ActionMode::ONCE);

		virtual ~RotateAction();

	private:
		sf::Transformable& m_target;
		AnimationCurve m_curve;
		float m_angle;
	};


}

#endif // !CSF_ROTATE_ACTION_HPP