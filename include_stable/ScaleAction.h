#pragma once


#ifndef CSF_SCALE_ACTION_HPP
#define CSF_SCALE_ACTION_HPP


#include"SFML/Graphics/Transformable.hpp"
#include"Action.h"
#include"AnimationCurve.h"

namespace csf {

	class ScaleAction : public Action
	{
	public:
		ScaleAction(sf::Transformable& target, float scale, float duration = 1.f, \
			ActionMode mode = ActionMode::ONCE);

		virtual void update(float elapsed);

		void setAnimationCurve(const AnimationCurve& curve);

		void create(float scale, float duration, ActionMode mode = ActionMode::ONCE);

		virtual void restart();

		virtual ~ScaleAction();

	private:
		sf::Transformable& m_target;
		AnimationCurve m_curve;
		float m_scale;
		sf::Vector2f m_startScale;
		
	};


}

#endif // !CSF_SCALE_ACTION_HPP
