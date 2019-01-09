#pragma once

#ifndef CSF_SCREEN_MANAGER_HPP
#define CSF_SCREEN_MANAGER_HPP
#include<map>
#include"Screen.h"

namespace csf {

	////////////////////////////////////////////////////////////
	///	/brief manages user screens
	////////////////////////////////////////////////////////////

	class ScreenManager
	{
	public:
		

		ScreenManager();
		////////////////////////////////////////////////////////////
		///	/brief add screen by name
		///  if screen with this name already exists ...
		///  
		////////////////////////////////////////////////////////////
		void addScreen(Screen* screen, const std::string& name);
		////////////////////////////////////////////////////////////
		///	/brief remove screen by name
		///  if screen with this name not exists ...
		///  
		////////////////////////////////////////////////////////////
		void removeScreen(const std::string& name);

		////////////////////////////////////////////////////////////
		///	/brief  ret current screen 
		/// /return it will be nullptr if there is no added screens
		////////////////////////////////////////////////////////////
		Screen* getCurrentScreen() const;


		////////////////////////////////////////////////////////////
		///	/brief  set current screen by name
		/// /  if screen with this name not exists ...
		////////////////////////////////////////////////////////////
		void setCurrent(const std::string& name);

		~ScreenManager();

	private:
		std::map<std::string, Screen*> m_screens;//< 
		Screen* m_currentScreen;//<
	};

}

#endif // !CSF_SCREEN_MANAGER_HPP