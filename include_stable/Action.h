#pragma once



#ifndef CSF_ACTION_HPP
#define CSF_ACTION_HPP

namespace csf {

	enum class ActionMode { LOOP, ONCE };

	class Action
	{
	public:
		Action(ActionMode mode = ActionMode::ONCE);

		virtual void update(float elapsed)=0;

		virtual void setActionMode(ActionMode mode);

		virtual ActionMode getActionMode()const;

		virtual void restart();

		virtual float getDuration();

		virtual ~Action();

	protected:
		float m_duration;
		float m_passed;
		float m_progress;
		ActionMode m_mode;
		bool m_inProgress;
	};
}

#endif // !CSF_ACTION_HPP
