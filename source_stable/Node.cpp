
#include "Node.h"


namespace csf {

	Node::Node()
	{

	}


	Node::Node(const Node& node)
	{
		m_topIndex = 0;
		m_ZetIndex = 0;
		m_parent = 0;
	}

	Node& Node::operator=(const Node& node)
	{
		return *this;
	}

	void Node::setParent(Node* parent) {
		m_parent = parent;
	}

	void Node::updateZetIndex(Node* child) {
		std::list<Node*>::const_iterator found = std::find(m_children.cbegin(), m_children.cend(), child);
		int index = (*found)->getZetIndex();
		std::list<Node*>::const_iterator forward = found, back = found;
		m_children.push_front(0);

		for (; back != m_children.begin(); --back) {
			if ((*back)->getZetIndex() > index) {
				++back;
				break;
			}
		}
		if (back == m_children.begin()) ++back;

		if (back != found) {
			m_children.erase(found);
			m_children.insert(back, child);
			m_children.pop_front();
			return;
		}

		for (; forward != m_children.end(); ++forward) {
			if ((*forward)->getZetIndex() < index) {
				--forward;
				break;
			}
		}
		m_children.erase(found);
		m_children.insert(forward, child);
		m_children.pop_front();
	}

	void Node::setZetIndex(int index) {
		m_ZetIndex = index;
		if (m_parent == 0) return;
		m_parent->updateZetIndex(this);
	}

	int Node::getZetIndex()const {
		return m_ZetIndex;
	}

	void Node::addNode(Node* node)
	{
		node->setZetIndex(m_topIndex++);
		m_children.push_front(node);
		node->setParent(this);
	}

	void Node::removeNode(Node* node) {
		node->setParent(0);
		m_children.remove(node);
	}


	void Node::draw(sf::RenderTarget& target, sf::RenderStates parentStates) const
	{
		// combine the parent transform with the node's one
		parentStates.transform *= getTransform();
		// let the node draw itself
		onDraw(target, parentStates);

		for (auto ch = m_children.rbegin(); ch != m_children.rend(); ++ch) {
			(*ch)->draw(target, parentStates);
		}
	}


	bool Node::delegateEvent(sf::Event event , positionEvent pos_event) {
		bool catched = false;

		sf::Transform transform = getInverseTransform();

		wheelScrolled w_scrolled;
		mouseTouch mtouch;
		mouseMove move;
		sensorTouch stouch;
		//need optimize

		switch (event.type) {
		case sf::Event::MouseWheelScrolled:
			if (!pos_event.isActive) {
				pos_event.point.x = event.mouseWheelScroll.x;
				pos_event.point.y = event.mouseWheelScroll.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			w_scrolled.point = pos_event.point;
			w_scrolled.delta = event.mouseWheelScroll.delta;
			w_scrolled.wheel = event.mouseWheelScroll.wheel;
			break;
		case sf::Event::MouseButtonPressed:

			if (!pos_event.isActive) {
				pos_event.point.x = event.mouseButton.x;
				pos_event.point.y = event.mouseButton.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			mtouch.point = pos_event.point;
			mtouch.button = event.mouseButton.button;
			break;
		case sf::Event::MouseButtonReleased:
			if (!pos_event.isActive) {
				pos_event.point.x = event.mouseButton.x;
				pos_event.point.y = event.mouseButton.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			mtouch.point = pos_event.point;
			mtouch.button = event.mouseButton.button;
			break;
		case sf::Event::MouseMoved:
			if (!pos_event.isActive) {
				pos_event.point.x = event.mouseMove.x;
				pos_event.point.y = event.mouseMove.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			move.point = pos_event.point;
			break;
		case sf::Event::TouchBegan:
			if (!pos_event.isActive) {
				pos_event.point.x = event.touch.x;
				pos_event.point.y = event.touch.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			stouch.point = pos_event.point;
			stouch.finger = event.touch.finger;
			break;
		case sf::Event::TouchMoved:
			if (!pos_event.isActive) {
				pos_event.point.x = event.touch.x;
				pos_event.point.y = event.touch.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			stouch.point = pos_event.point;
			stouch.finger = event.touch.finger;
			break;
		case sf::Event::TouchEnded:
			if (!pos_event.isActive) {
				pos_event.point.x = event.touch.x;
				pos_event.point.y = event.touch.y;
				pos_event.isActive = true;
			}
			pos_event.point = transform.transformPoint(pos_event.point);
			stouch.point = pos_event.point;
			stouch.finger = event.touch.finger;
			break;
		}

		for (auto ch : m_children) {
			if (ch->delegateEvent(event, pos_event)) {
				return true;
			}
		}


		switch (event.type) {
		case sf::Event::MouseWheelScrolled:
			catched = mouseWheelScrolled(w_scrolled);

			break;
		case sf::Event::MouseButtonPressed:

			catched = mousePressed(mtouch);

			break;
		case sf::Event::MouseButtonReleased:
		
			catched = mouseReleased(mtouch);

			break;
		case sf::Event::MouseMoved:
		
			catched = mouseMoved(move);

			break;
		case sf::Event::TouchBegan:
		
			catched = touchBegan(stouch);

			break;
		case sf::Event::TouchMoved:
		
			catched = touchMoved(stouch);

			break;
		case sf::Event::TouchEnded:

			catched = touchEnded(stouch);

			break;
		}

		if (catched || onEvent(event)) return true;

		return false;
	
	}

	void Node::updateChildrenParams() {

	}


	/*void Node::addCallBackGroup(std::string callback_group) {
		m_callbacks[callback_group];
	}

	void Node::removeCallBackGroup(std::string callback_groupe) {
		m_callbacks.erase(callback_groupe);
	}

	void Node::bind(std::string callback_group, callback call_back , void* args , void* obj){
		m_callbacks[callback_group][call_back] = (std::make_pair(args, obj));
	}

	void Node::unbind(std::string callback_group, callback call_back) {
		if(m_callbacks.find(callback_group) == m_callbacks.end()) return;
		m_callbacks[callback_group].erase(call_back);
	}

	void Node::setCallBackArgs(std::string callback_group, callback call_back, void* args) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		if (m_callbacks[callback_group].find(call_back) == m_callbacks[callback_group].end()) return;
		m_callbacks[callback_group][call_back].first = args;
	}

	void Node::executeCallbacks(std::string callback_group) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		for (auto func : m_callbacks[callback_group]) func.first(func.second.first , func.second.first);
	}

	void Node::executeCallBack(std::string callback_group, callback call_back) {
		if (m_callbacks.find(callback_group) == m_callbacks.end()) return;
		if (m_callbacks[callback_group].find(call_back) == m_callbacks[callback_group].end()) return;
		std::pair<void*, void*>& params = m_callbacks[callback_group][call_back];
		call_back(params.first, params.second);
	}*/



	Node::~Node()
	{
	}
}