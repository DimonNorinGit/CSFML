#include "TranslateAction.h"



namespace csf {

	TranslateAction::TranslateAction(sf::Transformable& target, const sf::Vector2f& offset, float duration,\
		ActionMode mode):
		Action(mode) , m_target(target) , m_offset(offset), m_curve(0, 0, 1, 1)
	{
		m_duration = duration;
	}

	void TranslateAction::update(float elapsed){
		if (!m_inProgress) return;
		
		m_passed += elapsed;
		if (m_passed >= m_duration) {
			m_target.move(m_offset.x * (1 - m_progress), m_offset.y * (1 - m_progress));
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
		float c = p - m_progress;
		m_target.move(m_offset.x * c  , m_offset.y * c);
		m_progress = p;
	}

	void TranslateAction::setAnimationCurve(const AnimationCurve& curve){
		m_curve = curve;
		restart();
	}

	void TranslateAction::create(const sf::Vector2f& offset, float duration, ActionMode mode) {
		m_offset = offset; m_duration = duration; m_mode = mode;
		restart();
	}

	TranslateAction::~TranslateAction()
	{
	}


}