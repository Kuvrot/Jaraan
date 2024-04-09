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
			auto event = sf::Event{};
			
			for (event; window.pollEvent(event);)
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

				if (event.type == sf::Event::KeyPressed) {

					if (event.key.code == sf::Keyboard::Return) {

						returnPressed = true;
					}
					else {
						returnPressed = false;
					}

					if (event.key.code == sf::Keyboard::BackSpace) {

						backSpacePressed = true;
					}
					else {
						backSpacePressed = false;
					}
				}
			}
			

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			window.clear(backgroundColor);

			if (!isSelecting) {
				setCursor("arrow");
			}

			isSelecting = false;

			//Draw widgets
			for (int i = 0; i < buttons.size(); i++) {
			
				window.draw(buttons[i].button);
				buttons[i].label.setColor(buttons[i].labelColor);
				buttons[i].button.setFillColor(buttons[i].idleColor);
				if (buttons[i].button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					isSelecting = true;
					buttons[i].button.setFillColor(buttons[i].hoverColor);
					setCursor("hand");

					if (mousePressed) {
						currentSelection = buttons[i].button;

						//Clicking 
						//If the positions match, then it's the same object
						if (buttons[i].button.getPosition() == currentSelection.getPosition()) {
							buttons[i].click();
						}
						
						mousePressed = false;
					}
				}
			}

			//Drawing the inputFields
			for (int i = 0; i < inputFields.size(); i++) {

				window.draw(inputFields[i].field);

				inputFields[i].label.setColor(inputFields[i].labelColor);
				inputFields[i].field.setFillColor(inputFields[i].idleColor);
				if (inputFields[i].field.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					isSelecting = true;
					inputFields[i].field.setFillColor(buttons[0].hoverColor);
					setCursor("text");

					if (mousePressed) {
						currentSelection = inputFields[i].field;
						mousePressed = false;
					}
				}

				//If the positions match, then it's the same object
				if (inputFields[i].field.getPosition() == currentSelection.getPosition()) {

					if (event.type == sf::Event::TextEntered) {
						// Handle text input
						if (event.text.unicode < 128) {

							if (!backSpacePressed) {

								if (inputFields[i].getText().size() < 17) {

									input += static_cast<char>(event.text.unicode);

								}
							}
							else {

								if (inputFields[i].getText().size() > 0) {

									input.pop_back();

								}
							}
						}
					}

					inputFields[i].setText(input);
				}
			}

			//Draw widgets
			for (int i = 0; i < checkBoxes.size(); i++) {

				window.draw(checkBoxes[i].box);
				checkBoxes[i].check.setColor(checkBoxes[i].labelColor);
				checkBoxes[i].box.setFillColor(checkBoxes[i].idleColor);
				if (checkBoxes[i].box.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					isSelecting = true;
					checkBoxes[i].box.setFillColor(checkBoxes[i].hoverColor);
					setCursor("hand");

					if (mousePressed) {
						currentSelection = checkBoxes[i].box;

						//Clicking 
						//If the positions match, then it's the same object
						if (checkBoxes[i].box.getPosition() == currentSelection.getPosition()) {
							checkBoxes[i].toggle();
						}

						mousePressed = false;
					}
				}
			}


			//Drawing all the labels
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

		sf::Cursor _cursor;

		if (cursor == "arrow") {
			_cursor.loadFromSystem(sf::Cursor::Arrow);
			window.setMouseCursor(_cursor);
		}
		else if (cursor == "hand") {
			_cursor.loadFromSystem(sf::Cursor::Hand);
			window.setMouseCursor(_cursor);
		}
		else if (cursor == "text") {
			_cursor.loadFromSystem(sf::Cursor::Text);
			window.setMouseCursor(_cursor);
		}
	}

	void Window::setBackgroundColor(int r, int g, int b) {

		this->backgroundColor = sf::Color(r, g, b);
	}

	Button::Button(int posx, int posy , std::string label, int fontSize , std::function<void()> callMethod) {

		this->func = callMethod;
		
		sf::RectangleShape button(sf::Vector2f(123,50));

		// set the string to display
		this->label.setString(label);

		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!
		
		int xSize = label.size() * this->label.getCharacterSize();
		button.setSize(sf::Vector2f(xSize, this->label.getCharacterSize() * 2));
		button.setPosition(posx * 32 , button.getSize().y + 32 * posy);

	
		this->button = button;
		this->label.setPosition(button.getPosition().x + button.getSize().x / 4, button.getPosition().y + button.getSize().y / 4);
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

	void Button::setButtonColor(int r, int g, int b) {

		this->idleColor = sf::Color(r, g, b);
	}

	void Button::setButtonColorHover(int r, int g, int b) {

		this->hoverColor = sf::Color(r, g, b);
	}

	void Button::setLabelColor(int r, int g, int b) {

		this->label.setColor(sf::Color(r, g, b));
	}


	void Button::destroy () {

		for (int i = 0; i < buttons.size(); i++) {

			if (buttons[i].button.getPosition() == this->button.getPosition()) {
				buttons.erase(buttons.begin() + i);
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
		this->label.setColor(sf::Color(233, 220, 188));
		this->label.setPosition(posx * 32, 32 * posy);
		labels.push_back(this->label);
	}

	void Label::setText(std::string label) {

		for (int i = 0; i < labels.size(); i++) {

			if (labels[i].getPosition() == this->label.getPosition()) {
				labels[i].setString(label);
				break;
			}
		}
	}


	InputField::InputField(int posx, int posy, int width, int fontSize, std::string placeholder) {

		sf::RectangleShape field(sf::Vector2f(123, 50));
		field.setOutlineColor(sf::Color(10, 10, 10));
		field.setOutlineThickness(2.5f);
		this->label.setString(placeholder);
		// set the character size
		this->label.setCharacterSize(fontSize); // in pixels, not points!

		int xSize = fontSize * width;
		field.setSize(sf::Vector2f(xSize, fontSize * 2));
		field.setPosition(posx * 32, field.getSize().y + 32 * posy);
		this->label.setColor(sf::Color(233, 220, 188));
		this->label.setPosition(field.getPosition().x + 10, field.getPosition().y + field.getSize().y / 4);
		this->field = field;
		labels.push_back(this->label);
		inputFields.push_back(*this);
	}


	void InputField::setText(std::string label) {

		for (int i = 0; i < labels.size(); i++) {

			if (labels[i].getPosition() == this->label.getPosition()) {
				labels[i].setString(label);
				break;
			}
		}
	}

	std::string InputField::getText() {

		std::string _string;

		for (int i = 0; i < labels.size(); i++) {

			if (labels[i].getPosition() == this->label.getPosition()) {
				_string = labels[i].getString();
				break;
			}
		}

		return _string; 
	}


	CheckBox::CheckBox(int posx, int posy, bool defaultValue, int size) {

		sf::RectangleShape field(sf::Vector2f(123, 50));
		field.setOutlineColor(sf::Color(10, 10, 10));
		field.setOutlineThickness(2.5f);
		this->value = defaultValue;
		if (defaultValue) {
			this->check.setString(" × ");
		}
		else {
			this->check.setString(" ");
		}
		// set the character size
		this->check.setCharacterSize(size * 2); // in pixels, not points!
		
		field.setSize(sf::Vector2f(size * 2, size * 2));
		field.setPosition(posx * 32, field.getSize().y + 32 * posy);
		this->check.setColor(sf::Color(233, 220, 188));
		this->check.setPosition(field.getPosition().x - 2, field.getPosition().y - 4);
		this->box = field;
		labels.push_back(this->check);
		checkBoxes.push_back(*this);

	}

	

	void CheckBox::toggle() {

		bool curValue = this->value;

		for (int i = 0; i < checkBoxes.size(); i++) {

			if (checkBoxes[i].box.getPosition() == this->box.getPosition()) {
				
				if (checkBoxes[i].value) {

					checkBoxes[i].value = false;
					curValue = false;

				}
				else {
					checkBoxes[i].value = true;
					curValue = true;
				}

				break;
			}
		}

		for (int i = 0; i < labels.size(); i++) {
		
			if (labels[i].getPosition() == this->check.getPosition()) {

				if (curValue) {

					labels[i].setString(" × ");
				}
				else {
					labels[i].setString(" ");
				}

				break;
			}
		
		}

	}

