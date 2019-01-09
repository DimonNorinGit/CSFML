#include "Application.h"

namespace csf {

	Application::Application()
	{

	}

	void Application::run() {	
		onStart();
		while (isOpen()) {
			m_timer.restart();
			sf::Event mainEvent;
			while(pollEvent(mainEvent)) {
				onEvent(mainEvent);
			}
			onRun();
			onDraw();
			m_elapsed = m_timer.getElapsedTime();
		}
		onEnd();
	}

	sf::Time Application::getElapsedTime() const {
		return m_elapsed;
	}

	void Application::onStart() {
		create(sf::VideoMode(400 , 400) , "Title", sf::Style::Default);
	}

	void Application::onRun() {

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