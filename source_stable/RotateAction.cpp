#include "RotateAction.h"

namespace csf {

	RotateAction::RotateAction(sf::Transformable& target, float angle, float duration, \
		ActionMode mode):
		Action(mode) , m_target(target) , m_angle(angle) , m_curve(0 , 0 , 1 , 1)
	{
		m_duration = duration;
	}



	void RotateAction::update(float elapsed) {
		if (!m_inProgress) return;
		m_passed += elapsed;
		if (m_passed >= m_duration) {
			m_target.rotate(m_angle * (1 - m_progress));
			if (m_mode == ActionMode::LOOP) {
				float dif = m_passed - m_duration;
				restart();
				m_passed = dif;
			
			}
			else if (m_mode == ActionMode::ONCE) {
				m_inProgress = false;
				return;
			}
		}
		float p = m_curve.getProgress(m_passed / m_duration);
		m_target.rotate(m_angle *  (p - m_progress));
		m_progress = p;
	}

	void RotateAction::create(float angle, float duration, ActionMode mode) {
		m_angle = angle; m_duration = duration; m_mode = mode;
		restart();
	}

	void RotateAction::setAnimationCurve(const AnimationCurve& curve) {
		m_curve = curve;
		restart();
	}
	RotateAction::~RotateAction()
	{
	}
}