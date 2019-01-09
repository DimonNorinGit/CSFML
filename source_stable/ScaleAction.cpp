#include "ScaleAction.h"

#include "RotateAction.h"

namespace csf {

	ScaleAction::ScaleAction(sf::Transformable& target, float scale, float duration, \
		ActionMode mode) :
		Action(mode) , m_target(target), m_scale(scale), m_curve(0, 0, 1, 1)
	{
		m_startScale = m_target.getScale();
		m_duration = duration;
	}

	void ScaleAction::update(float elapsed) {
		if (!m_inProgress) return;
		sf::Vector2f ñ_scale = m_target.getScale();
		m_passed += elapsed;
		if (m_passed >= m_duration) {
			float c = (m_scale - 1) *  (1 - m_progress);
			m_target.setScale(ñ_scale.x + c * m_startScale.x, ñ_scale.y + c * m_startScale.y);
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
		float c = (m_scale - 1) *  (p - m_progress);
		m_target.setScale(ñ_scale.x + c * m_startScale.x, ñ_scale.y + c * m_startScale.y);
		m_progress = p;
	}

	void ScaleAction::create(float scale, float duration, ActionMode mode) {
		m_scale = scale; m_duration = duration; m_mode = mode;
		restart();
	}

	void ScaleAction::setAnimationCurve(const AnimationCurve& curve) {
		m_curve = curve;
		restart();
	}

	void ScaleAction::restart() {
		Action::restart();
		m_startScale = m_target.getScale();
	}

	ScaleAction::~ScaleAction()
	{
	}
}