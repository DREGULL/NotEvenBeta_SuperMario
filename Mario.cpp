#include "IncludeLibs.h"

Mario::Mario() {

	this->accumulatedTime = 0.f;
	this->currentAnimation = 2 ;

	this->x = WINDOW_WIDTH / 2;
	this->y = WINDOW_HEIGHT / 2;
	this->jumpedFrom = this->y;
	this->jumpLimite = y - 70.f;

	this->_isjumping = false;
	this->_isFalling = true;
	this->_jumped = false;
	this->_dying = false;

	_playerStateTexture.resize(7);
	this->_state = { {'d',0} , {'d',1},{'r',2},{'r',3},{ 'l',4},{ 'l',5},{ 'y',6  } };
	for (const auto& [letter, index] : _state) {
		std::string path = std::string(MARIO_ASSETS) + std::to_string(index) + ".png";

		if (!_playerStateTexture[index].loadFromFile(path)) {
			std::cerr << "Failed to load: " << path << "\n";
		}
	}

	this->marioSprite = std::make_unique<sf::Sprite>(_playerStateTexture[0]);
	
}

void Mario::setState(unsigned int curentAnimation) {

	this->marioSprite->setTexture(_playerStateTexture[curentAnimation]);
}

void Mario::setPos(float x, float y) {
	marioSprite->setPosition({ this->x,this->y });
}

sf::Vector2f Mario::getPose() {
	return { this->x,this->y };
}

void Mario::Draw(sf::RenderWindow &window) {
	window.draw(*Mario::marioSprite);
}


void Mario::Update(char direction, float dt,float _pixelPerdt) {

	if (direction == 'r')
	{
		this->x += _pixelPerdt;
		this->accumulatedTime += dt;
		if (accumulatedTime >= 0.145)
		{
			this->currentAnimation = (currentAnimation == 2) ? 3 : 2;
			this->accumulatedTime = 0.f;
		}
		setPos(this->x, this->y);
		setState(currentAnimation);
	}
	if (direction == 'l')
	{
		this->x -= _pixelPerdt;
		this->accumulatedTime += dt;
		if (accumulatedTime >= 0.145)
		{
			this->currentAnimation = (currentAnimation == 4) ? 5 : 4;
			this->accumulatedTime = 0.f;
		}
		setPos(this->x, this->y);
		setState(currentAnimation);
	}
	
}

void Mario::jump(float _pixelPer_dt) {

	if (_isjumping && !_isFalling)
	{
		if (this->y > jumpLimite)
		{
			_jumped = (!_isFalling)? true : false;
			this->y -= _pixelPer_dt ;
			setPos(x,y);
		}
		else
		{
			_isjumping = false;
			_isFalling = true;
		}
	}
}

void Mario::g(float pixelPer_dt){
	
	if (this->y < 360 && _isFalling)
	{
		this->y += pixelPer_dt ;
		setPos(x,y);
	}
	else if(_dying && this->y >= 360 )
	{
		this->_dying = false;
	}
	
}

void Mario::setJumpingState() {
	_isjumping = true;
	if (this->y >= 360) _isFalling = false ;
}
void Mario::setDying() {
	this->_dying = true;
}
void Mario::dyingAnimation() {
	if (this->_dying) {
		setJumpingState();
		this->currentAnimation = 6;
		setState(this->currentAnimation);
	}
}