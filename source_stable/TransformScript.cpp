/*#include "TransformScript.h"

namespace csf {

	TransformScript::TransformScript(sf::Transformable& target , ActionMode mode):m_target(target)
	{
		m_totalLength = m_progress = m_actionProgress = 0.0;
		m_actionI = 0;
		m_mode = mode;
		m_inProgress = true;
	}

	void TransformScript::addAction(Action&& action) {
		m_totalLength += action.duration;
		m_actions.push_back(std::move(action));
	}

	void  TransformScript::update(double elapsed) {
		if (!m_inProgress) return;

		auto transform = [&](Action& a, double factor) {
			m_target.rotate(a.angle * factor);
			m_target.move(a.offset.x * factor, a.offset.y * factor);
		};


		m_progress += elapsed;
		double p = m_progress;

		for (int i = 0; i < m_actions.size(); ++i) {
			p -= m_actions[i].duration;
			if (p > 0 && &(m_actions[i]) == &(m_actions.back())) {
				if (m_mode == ActionMode::LOOP) {
					m_progress = 0.0;
					m_actionI = 0.0;
					i = -1;
				}
				else if (m_mode == ActionMode::ONCE) {
					m_inProgress = false;
					return;
				}
				continue;
			}
			if (p <= 0 || &(m_actions[i]) == &(m_actions.back())) {
				double factor = 0.0;
						
				if (i != m_actionI) {

					factor = (m_actions[m_actionI].duration - m_actionProgress) / m_actions[m_actionI].duration;
					transform(m_actions[m_actionI], factor);
					//scale

					for (size_t j = 1; j < (i - m_actionI); ++j) {
						transform(m_actions[m_actionI + j], 1);
					}
					m_actionI = i;
					m_actionProgress = 0;
				}
				factor = elapsed / m_actions[i].duration;
				transform(m_actions[i], factor);
				m_actionProgress += elapsed;
				break;
			}
		}
	}

	void  TransformScript::restart() {
		m_progress = 0.0;
		m_actionI = 0;
		m_actionProgress = 0.0;
		m_inProgress = true;
	}

	void TransformScript::setActionMode(ActionMode mode) {
		m_mode = mode;
		restart();
	}

	ActionMode TransformScript::getActionMode() const {
		return m_mode;
	}

	double TransformScript::getTotalLength()const {
		return m_totalLength;
	}

	bool TransformScript::inProgress()const {
		return m_inProgress;
	}

	TransformScript::~TransformScript()
	{
	}
}*/