#pragma once

#ifndef CSF_APPLICATION_HPP
#define CSF_APPLICATION_HPP

#include"SFML/Graphics/RenderWindow.hpp"
#include"SFML/Window/Event.hpp"

#include"CSFML/Graphics/ScreenManager.h"
#include"CSFML/Graphics/Widget.h"

namespace csf {
	class Application : public sf::RenderWindow
	{
	public:

		Application();

		virtual void run();

		~Application();

	protected:
		virtual void onEvent(sf::Event mainEvent);
		virtual void onDraw();
		virtual void onStart();
		virtual void onEnd();
	};
}
#endif // !CSF_APPLICATION_HPP