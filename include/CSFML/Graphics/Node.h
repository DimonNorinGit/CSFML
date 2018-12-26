#pragma once






#ifndef CSFML_NODE
#define CSFML_NODE

#include"SFML/Graphics/Transformable.hpp"
#include"SFML/Window/Event.hpp"
#include"SFML/Graphics/RenderTarget.hpp"

#include<set>
#include<map>
#include<functional>


namespace csf {

	typedef void(*callback)(void* , void*);

	struct positionEvent {
		sf::Vector2f point;
		bool isActive;
	};

	struct mouseTouch
	{
		sf::Mouse::Button button; ///< Code of the button that has been pressed
		sf::Vector2f point;
	};


	struct sensorTouch
	{
		unsigned int finger; ///< Index of the finger in case of multi-touch events
		sf::Vector2f point;
	};


	struct wheelScrolled
	{
		sf::Mouse::Wheel wheel; ///< Which wheel (for mice with multiple ones)
		float        delta; ///< Wheel offset (positive is up/left, negative is down/right). High-precision mice may use non-integral offsets.
		sf::Vector2f point;
	};


	struct mouseMove
	{
		sf::Vector2f point;
	};



	////////////////////////////////////////////////////////////
	///	/brief transformable representation of scene node
	////////////////////////////////////////////////////////////
	class Node : public sf::Transformable
	{
	public:

		////////////////////////////////////////////////////////////
		/// /brief make node with empty hierarchy
		////////////////////////////////////////////////////////////
		Node();

		////////////////////////////////////////////////////////////
		/// /brief pointers to children do not copy to m_children
		////////////////////////////////////////////////////////////
		Node(const Node& node);

		////////////////////////////////////////////////////////////
		/// /brief pointers to children do not copy to m_children
		////////////////////////////////////////////////////////////
		Node& operator=(const Node& node);
		
		////////////////////////////////////////////////////////////
		/// /brief add node as a child
		////////////////////////////////////////////////////////////
		void addNode(Node* node);

		////////////////////////////////////////////////////////////
		/// /brief remove node by pointer
		////////////////////////////////////////////////////////////
		void removeNode(const Node* node);





		void bind(std::string callback_group, callback call_back , void* args = nullptr , void* obj = nullptr);

		void unbind(std::string callback_group, callback call_back);

		void setCallBackArgs(std::string callback_group, callback call_back, void* args);

		void executeCallbacks(std::string callback_group);

		void executeCallBack(std::string callback_group, callback call_back);

		////////////////////////////////////////////////////////////
		/// /brief
		/// this method manage standart sfml events and passes it through the hierarchy
		/// and call functions to own node: mousePressed , mouseReleased , mouseMoved
		/// touchBegan , touchEnded , touchMoved
		////////////////////////////////////////////////////////////
		void delegateEvent(sf::Event event , positionEvent pos_event);		

		virtual ~Node();

	protected:
		////////////////////////////////////////////////////////////
		/// /brief  you have to ovveride this method in derived class
		///			you can manage event in this function as you want
		/// /return 1) true  , if you want to stop event spread
		///			2) false , if you want to pass event further by hierarchy
		////////////////////////////////////////////////////////////
		virtual bool onEvent(sf::Event event) = 0;



		////////////////////////////////////////////////////////////
		/// /brief  you have to ovveride this method in derived class
		///			all classes which ovveride this event can be drawed on the RenderTarget
		///			this method is called in draw() below for all nodes	
		////////////////////////////////////////////////////////////
		virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		////////////////////////////////////////////////////////////
		///	/brief  go down through the hierarchy and call onDraw
		///			than call draw for all childrens
		////////////////////////////////////////////////////////////
		void draw(sf::RenderTarget& target, sf::RenderStates parentStates) const;

		//it will be called if sf::Event::wheelScrooledEvent
		virtual bool mouseWheelScrolled(wheelScrolled w_scrolled) { return false; };

		//it will be called if sf::Event::MouseButtonPressed:
		virtual bool mousePressed(mouseTouch touch) { return false; };

		//it will be called if sf::Event::MouseButtonReleased
		virtual bool mouseReleased(mouseTouch touch) { return false; };

		//it will be called if sf::Event::MouseMoved
		virtual bool mouseMoved(mouseMove move) { return false; };

		//it will be called if sf::Event::TouchBegan
		virtual bool touchBegan(sensorTouch touch) { return false; };

		//it will be called if sf::Event::TouchMoved
		virtual bool touchEnded(sensorTouch touch) { return false; };

		//it will be called if sf::Event::TouchEnded
		virtual bool touchMoved(sensorTouch touch) { return false; };


	private:
		std::set<Node*> m_children; //< Node childrens in hierarchy
		std::map<std::string, std::map<callback , std::pair<void*,void*>>> m_callbacks;
	};

}

#endif