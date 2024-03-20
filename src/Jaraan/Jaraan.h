#ifndef JARAAN_H
#define JARAAN_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <iostream>


static std::vector<sf::RectangleShape> widgets;
static std::vector<sf::Text> labels;
static bool isSelecting;
static bool rightClick;
class Window {

public:
	sf::RenderWindow window;
	Window(unsigned int width, unsigned int height, std::string windowTitle);
	void Update();

	
};

class Button {
	
	public: 
		sf::RectangleShape button;
		sf::Text label;
		bool selected;
		Button(int posx, int posy, std::string label , int fontSize );
		bool isSelected();
		void onClick(void method());
		
};


class InputSystem {



};

#endif // !