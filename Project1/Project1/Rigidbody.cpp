#include "Rigidbody.h"
#include <SFML/Graphics.hpp>

using namespace sf;

float Rigidbody::CalculateFriction(float mass)
{
    float frictionCoefficient = 0.80f;      //kinetische coefficient voor rubber on concrete
    float gravity = 9.81f;
    return mass * gravity * frictionCoefficient;
}

float Rigidbody::CalculateAcceleration(float currentVelocity, float mass, float force)
{
    float forceNeededToMove = CalculateFriction(mass);
    return (force - forceNeededToMove * currentVelocity)/mass;
}

float Rigidbody::CalculateVelocity(float currentVelocity, float mass, float force, float dt)
{
    float acceleration = CalculateAcceleration(currentVelocity, mass, force);
    return currentVelocity + acceleration * dt; //*tijd
}

float Rigidbody::AddForce(float axis, float force)
{
    axis += force;
    return axis;
}
