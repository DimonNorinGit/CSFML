
#include "Node.h"


namespace csf {

	Node::Node()
	{

	}


	Node::Node(const Node& node)
	{

	}

	Node& Node::operator=(const Node& node)
	{
		return *this;
	}

	void Node::draw(sf::RenderTarget& target, sf::RenderStates parentStates) const
	{
		// combine the parent transform with the node's one
		parentStates.transform *= getTransform();
		// let the node draw itself
		onDraw(target, parentStates);

		// draw its children
		for (auto ch : m_children)
			ch->draw(target, parentStates);
	}




	void Node::delegateEvent(sf::Event event , positionEvent pos_event) {

		bool catched = onEvent(event);

		if (catched) return;

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
				catched = mouseWheelScrolled(w_scrolled);
				
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
				catched = mousePressed(mtouch);
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
				catched = mouseReleased(mtouch);
				break;
			case sf::Event::MouseMoved:
				if (!pos_event.isActive) {
					pos_event.point.x = event.mouseMove.x;
					pos_event.point.y = event.mouseMove.y;
					pos_event.isActive = true;
				}
				pos_event.point = transform.transformPoint(pos_event.point);
				move.point = pos_event.point;
				catched = mouseMoved(move);		
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
				catched = touchBegan(stouch);
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
				catched = touchMoved(stouch);
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
				catched = touchEnded(stouch);
				break;
		}
		
			
			if (catched) return;
			for(auto ch : m_children)
				ch->delegateEvent(event, pos_event);

		}

	/*bool Node::mouseWheelScrolled(wheelScrolled w_scrolled) {
		return false;
	}

	bool Node::mousePressed(mouseTouch touch) {
		return false;
	}

	bool Node::mouseReleased(mouseTouch touch) {
		return false;
	}

	bool Node::mouseMoved(mouseMove move) {
		return false;
	}

	bool Node::touchBegan(sensorTouch touch) {
		return false;
	}

	bool Node::touchEnded(sensorTouch touch) {
		return false;
	}

	bool Node::touchMoved(sensorTouch touch) {
		return false;
	}*/

	void Node::bind(std::string callback_group, callback call_back , void* args , void* obj){
		m_callbacks[callback_group][call_back] = (std::make_pair(args, obj));
	}

	void Node::unbind(std::string callback_group, callback call_back) {
		m_callbacks[callback_group].erase(call_back);
	}
	void Node::setCallBackArgs(std::string callback_group, callback call_back, void* args) {
		m_callbacks[callback_group][call_back].first = args;
	}
	void Node::executeCallbacks(std::string callback_group) {
		for (auto func : m_callbacks[callback_group]) func.first(func.second.first , func.second.first);
	}

	void Node::executeCallBack(std::string callback_group, callback call_back) {
		std::pair<void*, void*>& params = m_callbacks[callback_group][call_back];
		call_back(params.first, params.second);
	}
	
	void Node::removeNode(const Node* node) {
		m_children.erase(std::find(m_children.cbegin(), m_children.cend(), node));
	}

	void Node::addNode(Node* node)
	{
		m_children.emplace(node);
	}

	Node::~Node()
	{
	}
}