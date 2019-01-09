#include "ActionGroup.h"

namespace csf {

	ActionGroup::ActionGroup() {

	}

	ActionGroup::ActionGroup(std::initializer_list<Action*> actions): m_actions(actions)	
	{
		updateDuration(actions);
	}

	void ActionGroup::updateDuration(std::initializer_list<Action*>& actions) {
		for (auto a : actions) {
			float d = a->getDuration();
			if (d > m_duration) m_duration = d;
		}
	}
	
	void ActionGroup::append(std::initializer_list<Action*> actions){
		m_actions.insert(m_actions.begin(), actions.begin(), actions.end());
		updateDuration(actions);
		restart();
	}

	void ActionGroup::update(float elapsed) {
		if (!m_inProgress) return;
		m_passed += elapsed;
		for (auto a : m_actions) {
			a->update(elapsed);
		}
		if (m_passed >= m_duration) {
			if (m_mode == ActionMode::LOOP) {
				float dif = m_passed - m_duration;
				restart();
				m_passed = dif;
			}
			else if (m_mode == ActionMode::ONCE) {
				m_inProgress = false;
			}
		}
	}

	/*void ActionGroup::deleteActions() {
		for (auto a : m_actions) {
			delete a;
		}
		m_actions.clear();
	}*/

	void ActionGroup::restart() {
		Action::restart();
		for (auto a : m_actions) {
			a->restart();
		}
	}

	void ActionGroup::clear() {
		m_actions.clear();
		m_inProgress = false;
	}

	ActionGroup::~ActionGroup()
	{
	}

}