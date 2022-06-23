#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2D.h"
#include "RectCollider.h"

using namespace sf;

class Car
{
    private:
    Sprite carSprite;
    Texture texture;
    Rigidbody* rigidbody;
    Vector2D size;

    public:
    float dir;
    Vector2D position;
    Car(float force);
    RectCollider getPosition();
    Sprite& getShape();
    void SetTexture();
    void hitBottom();
    void update(float dt);
    float randomizeStartPos();
    String randomizeTexture();
    float randomizeDir();
};

