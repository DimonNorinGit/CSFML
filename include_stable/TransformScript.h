/*#pragma once


#ifndef CSF_TRANSFORM_SCRIPT_HPP
#define CSF_TRANSFORM_SCRIPT_HPP

//#include"SFML/Graphics/Transform.hpp"
#include"SFML/Graphics/Transformable.hpp"
#include<vector>
//Action class
//Script(act1 , act2)...
namespace csf {

	enum class ActionMode { LOOP, ONCE };

	struct Action {
		float angle;
		sf::Vector2f offset;
		double duration;


	};


	class TransformScript
	{
	public:
		TransformScript(sf::Transformable& target , ActionMode mode = ActionMode::ONCE);

		void addAction(Action&& action);

		void setActionMode(ActionMode mode);

		ActionMode getActionMode()const;

		void update(double elapsed);

		double getTotalLength()const;

		bool inProgress()const;

		void restart();

		virtual ~TransformScript();

	private:
		sf::Transformable& m_target;
		std::vector<Action> m_actions;
		ActionMode m_mode;
		double m_totalLength;
		double m_progress;
		double m_actionProgress;
		size_t m_actionI;
		bool m_inProgress;
	};


}

#endif // !CSF_TRANSFORM_SCRIPT_HPP*/