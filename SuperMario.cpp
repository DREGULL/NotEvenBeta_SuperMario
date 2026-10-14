#include"IncludeLibs.h"

int main() {
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH,WINDOW_HEIGHT }), "SuperMario");
	sf::Image icon(GAME_ICON);
	window.setIcon(icon);

	unsigned int FPS = 60;
	window.setFramerateLimit(FPS);
	Mario mario;
	mario.setPos(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2 )- 100);

	float dt = 1.f / FPS;
	float gameSpeed = 1.f;
	
	float _pixelPer_dt = 300.f * dt *gameSpeed;

	while (window.isOpen()) {

		while (std::optional<sf::Event> event = window.pollEvent()) {

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			if (const auto* keyRel = event->getIf<sf::Event::KeyReleased>())
			{
				if (keyRel->code == sf::Keyboard::Key::D) {
					mario.setState(0);
				}
				if (keyRel->code == sf::Keyboard::Key::A) {
					mario.setState(1);
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			mario.Update('r',dt,_pixelPer_dt);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			mario.Update('l', dt,_pixelPer_dt);
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			//SetGameSpeed(gameSpeed, _pixelPer_dt, dt);
			//When the "cin" works (inside the function), it will stop all the main loop ,so it's bad fn "and i'm so tired i won't fix that :) " , and the default speed as you know is x1
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			mario.setJumpingState();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl))
		{
			mario.setDying();
		}
		mario.dyingAnimation();
		mario.jump(_pixelPer_dt);
		mario.g(_pixelPer_dt);



		


		window.clear(sf::Color(0, 255, 255));
		mario.Draw(window);
		window.display();
	}
}