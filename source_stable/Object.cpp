#include "Object.h"


namespace csf {
	Object::Object()
	{
	}

	void Object::addCallBackGroup(std::string callback_group) {
		m_callbacks[callback_group];
	}

	void Object::removeCallBackGroup(std::string callback_groupe) {
		m_callbacks.erase(callback_groupe);
	}

	void Object::bind(std::string callback_group, callback call_back, void* args, void* obj) {
		m_callbacks[callback_group][call_back] = (std::make_pair(args, obj));
	}

	void Object::unbind(std::string callback_group, callback call_back) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		m_callbacks[callback_group].erase(call_back);
	}

	void Object::setCallBackArgs(std::string callback_group, callback call_back, void* args) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		if (m_callbacks[callback_group].find(call_back) == m_callbacks[callback_group].end()) return;
		m_callbacks[callback_group][call_back].first = args;
	}

	void Object::executeCallbacks(std::string callback_group) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		for (auto func : m_callbacks[callback_group]) func.first(func.second.first, func.second.first);
	}

	void Object::executeCallBack(std::string callback_group, callback call_back) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		if (m_callbacks[callback_group].find(call_back) == m_callbacks[callback_group].end()) return;
		std::pair<void*, void*>& params = m_callbacks[callback_group][call_back];
		call_back(params.first, params.second);
	}

	Object::~Object()
	{
	}
}