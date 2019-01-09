#pragma once

#ifndef CSF_APPLICATION_HPP
#define CSF_APPLICATION_HPP

#include"SFML/Graphics/RenderWindow.hpp"
#include"SFML/Window/Event.hpp"
#include"ScreenManager.h"
#include"Widget.h"


namespace csf {
	class Application : public sf::RenderWindow
	{
	public:

		Application();

		virtual void run();

		virtual sf::Time getElapsedTime() const;

		~Application();

	protected:
		virtual void onEvent(sf::Event mainEvent);
		virtual void onRun();
		virtual void onDraw();
		virtual void onStart();
		virtual void onEnd();
	private:
		sf::Clock m_timer;
		sf::Time m_elapsed;
	};
	
}
#endif // !CSF_APPLICATION_HPP