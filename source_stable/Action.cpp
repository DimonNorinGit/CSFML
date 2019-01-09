#include "Action.h"

namespace csf {

	Action::Action(ActionMode mode)
	{
		m_duration = m_passed = m_progress = 0.0;
		m_mode = mode;
		m_inProgress = true;
	}

	void Action::setActionMode(ActionMode mode) {
		m_mode = mode;
		restart();
	}

	ActionMode Action::getActionMode()const {
		return m_mode;
	}

	void Action::restart() {
		m_inProgress = true;
		m_passed = m_progress = 0.0;
	}

	float Action::getDuration() {
		return m_duration;
	}


	Action::~Action()
	{
	}
}