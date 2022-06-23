#include "Car.h"
#include <iostream>

Car::Car(float force)
{
    rigidbody = new Rigidbody();
    rigidbody->forwardsForce = force;
    position.x = randomizeStartPos();
    position.y = -120;
    SetTexture();
    carSprite.setPosition(Vector2f(position.x, position.y));

    size = Vector2D(90, 120);
    dir = randomizeDir();
}

RectCollider Car::getPosition()
{
    return RectCollider(Vector2D(position), Vector2D(size));
}

Sprite& Car::getShape()
{
    return carSprite;
}

void Car::SetTexture()
{
    if (!texture.loadFromFile(randomizeTexture())) {
        std::cout << "Could not load texture" << std::endl;
        return;
    }
    carSprite.setTexture(texture);
}

void Car::hitBottom()
{
    position.y = 1;
}

void Car::update(float dt)
{
    position.y += rigidbody->CalculateVelocity(rigidbody->yVelocity, rigidbody->mass, rigidbody->forwardsForce, dt);
    carSprite.setPosition(Vector2f(position.x, position.y));

    //move car sideways
    //rigidbody->sidewaysForce = rigidbody->AddForce(rigidbody->sidewaysForce, 0.1f);
    position.x += rigidbody->CalculateVelocity(rigidbody->xVelocity, rigidbody->mass, 50, dt) * dir;
    if (position.x <= 190 || position.x >= 690) {
        dir = -dir;
    }
}

float Car::randomizeStartPos()
{
    std::vector<int> startPositions = {240,440,640};
    
    int startPos = rand() % 3;
    
    return startPositions[startPos];
}

String Car::randomizeTexture()
{
    std::vector<String>textures
    {"assets/Laag 5.png",
     "assets/Laag 4.png",
     "assets/Laag 7.png",
     "assets/Laag 8.png"};

    int carText = rand() % 4;
    
    return textures[carText];
}

float Car::randomizeDir() {
    std::vector<float>directions{ 1,-1 };
    float startDir = rand() % 2;
    return directions[startDir];
}
