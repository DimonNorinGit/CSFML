#pragma once

#ifndef CSF_ACTION_GROUP_HPP
#define CSF_ACTION_GROUP_HPP


#include"Action.h"

#include<initializer_list>
#include<vector>

namespace csf {

	class ActionGroup : public Action
	{
	public:

		ActionGroup();

		ActionGroup(std::initializer_list<Action*> actions);

		void append(std::initializer_list<Action*> actions);

		void clear();

		//void deleteActions();

		virtual void restart();

		virtual void update(float elapsed);	
 
		virtual ~ActionGroup();
	private:
		void updateDuration(std::initializer_list<Action*>& actions);
		std::vector<Action*> m_actions;
	};

}


#endif // !CSF_ACTION_GROUP_HPP