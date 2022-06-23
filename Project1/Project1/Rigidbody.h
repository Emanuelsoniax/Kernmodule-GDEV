#pragma once

class Rigidbody
{
	public:
	float mass = 1;
	float forwardsForce = 0;
	float sidewaysForce = 0;
	float yVelocity = 0;
	float xVelocity = 0;
	float CalculateFriction(float mass);
	float CalculateAcceleration(float currentVelocity, float mass, float force);
	float CalculateVelocity(float currentVelocity, float mass, float force, float dt);
	float AddForce(float axis, float force);
};


