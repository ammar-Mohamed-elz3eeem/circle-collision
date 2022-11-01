#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace std;

int main()
{
	sf::CircleShape cir1;
	sf::CircleShape cir2;

	cir1.setRadius(50);
	cir2.setRadius(20);

	cir1.setPosition(sf::Vector2f(20,20));
	cir2.setPosition(sf::Vector2f(300,300));

	cir1.setFillColor(sf::Color(0xffffff));
	cir2.setFillColor(sf::Color(0xaaaaaa));

	sf::Clock clock;
	sf::Vector2f speed(0,0);

	float dt;

	bool game_over = false;

	sf::RenderWindow app(sf::VideoMode(1024, 720), "Circle Collide");
	app.setFramerateLimit(60);
	sf::Event event;

	while(app.isOpen())
	{
		dt = clock.getElapsedTime().asSeconds();
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				app.close();
		}
		float dx = cir1.getPosition().x - cir2.getPosition().x;
		float dy = cir1.getPosition().y - cir2.getPosition().y;
		float dist = floor(sqrt(((dx * dx) + (dy * dy))));
		float totalRadSquared = sqrt((50 + 20) * (50 + 20));
		if(totalRadSquared > dist)
			game_over = true;

		cout << "Length of both two Radiuses: " << totalRadSquared << endl;
		cout << "Dist between two circles: " << dist << endl;

		app.clear();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			speed.y = -10;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			speed.x = 10 ;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			speed.y = 10;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			speed.x = -10;


		if(!game_over)
		{
			cir1.move(speed);
			speed.x = 0;
			speed.y = 0;
			app.draw(cir1);
			app.draw(cir2);
		}
		app.display();
	}
}

