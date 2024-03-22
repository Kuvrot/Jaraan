#ifndef JARAAN_H
#define JARAAN_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <iostream>
#include <functional>


static std::vector<sf::RectangleShape> widgets;
static std::vector<sf::Text> labels;
static bool isSelecting;
static bool mousePressed;
static sf::RectangleShape currentSelection;
static sf::Color idleColor = sf::Color(100, 30, 36);
static sf::Color hoverColor = sf::Color(43, 13, 15);

class Window {

public:
	sf::RenderWindow window;
	Window(unsigned int width, unsigned int height, std::string windowTitle);
	void Update();
	void setCursor(std::string cursor);

	
};

class Button{
	
	public: 
		sf::RectangleShape button;
		sf::Text label;
		std::function<void()> func = nullptr;
		Button(int posx, int posy, std::string label, int fontSize , std::function<void()> callMethod);
		void click();
		void setColor(int r , int g, int b);
		void setColorHover(int r , int g, int b);
		void destroy();
};

static std::vector<Button> buttons;


class Label {
public:
	sf::Text label;
	Label(int posx, int posy, std::string label , unsigned int fontSize);
	void setText(std::string label);


};


#endif // !