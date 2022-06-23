#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rigidbody.h"
#include "Vector2D.h"
#include "RectCollider.h"

using namespace sf;
using namespace std;

class Player
{
	private:
	Sprite playerSprite;
	Texture texture;
	Vector2D position;
	Vector2D size;
	RenderWindow renderWindow;

	public:
	float playerSpeed = 20;
	Rigidbody* rigidbody;
	Player(float startPosX, float startPosY);
	RectCollider getPosition();
	void SetTexture();
	Sprite& getShape();
	void moveLeft(float dt);
	void moveRight(float dt);
	void update(float dt);
};

