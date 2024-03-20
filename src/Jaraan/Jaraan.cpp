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

		// set the string to display
		this->label.setString(label);

		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!

		// set the color
		this->label.setFillColor(sf::Color(236, 219, 186));
		

		int xSize = label.size() * this->label.getCharacterSize();
		button.setSize(sf::Vector2f(xSize, this->label.getCharacterSize() * 2));
		
		int temp = 0;

		button.setPosition(posx * 32 , button.getSize().y + 32 * posy);
		
		
		widgets.push_back(button);
		this->button = button;
		this->label.setPosition(button.getPosition().x + button.getSize().x/4, button.getPosition().y + button.getSize().y / 4);
		labels.push_back(this->label);
		
		
	}
