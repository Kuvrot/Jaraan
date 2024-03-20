#include "Jaraan.h"

	Window::Window(unsigned int width, unsigned int height, std::string windowTitle) {
		sf::Image icon;
		icon.loadFromFile("../../../../owl.jpg");
		this->window.create(sf::VideoMode(width, height), windowTitle);
		this->window.setIcon(icon.getSize().x , icon.getSize().y , icon.getPixelsPtr());
		window.setFramerateLimit(144);
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
			}

			window.clear(sf::Color(25, 25, 25));

			//Draw widgets
			for (int i = 0; i < widgets.size(); i++) {

				window.draw(widgets[i]);

			}

			for (int i = 0; i < labels.size(); i++) {


				sf::Font font;

				if (!font.loadFromFile("arial.ttf"))
				{
					printf("Error bonito :)");
				}

				labels[i].setFont(font);

				window.draw(labels[i]);

			}

			window.display();
		}

	}

	Button::Button(int posx, int posy , std::string label, int fontSize) {
		sf::RectangleShape button(sf::Vector2f(123,50));
		button.setFillColor(sf::Color (44,66,99));
		
		button.setPosition(posx, posy);
		
		this->button = button;

		// set the string to display
		this->label.setString(label);

		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!

		// set the color
		this->label.setFillColor(sf::Color(236, 219, 186));
		this->label.setPosition(button.getPosition().x + 32, button.getPosition().y);
		labels.push_back(this->label);

		int xSize = label.size() * this->label.getCharacterSize();
		button.setSize(sf::Vector2f(xSize - xSize/label.size(), this->label.getCharacterSize() * 2));
		widgets.push_back(button);
		
		
	}
