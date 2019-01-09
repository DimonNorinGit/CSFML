#pragma once

#ifndef CSF_TRANSLATE_ACTION_HPP
#define CSF_TRANSLATE_ACTION_HPP

#include"Action.h"
#include"AnimationCurve.h"

#include"SFML/Graphics/Transformable.hpp"

namespace csf {

	class TranslateAction : public Action
	{
	public:
		TranslateAction(sf::Transformable& target , const sf::Vector2f& offset , float duration = 1.f,\
			ActionMode mode = ActionMode::ONCE);

		virtual void update(float elapsed);

		void setAnimationCurve(const AnimationCurve& curve);

		void create(const sf::Vector2f& offset, float duration, ActionMode mode = ActionMode::ONCE);

		virtual ~TranslateAction();


	private:

		AnimationCurve m_curve;
		sf::Transformable& m_target;
		sf::Vector2f m_offset;
	};
}

#endif // !CSF_TRANSLATE_ACTION_HPP