#pragma once

#ifndef CSF_ACTION_SCRIPT_HPP
#define CSF_ACTION_SCRIPT_HPP

#include"Action.h"
#include<vector>

namespace csf {

	class ActionScript : Action
	{
	public:
		ActionScript();

		ActionScript(std::initializer_list<Action*> actions);

		void append(std::initializer_list<Action*> actions);

		void addAction(Action* action);

		void clear();

		virtual void update(float elapsed);

		virtual void restart();

		virtual ~ActionScript();

	private:
		void updateDuration(std::initializer_list<Action*>& actions);
		std::vector<Action*> m_actions;
	};

}

#endif // !CSF_ACTION_SCRIPT_HPP