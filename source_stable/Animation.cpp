#include "Animation.h"



namespace csf {

	Animation::Animation(sf::Sprite& target , ActionMode mode):
		Action(mode) , m_target(target) , m_curve(0 , 0 , 1 , 1)
		
	{

	}

	void Animation::addFrame(Frame&& frame) {
		m_duration += frame.duration;
		m_frames.push_back(std::move(frame));
		restart();
	}

	void Animation::setAnimationCurve(const AnimationCurve& curve) {
		m_curve = curve;
		restart();
	}

	void Animation::update(float elapsed) {
		//rewrite algorithm
		if (!m_inProgress) return;
		m_passed += elapsed;

		/*double t = m_passed / m_totalLength;
		double progress = m_curve.getProgress(t);
		double p = progress * m_totalLength;*/

		float p = m_duration * m_curve.getProgress(m_passed / m_duration);
		

		if (m_passed >= m_duration) {
			m_target.setTextureRect(m_frames.back().rect);
			if (m_mode == ActionMode::LOOP) {
				float dif = m_passed - m_duration;
				restart();
				m_passed = dif;
				return;
			}
			else {
				m_inProgress = false;
				return;
			}
		}
		
		for (size_t f = 0; f < m_frames.size(); ++f) {

			p -= m_frames[f].duration;

			if (p <= 0.f || &(m_frames[f]) == &(m_frames.back())) {
				m_target.setTextureRect(m_frames[f].rect);
				break;
			}
			
		}
	}

	Animation::~Animation()
	{
	}

}