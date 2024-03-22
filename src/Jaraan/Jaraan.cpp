#include "Jaraan.h"

	Window::Window(unsigned int width, unsigned int height, std::string windowTitle) {
		sf::Image icon;
		icon.loadFromFile("../../../../owl.jpg");
		this->window.create(sf::VideoMode(width, height), windowTitle);
		this->window.setIcon(icon.getSize().x , icon.getSize().y , icon.getPixelsPtr());
		window.setFramerateLimit(60);
		setCursor("arrow");
	}

	void Window::Update() {
		
		while (window.isOpen())
		{
			for (auto event = sf::Event{}; window.pollEvent(event);)
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

				if (event.type == sf::Event::MouseButtonPressed) {
					
					if (event.key.code == sf::Mouse::Left) {

						if (isSelecting) {
							mousePressed = true;
						}
					}
				}
			}
			
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			window.clear(sf::Color(25, 25, 25));
			isSelecting = false;
			setCursor("arrow");
			//Draw widgets
			for (int i = 0; i < widgets.size(); i++) {

				window.draw(widgets[i]);
				widgets[i].setFillColor(idleColor);
				if (widgets[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					isSelecting = true;
					widgets[i].setFillColor(hoverColor);
					setCursor("hand");

					if (mousePressed) {
						 currentSelection = widgets[i];
						 //Clicking 
						 for (int i = 0; i < buttons.size(); i++) {

							 //If the positions match, then it's the same object
							 if (buttons[i].button.getPosition() == currentSelection.getPosition()) {
								 buttons[i].click();
								 break;
							 }

						 }
						 mousePressed = false;
					}
				}
			}
			
			for (int i = 0; i < labels.size(); i++) {

				sf::Font font;

				if (!font.loadFromFile("arial.ttf"))
				{
					throw("Font not founded");
				}

				labels[i].setFont(font);

				window.draw(labels[i]);
			}

			window.display();
		}

	}

	void Window::setCursor(std::string cursor) {

		if (cursor == "arrow") {
			sf::Cursor cursor;
			cursor.loadFromSystem(sf::Cursor::Arrow);
			window.setMouseCursor(cursor);
		}
		else if (cursor == "hand") {

			sf::Cursor cursor;
			cursor.loadFromSystem(sf::Cursor::Hand);
			window.setMouseCursor(cursor);
		}

	}

	Button::Button(int posx, int posy , std::string label, int fontSize , std::function<void()> callMethod) {
		this->func = callMethod;
		sf::RectangleShape button(sf::Vector2f(123,50));
		button.setFillColor(sf::Color (100,30,36));

		// set the string to display
		this->label.setString(label);

		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!

		// set the color
		this->label.setFillColor(sf::Color(233, 220, 188));
		
		int xSize = label.size() * this->label.getCharacterSize();
		button.setSize(sf::Vector2f(xSize, this->label.getCharacterSize() * 2));
		button.setPosition(posx * 32 , button.getSize().y + 32 * posy);

	
		this->button = button;
		widgets.push_back(this->button);
		this->label.setPosition(button.getPosition().x + button.getSize().x/4, button.getPosition().y + button.getSize().y / 4);
		labels.push_back(this->label);
		buttons.push_back(*this);
	}

	void Button::click() {

		if (func == nullptr) {
			std::cout << "Error: onClick function not set\n";
			return;
		}

		func();
	}

	void Button::setColor(int r, int g, int b) {

		idleColor = sf::Color(r, g, b);

	}
	void Button::setColorHover(int r, int g, int b) {

		hoverColor = sf::Color(r, g, b);
	}


	void Button::destroy () {

		for (int i = 0; i < widgets.size(); i++) {

			if (widgets[i].getPosition() == this->button.getPosition()) {
				widgets.erase(widgets.begin() + i);
				std::cout << i;
				break;
			}
		}
	}



	Label::Label(int posx, int posy, std::string label, unsigned int fontSize) {

		// set the string to display
		this->label.setString(label);

		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!

		// set the color
		this->label.setFillColor(sf::Color(233, 220, 188));
		this->label.setPosition(posx * 32, 32 * posy);
		labels.push_back(this->label);
	}

	void Label::setText(std::string label) {

		for (int i = 0; i < widgets.size(); i++) {

			if (labels[i].getPosition() == this->label.getPosition()) {
				labels[i].setString(label);
				break;
			}
		}
	}

	


