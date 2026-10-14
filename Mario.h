#pragma once
#include"IncludeLibs.h"

class Mario {
private:
	
	unsigned int currentAnimation ;
	float accumulatedTime ;
	float jumpedFrom;
	float jumpLimite ;

	bool _isjumping;
	bool _isFalling;
	bool _jumped;
	bool _dying;

	float x;
	float y;

	std::unordered_multimap<char, unsigned int > _state;
	// 0 1 default ./ 2 3 moving R ./ 4 5 moving L ./ 6 dying

	std::vector <sf::Texture> _playerStateTexture;
	//Each index pointing to player state value and vector texture value

	std::unique_ptr <sf::Sprite> marioSprite;

public:
	Mario();

	void setState(unsigned int curentAnimation);


	sf::Vector2f getPose();

	void setPos(float x , float y);

	void Draw(sf::RenderWindow &window);

	void Update(char direction, float dt, float _pixelPerdt);

	void setJumpingState();

	void jump(float _pixelPer_dt);

	void g(float pixelPer_dt);

	void dyingAnimation();

	void setDying();
};

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_ICON    "assets/textures/Icon.png"
#define MARIO_ASSETS "assets/textures/Mario"
