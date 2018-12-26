#include "Application.h"

namespace csf {

	Application::Application()
	{

	}

	void Application::run() {	
		onStart();
		while (isOpen()) {
			sf::Event mainEvent;
			while(pollEvent(mainEvent)) {
				onEvent(mainEvent);
			}
			onDraw();
		}
		onEnd();
	}

	void Application::onStart() {
		create(sf::VideoMode(400 , 400) , "Title", sf::Style::Default);
	}


	void Application::onDraw() {

	}

	void Application::onEvent(sf::Event mainEvent) {
		if (mainEvent.type == sf::Event::Closed) {
			close();
		}
	}
	void Application::onEnd() {

	}

	Application::~Application()
	{
	}

}