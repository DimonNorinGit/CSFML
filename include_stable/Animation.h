#pragma once

#ifndef CSF_ANIMATION_HPP
#define CSF_ANIMATION_HPP

#include<vector>

#include"SFML/Graphics/Sprite.hpp"

#include"AnimationCurve.h"

#include"Action.h"

// pointer to Animation

namespace csf {

	struct Frame {
		sf::IntRect rect;
		double duration;
	};

	class Animation : public Action
	{
	public:
		Animation(sf::Sprite& target , ActionMode mode = ActionMode::LOOP);

		void addFrame(Frame&& frame);

		void setAnimationCurve(const AnimationCurve& curve);

		virtual void update(float elapsed);

		virtual ~Animation();

	private:
		std::vector<Frame> m_frames;
		sf::Sprite& m_target;
		AnimationCurve m_curve;
	};

}

#endif // !CSF_ANIMATION_HPP