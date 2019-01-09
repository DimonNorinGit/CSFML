#pragma once



#ifndef CSF_OBJECT_HPP
#define CSF_OBJECT_HPP

#include<map>


namespace csf {

	typedef void(*callback)(void*, void*);

	class Object
	{
	public:
		Object();

		void addCallBackGroup(std::string callback_group);

		void removeCallBackGroup(std::string callback_groupe);

		void bind(std::string callback_group, callback call_back, void* args = nullptr, void* obj = nullptr);

		void unbind(std::string callback_group, callback call_back);

		void setCallBackArgs(std::string callback_group, callback call_back, void* args);

		void executeCallbacks(std::string callback_group);

		void executeCallBack(std::string callback_group, callback call_back);

		virtual ~Object();
	private:
		std::map<std::string, std::map<callback, std::pair<void*, void*>>> m_callbacks;
	};


}
#endif // !CSF_OBJECT_HPP