#include "ScreenManager.h"


namespace csf {
	ScreenManager::ScreenManager():m_currentScreen(nullptr)
	{

	}

	void ScreenManager::setCurrent(const std::string& name) {
		auto found = m_screens.find(name);
		if (found != m_screens.end()) {
			m_currentScreen = found->second;
		}
		else {
			//exeption: screen not found
		}
	}

	void ScreenManager::addScreen(Screen* screen, const std::string& name) {
		if (m_screens.find(name) == m_screens.end()) {
			if (m_screens.empty())m_currentScreen = screen;
			m_screens[name] = screen;	
		}
		else {
			//exeption: name already exist
		}
	}

	void ScreenManager::removeScreen(const std::string& name) {
		auto found = m_screens.find(name);
		if (found != m_screens.end()) {
			m_screens.erase(found);
		}
		else {
			//exeption: screen not found
		}
		if (m_screens.empty()) m_currentScreen = nullptr;
	}

	Screen* ScreenManager::getCurrentScreen() const {
		if (m_currentScreen == nullptr) {
			//rise exeption
		}
		return m_currentScreen;
	}

	ScreenManager::~ScreenManager()
	{

	}
}