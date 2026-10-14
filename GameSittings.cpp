#include "GameSittings.h"
#include <SFML/Graphics.hpp>

void SetGameSpeed(float& gameSpeed, float& reset_dt,float dt){

	ST: std::cin >> gameSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		return;
	}
	if (gameSpeed > 2 || gameSpeed < 1) { 

		std::cout << "Renter a value between 1 and 2\n";
		goto ST;
	}
	else
	{
		reset_dt = 300.f * dt * gameSpeed;
	}

}