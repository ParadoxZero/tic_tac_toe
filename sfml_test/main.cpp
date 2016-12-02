#include <SFML/Graphics.hpp>
/*
int main()
{
	sf::RenderWindow window;
	window.setFramerateLimit(60);
	window.create(sf::VideoMode(800, 600), "SFML works!", sf::Style::Close);
	sf::RectangleShape shape(sf::Vector2f(50,50));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(0, 0);
	sf::Font font;
	if (!font.loadFromFile("sansation.ttf")) {
		exit(0);
	}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(window.getSize().y/10);
	text.setString("Hello");
	text.setPosition(50, 50);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.draw(text);
		window.display();
	}

	return 0;
}*/