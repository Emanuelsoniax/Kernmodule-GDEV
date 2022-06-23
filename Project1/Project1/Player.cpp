#include "Player.h"

Player::Player(float startPosX, float startPosY)
{
	rigidbody = new Rigidbody();
	SetTexture();

	rigidbody->forwardsForce = 10;
	rigidbody->sidewaysForce = 0;
	rigidbody->xVelocity = 0;
	rigidbody->yVelocity = 1;

	position = Vector2D(startPosX, startPosY);
	size = Vector2D(90, 120);

	playerSprite.setPosition(Vector2f(position.x, position.y));
}

RectCollider Player::getPosition()
{
	return RectCollider(Vector2D(position), Vector2D(size));
}

void Player::SetTexture() {
	
	if(!texture.loadFromFile("assets/Laag 2.png")) {
		cout << "Could not load texture" << endl;
		return;
	}
	playerSprite.setTexture(texture);
}

Sprite& Player::getShape()
{
	return playerSprite;
}

void Player::moveLeft(float dt)
{
	rigidbody->sidewaysForce = rigidbody->AddForce(rigidbody->sidewaysForce, -playerSpeed);
	
}

void Player::moveRight(float dt)
{
	rigidbody->sidewaysForce = rigidbody->AddForce(rigidbody->sidewaysForce, playerSpeed);
}

void Player::update(float dt)
{
	position.x += rigidbody->CalculateVelocity(rigidbody->xVelocity, rigidbody->mass, rigidbody->sidewaysForce, dt);
	playerSprite.setPosition(Vector2f(position.x, position.y));
	if (position.x <= 190) {
		position.x = 190;
	}

	if (position.x >= 690) {
		position.x = 690;
	}
}
