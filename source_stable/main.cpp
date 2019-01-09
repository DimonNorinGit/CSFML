
/*class CButton : public csf::Button {

	virtual bool mousePressed(csf::mouseTouch touch) {
		if (collidePoint(touch.point)) {
			std::cout << touch.point.x << " " << touch.point.y << "\n";
			Button::setBackgroundColor(sf::Color::Red);
			executeCallbacks("work");
		}
		return true;
	}

	virtual bool mouseReleased(csf::mouseTouch touch) {
		if (collidePoint(touch.point)) {
			std::cout << touch.point.x << " " << touch.point.y << "\n";
			Button::setBackgroundColor(sf::Color::Green);
		}
		return true;
	}
public:
	void start(int d) {
		std::cout << "WORdf" << d << std::endl;
	}

	static void oncall(void* args, void* obj) {
		static_cast<CButton*>(obj)->start(*(int*)args);
	}


};*/








//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!std::move





#include<iostream>

#include"Application.h"
#include"csfmlfunctionsh.h"
#include"SuperEllipse.h"
#include"Button.h"
#include"Animation.h"

#include"SpriteNode.h"
#include"TransformScript.h"
#include"TranslateAction.h"


using csf::Button;
using csf::Screen;

void foo(void* a, void* b) {
	std::cout << "AAAA";
}

void foo2(void* a, void* b) {
	std::cout << "j]keee";
}



class PlayBut : public csf::Button {


protected:
	virtual bool mousePressed(csf::mouseTouch touch) {
		if (collidePoint(touch.point)) {
			executeCallbacks("mouse_pressed");
			return true;
		}
	}

};

#include"RotateAction.h"
#include"ScaleAction.h"
#include"ActionGroup.h"
#include"ActionScript.h"

class RoboQuest : public csf::Application
{

public:

	RoboQuest() {

	}

protected:


	virtual void onStart() {
		unsigned int window_x = 800, window_y = 800;
		sf::ContextSettings cont;
		create(sf::VideoMode(window_x, window_y), "Title" , sf::Style::Default);
		//setFramerateLimit(60);


		sf::Font* f_amatic = new sf::Font();
		f_amatic->loadFromFile("tiles/AmaticR.ttf");
		sf::Texture* tex = new sf::Texture();
		tex->loadFromFile("tiles/robotis_st.jpg");


		rob.setTexture(*tex);
		/*animr = new csf::Animation(rob);
		animr->addFrame(csf::Frame({ {0 , 0 , 50 , 50} , 1 }));
		animr->addFrame(csf::Frame({ {50 , 0 , 50 , 50} , 1 }));
		animr->addFrame(csf::Frame({ {0 , 50 , 50 , 50} , 1 }));
		animr->addFrame(csf::Frame({ {50 , 50 , 50 , 50} , 1 }));*/
		rob.setTextureRect({0 , 0 , 50 , 50});

		rob.setOrigin(25, 25);
		rob.setPosition(50, 50);

		csf::TranslateAction* m = new csf::TranslateAction(rob, {100,100} , 2);
		csf::RotateAction* r = new csf::RotateAction(rob, 90, 2);
		csf::ScaleAction* s = new csf::ScaleAction(rob, 2, 2);
		csf::Animation* a = new csf::Animation(rob);
		a->addFrame({ {0,0 , 50 , 50} , 0.2 });
		a->addFrame({{ 50,0,50,50 }, 0.2});

		csf::ActionGroup* gr = new csf::ActionGroup({m , a});

		scr.append({s , r , gr});

	}

	virtual void onEvent(sf::Event mainEvent) {
		if (mainEvent.type == sf::Event::Closed) {
			close();
		}
	}

	virtual void onRun() {
		//animr->update(getElapsedTime().asSeconds());
		float elp = getElapsedTime().asSeconds();
		scr.update(elp);
	}

	virtual void onDraw() {
		clear();
		draw(rob);
		display();
	}

	virtual void onEnd() {
	
	}

private:
	sf::Sprite rob;
	csf::ActionScript scr;
};



void fo(sf::Transformable& tr) {

}





#include"AnimationCurve.h"
#include <initializer_list>



class A {

public:
	virtual void res() {
		std::cout << "Hello";
	}


	virtual void call() {
		res();
	}
};

class BA : public A
{

public:
	virtual void res() {
		std::cout << "AAAAAa";
	}
};


#include"BlockAlloc.h"

template <class T>
class Ar : public BlockAlloc<Ar<T>>
{
public:
	int a;
};


class An {
public:
	int a;
};






int main(){
	RoboQuest rb;
	rb.run();

	sf::Clock clk;
	const int size = 1000;
	Ar<int>* br[size];
	clk.restart();
	for (int i = 0; i < size; ++i) {
		br[i] = new Ar<int>;
	}

	std::cout << clk.getElapsedTime().asSeconds() << "\n";


	clk.restart();
	for (int i = 0; i < size; ++i) {
		br[i]->a = 0;
	}

	std::cout << "set " << clk.getElapsedTime().asMicroseconds() << "\n";




	sf::Clock clk1;
	An* bl[size];
	clk1.restart();
	for (int i = 0; i < size; ++i) {
		 bl[i] = new An;
	}
	std::cout << clk1.getElapsedTime().asSeconds() << "\n";

	clk1.restart();
	for (int i = 0; i < size; ++i) {
		bl[i]->a = 0;
	}
	std::cout << "set " << clk1.getElapsedTime().asMicroseconds() << "\n";
	
	
	system("pause");
	
	return 0;
}


/*std::srand(time(0));
	sf::ContextSettings con;
	con.antialiasingLevel = 10;
	sf::RenderWindow w(sf::VideoMode(500, 500), "Title" , sf::Style::Default ,  con);


	sf::Font f;
	f.loadFromFile("tiles/AmaticR.ttf");


	while (w.isOpen()) {

		sf::Event ev;

		while (w.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {

				w.close();
			}
		}

		w.clear();
		w.display();

	}*/