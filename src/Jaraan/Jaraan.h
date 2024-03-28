#ifndef JARAAN_H
#define JARAAN_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <iostream>
#include <functional>

static std::vector<sf::Text> labels;
static bool isSelecting;
static bool mousePressed;
static sf::RectangleShape currentSelection;
static std::string input;

class Window {

public:
	sf::RenderWindow window;
	sf::Color backgroundColor = sf::Color(25, 25, 25);
	Window(unsigned int width, unsigned int height, std::string windowTitle);
	void Update();
	void setCursor(std::string cursor);
	void setBackgroundColor(int r, int g, int b);

};

class Button{
	
	public: 
		sf::RectangleShape button;
		sf::Text label;
		std::function<void()> func = nullptr;
		sf::Color idleColor = sf::Color(100, 30, 36);
		sf::Color hoverColor = sf::Color(43, 13, 15);
		sf::Color labelColor = sf::Color(100, 30, 36);
		Button(int posx, int posy, std::string label, int fontSize , std::function<void()> callMethod);
		void setButtonColor(int r , int g, int b);
		void setButtonColorHover(int r , int g, int b);
		void setLabelColor(int r , int g, int b);
		void click();
		void destroy();
};

static std::vector<Button> buttons;

class InputField {

public:
	sf::RectangleShape field;
	sf::Text label;
	std::function<void()> func = nullptr;
	sf::Color idleColor = sf::Color(100, 30, 36);
	sf::Color labelColor = sf::Color(100, 30, 36);
	InputField(int posx, int posy, int width, int fontSize, std::function<void()> callMethod);
	void setLabelColor(int r, int g, int b);
	void getText();
	void destroy();
};

static std::vector<InputField> inputFields;

class Label {
public:
	sf::Text label;
	Label(int posx, int posy, std::string label , unsigned int fontSize);
	void setText(std::string label);
};


#endif // !