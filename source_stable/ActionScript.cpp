#include "ActionScript.h"

namespace csf {

	ActionScript::ActionScript()
	{
	}

	ActionScript::ActionScript(std::initializer_list<Action*> actions): m_actions(actions)
	{
		updateDuration(actions);
	}

	void ActionScript::append(std::initializer_list<Action*> actions) {
		m_actions.insert(m_actions.end(), actions.begin(), actions.end());
		updateDuration(actions);
	}

	void ActionScript::addAction(Action* action) {
		m_actions.push_back(action);
		m_duration += action->getDuration();
		restart();
	}

	void ActionScript::update(float elapsed){
		if (!m_inProgress) return;
		m_passed += elapsed;
		float p = m_passed;


		if (p >= m_duration) {
			m_actions.back()->update(elapsed);
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

		for (size_t a = 0; a < m_actions.size(); ++a) {
		
			p -= m_actions[a]->getDuration();

			if (p <= 0.0 || &(m_actions[a]) == &(m_actions.back())) {
				m_actions[a]->update(elapsed);
				break;
			}
		}
	}

	void ActionScript::restart() {
		for (auto a : m_actions) {
			a->restart();
		}
	}

	void ActionScript::clear() {
		m_actions.clear();
		m_inProgress = false;
	}

	void ActionScript::updateDuration(std::initializer_list<Action*>& actions){
		for (auto a : actions) {
			m_duration += a->getDuration();
		}
	}

	ActionScript::~ActionScript()
	{
	}
}